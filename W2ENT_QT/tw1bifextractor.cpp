#include "tw1bifextractor.h"
#include <iostream>

bool operator< (const ResourceId& a, const ResourceId& b)
{
    if (a._bifId != b._bifId)
        return a._bifId < b._bifId;

    return a._resourceId < b._resourceId;
}

TW1bifExtractor::TW1bifExtractor(QString file, QString folder): _file(file), _folder(folder)
{
    _fileTypes = getResourceTypeMap();
    _nbProgress = 0;
    _lastProgression = 0;
    _stopped = false;
}

void TW1bifExtractor::run()
{
    extractKeyBIF(_folder, _file);
}

void relativeSeek(QFile* buf, int value)
{
    buf->seek(buf->pos() + value);
}

QString TW1bifExtractor::getExtensionFromResourceType(unsigned short resourceType)
{
    QMap<unsigned short, QString>::iterator it = _fileTypes.find(resourceType);
    if (it == _fileTypes.end())
        return "";
    else
        return "." + it.value();
}

void TW1bifExtractor::extractKeyBIF(QString exportFolder, QString filename)
{
    QFile bifFile(filename);

    QFileInfo fileInf(bifFile);
    const QString baseFilename = fileInf.absoluteDir().absolutePath();
    const QString bifFolder = baseFilename + "/";

    if (!bifFile.open(QIODevice::ReadOnly))
    {
        emit error();
        return;
    }

    // magic word "BIFFV1.1"
    bifFile.seek(8);

    unsigned int nbFiles, nbKeys;
    unsigned int fileOffset, keysOffset;

    bifFile.read((char*)&nbFiles, 4);
    bifFile.read((char*)&nbKeys, 4);

    std::cout << "nbFiles = " << nbFiles << std::endl;

    relativeSeek(&bifFile, 4);

    bifFile.read((char*)&fileOffset, 4);
    bifFile.read((char*)&keysOffset, 4);


    std::cout << "keyTable" << std::endl;
    bifFile.seek(keysOffset);
    for (unsigned int i = 0; i < nbKeys; ++i)
    {
        int back1 = bifFile.pos();
        QString name = "";
        for (int n = 0; n < 16; ++n)
        {
            char c;
            bifFile.read(&c, 1);
            if (c == 0x00)
                break;
            else
                name.push_back(c);
        }
        bifFile.seek(back1 + 16);
        //std::cout << qname.toStdString().c_str() << std::endl;

        unsigned short resourceType;
        unsigned int resourceId, flags;
        bifFile.read((char*)&resourceType, 2);
        bifFile.read((char*)&resourceId, 4);
        bifFile.read((char*)&flags, 4);

        unsigned int bifId = ((flags & 0xFFF00000) >> 20);

        ResourceId rId(bifId, resourceId);

        //std::cout << "resourceId=" << resourceId << ", flags=" << flags << std::endl;
        _resources.insert(rId, name);
    }


    bifFile.seek(fileOffset);
    for (unsigned int i = 0; i < nbFiles; ++i)
    {
        unsigned int filesize, nameOffset, nameSize;
        bifFile.read((char*)&filesize, 4);
        bifFile.read((char*)&nameOffset, 4);
        bifFile.read((char*)&nameSize, 4);

        int back = bifFile.pos();

        bifFile.seek(nameOffset);
        char name[nameSize + 1];
        bifFile.read(name, nameSize);
        name[nameSize] = 0x00;
        QString qname = name;
        std::cout << name << std::endl;

        if (QFile::exists(bifFolder + qname))
            extractBIF(exportFolder, bifFolder + qname, i);

        bifFile.seek(back);

        if (_stopped)
            break;
    }
    _resources.clear();

    emit finished();
}

void TW1bifExtractor::extractBIF(QString exportFolder, QString filename, unsigned int bifId)
{
    std::cout << "Read bif"<< std::endl;
    QFile bifFile(filename);

    QFileInfo fileInf(bifFile);
    const QString baseFilename = fileInf.baseName();
    const QString newFileFolder = exportFolder + "/" + baseFilename + "/";

    if (!bifFile.open(QIODevice::ReadOnly))
        return;

    /*

    QByteArray bifContent = bifFile.readAll();
    QBuffer buffer(&bifContent, 0);
    if (!buffer.open(QIODevice::ReadOnly))
        return;
    */


    QDir dir;
    dir.mkdir(newFileFolder);

    // magic word "BIFFV1.1"
    bifFile.seek(8);

    unsigned int nbFiles, offset;
    bifFile.read((char*)&nbFiles, 4);
    std::cout << "nbFiles = " << nbFiles << std::endl;

    // unknown
    relativeSeek(&bifFile, 4);
    bifFile.read((char*)&offset, 4);

    bifFile.seek(offset);
    for (unsigned int i = 0; i < nbFiles; ++i)
    {
        unsigned short resourceType;
        unsigned int adress, size, resourceId, flags;

        bifFile.read((char*)&resourceId, 4);
        bifFile.read((char*)&flags, 4);

        //unsigned int bifId = ((flags & 0xFFF00000) >> 20);
        //std::cout << "flags=" << flags << ", resourceId=" << resourceId << std::endl;

        bifFile.read((char*)&adress, 4);
        bifFile.read((char*)&size, 4);
        bifFile.read((char*)&resourceType, 2);

        //std::cout << "adress = " << adress << std::endl;
        //std::cout << "size = " << size << std::endl;
        //std::cout << "pos = " << buffer.pos() << std::endl;

        relativeSeek(&bifFile, 2);

        if (resourceId > i)
        {
            // Curiously the last resource entry of djinni.bif seem to be missing
            continue;
        }

        unsigned int back = bifFile.pos();
        bifFile.seek(adress);

        ResourceId rId(bifId, resourceId);
        //std::cout << "id="<<  id <<", size=" << size << ", "<< back - 8 << ", i=" << i << std::endl;
        QByteArray fileData = bifFile.read(size);

        QString filename;
        QMap<ResourceId, QString>::iterator it = _resources.find(rId);
        if (it != _resources.end())
            filename = it.value();
        else
            filename = QString::number(i);

        QString extension = getExtensionFromResourceType(resourceType);
        QFile newFile(newFileFolder + filename + extension);
        if (!newFile.open(QIODevice::WriteOnly))
            return;
        newFile.write(fileData);
        newFile.close();

        bifFile.seek(back);

        _nbProgress++;
        int progression = (float)_nbProgress / (float)_resources.size() * 100.f;
        if (progression > _lastProgression)
        {
            _lastProgression = progression;
            emit onProgress(progression);
        }

        if (_stopped)
            break;
    }
    bifFile.close();
}

void TW1bifExtractor::quitThread()
{
    _stopped = true;
}


QMap<unsigned short, QString> TW1bifExtractor::getResourceTypeMap()
{
    QMap<unsigned short, QString> m;
    m.insert(0x0000, "res");
    m.insert(0x0001, "bmp");
    m.insert(0x0002, "mve");
    m.insert(0x0003, "tga");
    m.insert(0x0004, "wav");

    m.insert(0x0006, "plt");
    m.insert(0x0007, "ini");
    m.insert(0x0008, "mp3");
    m.insert(0x0009, "mpg");
    m.insert(0x000A, "txt");
    m.insert(0x000B, "xml");

    m.insert(0x07D0, "plh");
    m.insert(0x07D1, "tex");
    m.insert(0x07D2, "mdl");
    m.insert(0x07D3, "thg");

    m.insert(0x07D5, "fnt");

    m.insert(0x07D7, "lua");
    m.insert(0x07D8, "slt");
    m.insert(0x07D9, "nss");
    m.insert(0x07DA, "ncs");
    m.insert(0x07DB, "mod");
    m.insert(0x07DC, "are");
    m.insert(0x07DD, "set");
    m.insert(0x07DE, "ifo");
    m.insert(0x07DF, "bic");
    m.insert(0x07E0, "wok");
    m.insert(0x07E1, "2da");
    m.insert(0x07E2, "tlk");

    m.insert(0x07E6, "txi");
    m.insert(0x07E7, "git");
    m.insert(0x07E8, "bti");
    m.insert(0x07E9, "uti");
    m.insert(0x07EA, "btc");
    m.insert(0x07EB, "utc");


    m.insert(0x07ED, "dlg");
    m.insert(0x07EE, "itp");
    m.insert(0x07EF, "btt");
    m.insert(0x07F0, "utt");
    m.insert(0x07F1, "dds");
    m.insert(0x07F2, "bts");
    m.insert(0x07F3, "uts");
    m.insert(0x07F4, "ltr");
    m.insert(0x07F5, "gff");
    m.insert(0x07F6, "fac");
    m.insert(0x07F7, "bte");
    m.insert(0x07F8, "ute");
    m.insert(0x07F9, "btd");
    m.insert(0x07FA, "utd");
    m.insert(0x07FB, "btp");
    m.insert(0x07FC, "utp");
    m.insert(0x07FD, "dft");
    m.insert(0x07FE, "gic");
    m.insert(0x07FF, "gui");
    m.insert(0x0800, "css");
    m.insert(0x0801, "ccs");
    m.insert(0x0802, "btm");
    m.insert(0x0803, "utm");
    m.insert(0x0804, "dwk");
    m.insert(0x0805, "pwk");
    m.insert(0x0806, "btg");

    m.insert(0x0808, "jrl");
    m.insert(0x0809, "sav");
    m.insert(0x080A, "utw");
    m.insert(0x080B, "4pc");
    m.insert(0x080C, "ssf");

    m.insert(0x080F, "bik");
    m.insert(0x0810, "ndb");
    m.insert(0x0811, "ptm");
    m.insert(0x0812, "ptt");
    m.insert(0x0813, "ncm");
    m.insert(0x0814, "mfx");
    m.insert(0x0815, "mat");
    m.insert(0x0816, "mdb");
    m.insert(0x0817, "say");
    m.insert(0x0818, "ttf");
    m.insert(0x0819, "ttc");
    m.insert(0x081A, "cut");
    m.insert(0x081B, "ka");
    m.insert(0x081C, "jpg");
    m.insert(0x081D, "ico");
    m.insert(0x081E, "ogg");
    m.insert(0x081F, "spt");
    m.insert(0x0820, "spw");
    m.insert(0x0821, "wfx");
    m.insert(0x0822, "ugm");
    m.insert(0x0823, "qdb");
    m.insert(0x0824, "qst");
    m.insert(0x0825, "npc");
    m.insert(0x0826, "spn");
    m.insert(0x0827, "utx");
    m.insert(0x0828, "mmd");
    m.insert(0x0829, "smm");
    m.insert(0x082A, "uta");
    m.insert(0x082B, "mde");
    m.insert(0x082C, "mdv");
    m.insert(0x082D, "mda");
    m.insert(0x082E, "mba");
    m.insert(0x082F, "oct");
    m.insert(0x0830, "bfx");
    m.insert(0x0831, "pdb");
    m.insert(0x0832, "TheWitcherSave");
    m.insert(0x0833, "pvs");
    m.insert(0x0834, "cfx");
    m.insert(0x0835, "luc");

    m.insert(0x0837, "prb");
    m.insert(0x0838, "cam");
    m.insert(0x0839, "vds");
    m.insert(0x083A, "bin");
    m.insert(0x083B, "wob");
    m.insert(0x083C, "api");
    m.insert(0x083D, "properties");
    m.insert(0x083E, "png");

    m.insert(0x270B, "big");

    m.insert(0x270D, "erf");
    m.insert(0x270E, "bif");
    m.insert(0x270F, "key");

    return m;
}
