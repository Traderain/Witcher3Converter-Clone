#include "CWitcherMDLMeshFileLoader.h"

// Based on the loader and spec of the Xoreos engine

#include "ISceneManager.h"
#include "IVideoDriver.h"
#include "IWriteFile.h"

#include <iostream>

#include "LoadersUtils.h"


enum NodeType
{
    kNodeTypeNode         = 0x00000001,
    kNodeTypeLight        = 0x00000003,
    kNodeTypeEmitter      = 0x00000005,
    kNodeTypeCamera       = 0x00000009,
    kNodeTypeReference    = 0x00000011,
    kNodeTypeTrimesh      = 0x00000021,
    kNodeTypeSkin         = 0x00000061,
    kNodeTypeAABB         = 0x00000221,
    kNodeTypeTrigger      = 0x00000421,
    kNodeTypeSectorInfo   = 0x00001001,
    kNodeTypeWalkmesh     = 0x00002001,
    kNodeTypeDanglyNode   = 0x00004001,
    kNodeTypeTexturePaint = 0x00008001,
    kNodeTypeSpeedTree    = 0x00010001,
    kNodeTypeChain        = 0x00020001,
    kNodeTypeCloth        = 0x00040001
};

enum ControllerType
{
    ControllerPosition = 84,
    ControllerOrientation = 96,
    ControllerScale = 184
};

bool stringBeginWith(core::stringc base, core::stringc start)
{
    if (base.size() < start.size())
        return false;

    for (u32 i = 0; i < start.size(); ++i)
        if (start[i] != base[i])
            return false;

    return true;
}

bool readBool(io::IReadFile* f)
{
    char valChar = readData<char>(f);
    return valChar == 1 ? true : false;
}

CWitcherMDLMeshFileLoader::CWitcherMDLMeshFileLoader(scene::ISceneManager* smgr, io::IFileSystem* fs)
: SceneManager(smgr), FileSystem(fs)
{

}

bool CWitcherMDLMeshFileLoader::isALoadableFileExtension(const io::path& filename) const
{
    return core::hasFileExtension ( filename, "mdb" );
}

ArrayDef readArrayDef(io::IReadFile* file)
{
    ArrayDef def;
    def.firstElemOffest = readData<u32>(file);

    // nbUsedEntries is equal to nbAllocatedEntries
    def.nbUsedEntries = readData<u32>(file);
    def.nbAllocatedEntries = readData<u32>(file);
    return def;
}

scene::IAnimatedMesh* CWitcherMDLMeshFileLoader::createMesh(io::IReadFile* file)
{
    if (!file)
        return 0;

    AnimatedMesh = SceneManager->createSkinnedMesh();
    if (load(file))
    {
        SceneManager->getMeshManipulator()->recalculateNormals(AnimatedMesh);
        AnimatedMesh->finalize();
    }
    else
    {
        AnimatedMesh->drop();
        AnimatedMesh = 0;
    }
    return AnimatedMesh;
}

bool CWitcherMDLMeshFileLoader::load(io::IReadFile* file)
{
    GameTexturesPath = SceneManager->getParameters()->getAttributeAsStringW("TW_GAME_PATH");
    
    if (readData<u8>(file) != 0) // 0 = binary file
    {
        std::cout << "Error : not a binary file" << std::endl;
        return false;
    }
    file->seek(4);

    ModelInfos.fileVersion = readData<u32>(file) & 0x0FFFFFFF; // should be 133 or 136
    u32 modelCount = readData<u32>(file); // should be 1 ?
    if (modelCount != 1)
    {
        std::cout << "Error : modelCount != 1 isn't handled" << std::endl;
        return false;
    }

    file->seek(4, true);
    ModelInfos.sizeModelData = readData<u32>(file);
    file->seek(4, true);
    ModelInfos.offsetModelData = 32;

    if (ModelInfos.fileVersion == 133)
    {
        ModelInfos.offsetRawData  = readData<u32>(file) + ModelInfos.offsetModelData;
        ModelInfos.sizeRawData = readData<u32>(file);
        ModelInfos.offsetTexData  = ModelInfos.offsetModelData;
        ModelInfos.sizeTexData = 0;
    }
    else
    {
        ModelInfos.offsetRawData  = ModelInfos.offsetModelData;
        ModelInfos.sizeRawData = 0;
        ModelInfos.offsetTexData  = readData<u32>(file) + ModelInfos.offsetModelData;
        ModelInfos.sizeTexData = readData<u32>(file);
    }

    file->seek(8, true);

    core::stringc name = readStringFixedSize(file, 64);
    //std::cout << "name = " << name.c_str() << std::endl;
    u32 offsetRootNode = readData<u32>(file);

    file->seek(32, true);
    u8 type = readData<u8>(file);

    file->seek(3, true);
    file->seek(48, true);

    float firstLOD = readData<float>(file);
    float lastLOD  = readData<float>(file);

    file->seek(16, true);

    core::stringc detailMap = readStringFixedSize(file, 64);
    //std::cout << "map = " << detailMap.c_str() << std::endl;

    file->seek(4, true);

    float modelScale = readData<float>(file);

    core::stringc superModel = readStringFixedSize(file, 64);

    //std::cout << "superModel = " << superModel.c_str() << std::endl;

    file->seek(16, true);

    file->seek(ModelInfos.offsetModelData + offsetRootNode);
    loadNode(file);

    return true;
}

video::ITexture* CWitcherMDLMeshFileLoader::getTexture(core::stringc texPath)
{
    video::ITexture* texture = 0;

    core::array<io::path> texFolders;
    texFolders.push_back("textures00/");
    texFolders.push_back("textures01/");

    core::array<io::path> possibleExtensions;
    possibleExtensions.push_back(".dds");
    possibleExtensions.push_back(".bmp");
    possibleExtensions.push_back(".jpg");
    possibleExtensions.push_back(".jpeg");
    possibleExtensions.push_back(".tga");
    possibleExtensions.push_back(".png");

    for (u32 i = 0; i < possibleExtensions.size(); ++i)
    {
        for (u32 j = 0; j < texFolders.size(); ++j)
        {
            core::stringc filename = GameTexturesPath + texFolders[j] + texPath + possibleExtensions[i];
            std::cout << "test " << filename.c_str() << std::endl;

            if (FileSystem->existFile(filename))
            {
                std::cout << "file found" << std::endl;
                texture = SceneManager->getVideoDriver()->getTexture(filename);
            }

            if (texture)
            {
                std::cout << "return valid tex" << std::endl;
                return texture;
            }
        }
    }

    std::cout << "return 0" << std::endl;
    return texture;
    
}

core::matrix4 CWitcherMDLMeshFileLoader::readNodeControllers(io::IReadFile* file, ArrayDef key, ArrayDef data)
{
    core::matrix4 pos, rot, scale;
    core::matrix4 transform;

    core::array<float> controllerData = readArray<float>(file, data);

    const long back = file->getPos();
    file->seek(ModelInfos.offsetModelData + key.firstElemOffest);

    for (u32 i = 0; i < key.nbUsedEntries; ++i)
    {
        s32 controllerType = readData<s32>(file);
        s16 nbRows = readData<s16>(file);
        s16 firstKeyIndex = readData<s16>(file);
        s16 firstValueIndex = readData<s16>(file);
        s8 nbColumns = readData<s8>(file);
        file->seek(1, true); // Pad, not used


        if (controllerType == ControllerPosition)
        {
            f32 x = controllerData[firstValueIndex];
            f32 y = controllerData[firstValueIndex + 1];
            f32 z = controllerData[firstValueIndex + 2];
            core::vector3df position(x, y, z);
            pos.setTranslation(position);
        }
        if (controllerType == ControllerOrientation)
        {
            f32 x = controllerData[firstValueIndex];
            f32 y = controllerData[firstValueIndex + 1];
            f32 z = controllerData[firstValueIndex + 2];
            f32 w = controllerData[firstValueIndex + 3];
            w = core::RADTODEG * (acos(w) * 2.f);
            core::quaternion quat (x, y, z, w);
            core::vector3df euler;
            quat.toEuler(euler);
            rot.setRotationDegrees(euler);
        }
        if (controllerType == ControllerScale)
        {
            f32 scaleValue = controllerData[firstValueIndex];
            core::vector3df scaleVect(scaleValue, scaleValue, scaleValue);
            scale.setScale(scaleVect);
        }
    }
    transform = scale * rot * pos;


    file->seek(back);
    return transform;
}

void CWitcherMDLMeshFileLoader::readTexturePaint(io::IReadFile* file, core::matrix4 transform)
{
    ArrayDef layersDef = readArrayDef(file);

    file->seek(28, true);

    u32 offMeshArrays = readData<u32>(file);

    // sector ID
    file->seek(16, true);

    // bbox
    file->seek(24, true);

    // textures
    file->seek(24, true);

    // many useless material options
    file->seek(53, true);

    // dayNightTransition ?
    file->seek(200, true);

    file->seek(28, true);

    // lightmap name
    file->seek(64, true);

    file->seek(3, true);

    u32 endPos = file->seek(ModelInfos.offsetRawData + offMeshArrays);
    file->seek(4, true);


    ArrayDef vertexDef = readArrayDef(file);
    ArrayDef normalsDef = readArrayDef(file);

    ArrayDef tangentsDef = readArrayDef(file);
    ArrayDef binormalsDef = readArrayDef(file);

    ArrayDef tVerts[4];
    for (u32 t = 0; t < 4; t++)
        tVerts[t] = readArrayDef(file);


    ArrayDef unknownDef = readArrayDef(file);
    ArrayDef facesDef = readArrayDef(file);
    u32 facesCount = facesDef.nbUsedEntries;

    if ((vertexDef.nbUsedEntries == 0) || (facesDef.nbUsedEntries == 0))
    {
        file->seek(endPos);
        return;
    }


    // TODO !!!!!!

    for (u32 i = 0; i < layersDef.nbUsedEntries; ++i)
    {
        file->seek(ModelInfos.offsetRawData + layersDef.firstElemOffest + i * 52);
        bool hasTexture = (readData<u8>(file) == 1);
        if (!hasTexture)
            continue;

        file->seek(7, true);
        core::stringc texture = readStringFixedSize(file, 32);

        ArrayDef weightsDef = readArrayDef(file);
        core::array<f32> weights = readArray<f32>(file, weightsDef);
    }

    core::array<core::stringc> textures;



    // Read vertices
    scene::SSkinMeshBuffer* buffer = AnimatedMesh->addMeshBuffer();
    buffer->VertexType = video::EVT_STANDARD;

    buffer->Vertices_Standard.reallocate(vertexDef.nbUsedEntries);
    buffer->Vertices_Standard.set_used(vertexDef.nbUsedEntries);

    file->seek(ModelInfos.offsetRawData + vertexDef.firstElemOffest);
    for (u32 i = 0; i < vertexDef.nbUsedEntries; ++i)
    {
        float x = readData<f32>(file);
        float y = readData<f32>(file);
        float z = readData<f32>(file);
        core::vector3df pos(x, y, z);
        buffer->Vertices_Standard[i].Pos = pos;
        buffer->Vertices_Standard[i].Color = video::SColor(255.f, 255.f, 255.f, 255.f);
    }

    // Normals
    file->seek(ModelInfos.offsetRawData + normalsDef.firstElemOffest);
    for (u32 i = 0; i < normalsDef.nbUsedEntries; ++i)
    {
        float x = readData<f32>(file);
        float y = readData<f32>(file);
        float z = readData<f32>(file);
        buffer->Vertices_Standard[i].Normal = core::vector3df(x, y, z);
    }


    // UV
    // Some meshes has no TCoord
    for (u32 i = 0; i < buffer->getVertexCount(); i++)
    {
        buffer->Vertices_Standard[i].TCoords = core::vector2df(0.f, 0.f);
    }

    for (u32 t = 0; t < textures.size(); t++)
    {
        // TODO : TCoords2
        if (t > 0)
            break;

        file->seek(ModelInfos.offsetRawData + tVerts[t].firstElemOffest);
        for (u32 i = 0; i < tVerts[t].nbUsedEntries; i++)
        {
            float u = 0.f, v = 0.f;
            if (i < tVerts[t].nbUsedEntries)
            {
                u = readData<f32>(file);
                v = readData<f32>(file);
            }
            buffer->Vertices_Standard[i].TCoords = core::vector2df(u, v);
        }
    }

    // TODO : Binormals + tangents


    // Faces
    buffer->Indices.reallocate(facesCount * 3);
    buffer->Indices.set_used(facesCount * 3);

    file->seek(ModelInfos.offsetRawData + facesDef.firstElemOffest);
    for (u32 i = 0; i < facesCount; ++i)
    {
        buffer->Indices[i * 3 + 0] = readData<u32>(file);
        buffer->Indices[i * 3 + 1] = readData<u32>(file);
        buffer->Indices[i * 3 + 2] = readData<u32>(file);

        file->seek(68, true);
    }

    file->seek(endPos);
}

void CWitcherMDLMeshFileLoader::readMesh(io::IReadFile* file, core::matrix4 transform)
{
    file->seek(8, true); // Function pointer

    u32 offMeshArrays = readData<u32>(file);

    file->seek(4, true); // Unknown
    file->seek(24, true); // bbox
    file->seek(28, true); // Unknown
    file->seek(4, true); // fog scale
    file->seek(16, true); // Unknown

    file->seek(36, true); // diffuse, ambient and specular color
    file->seek(20, true); // render settings
    file->seek(4, true); // Unknown

    core::stringc texture[4];
    for (u32 i = 0; i < 4; ++i)
    {
        texture[i] = readStringFixedSize(file, 64);

        if (texture[i] == "NULL")
            texture[i] = "";

        std::cout << texture[i].c_str() << std::endl;
    }

    file->seek(7, true); // render settings

    // Unknown
    file->seek(1, true);
    file->seek(16, true); // render settings
    file->seek(4, true); // Unknown
    file->seek(13, true); // render settings
    file->seek(3, true); // Unknown
    file->seek(5, true);
    file->seek(3, true); // Unknown
    file->seek(9, true);

    core::stringc dayNightTransition = readStringFixedSize(file, 200);

    file->seek(2, true);

    // Unknown
    file->seek(1, true);
    file->seek(12, true);
    file->seek(8, true);

    core::stringc lightMapName = readStringFixedSize(file, 64);

    // Unknown
    file->seek(4, true);
    file->seek(4, true);

    ModelInfos.offsetTextureInfo = readData<u32>(file);

    u32 endPos = file->seek(ModelInfos.offsetRawData + offMeshArrays);

    file->seek(4, true);

    ArrayDef vertexDef = readArrayDef(file);
    ArrayDef normalsDef = readArrayDef(file);

    ArrayDef tangentsDef = readArrayDef(file);
    ArrayDef binormalsDef = readArrayDef(file);

    ArrayDef tVerts[4];
    for (u32 t = 0; t < 4; t++)
        tVerts[t] = readArrayDef(file);


    ArrayDef unknownDef = readArrayDef(file);
    ArrayDef facesDef = readArrayDef(file);
    u32 facesCount = facesDef.nbUsedEntries;


    if (ModelInfos.fileVersion == 133)
        ModelInfos.offsetTexData = readData<u32>(file);


    if ((vertexDef.nbUsedEntries == 0) || (facesDef.nbUsedEntries == 0))
    {
        file->seek(endPos);
        return;
    }

    core::array<core::stringc> textures;
    readTextures(file, textures);
    
    // Vertices
    scene::SSkinMeshBuffer* buffer = AnimatedMesh->addMeshBuffer();
    buffer->VertexType = video::EVT_STANDARD;

    buffer->Vertices_Standard.reallocate(vertexDef.nbUsedEntries);
    buffer->Vertices_Standard.set_used(vertexDef.nbUsedEntries);

    file->seek(ModelInfos.offsetRawData + vertexDef.firstElemOffest);
    for (u32 i = 0; i < vertexDef.nbUsedEntries; ++i)
    {
        float x = readData<f32>(file);
        float y = readData<f32>(file);
        float z = readData<f32>(file);
        core::vector3df pos(x, y, z);
        buffer->Vertices_Standard[i].Pos = pos;
        buffer->Vertices_Standard[i].Color = video::SColor(255.f, 255.f, 255.f, 255.f);
    }

    // Normals
    file->seek(ModelInfos.offsetRawData + normalsDef.firstElemOffest);
    for (u32 i = 0; i < normalsDef.nbUsedEntries; ++i)
    {
        float x = readData<f32>(file);
        float y = readData<f32>(file);
        float z = readData<f32>(file);
        buffer->Vertices_Standard[i].Normal = core::vector3df(x, y, z);
    }


    // UV
    // Some meshes has no TCoord
    for (u32 i = 0; i < buffer->getVertexCount(); i++)
    {
        buffer->Vertices_Standard[i].TCoords = core::vector2df(0.f, 0.f);
    }

    for (u32 t = 0; t < textures.size(); t++)
    {
        // TODO : TCoords2
        if (t > 0)
            break;

        file->seek(ModelInfos.offsetRawData + tVerts[t].firstElemOffest);
        for (u32 i = 0; i < tVerts[t].nbUsedEntries; i++)
        {
            float u = 0.f, v = 0.f;
            if (i < tVerts[t].nbUsedEntries)
            {
                u = readData<f32>(file);
                v = readData<f32>(file);
            }
            buffer->Vertices_Standard[i].TCoords = core::vector2df(u, v);
        }
    }

    // TODO : Binormals + tangents


    // Faces
    buffer->Indices.reallocate(facesCount * 3);
    buffer->Indices.set_used(facesCount * 3);

    file->seek(ModelInfos.offsetRawData + facesDef.firstElemOffest);
    for (u32 i = 0; i < facesCount; ++i)
    {
        file->seek(4 * 4 + 4, true);

        if (ModelInfos.fileVersion == 133)
            file->seek(3 * 4, true);

        buffer->Indices[i * 3 + 0] = readData<u32>(file);
        buffer->Indices[i * 3 + 1] = readData<u32>(file);
        buffer->Indices[i * 3 + 2] = readData<u32>(file);

        if (ModelInfos.fileVersion == 133)
            file->seek(4, true);
    }

    // Material
    video::SMaterial mat;
    if (textures.size() > 0)
    {
        video::ITexture* tex = getTexture(textures[0]);
        if (tex)
            mat.setTexture(0, tex);
    }
    buffer->Material = mat;

    if (textures.size() > 0)
        std::cout << textures[0].c_str() << std::endl;

    file->seek(endPos);
}

template <class T>
core::array<T> CWitcherMDLMeshFileLoader::readArray(io::IReadFile* file, ArrayDef def)
{
    const long back = file->getPos();
    file->seek(ModelInfos.offsetModelData + def.firstElemOffest);

    core::array<T> array;
    for (u32 i = 0; i < def.nbUsedEntries; ++i)
    {
        array.push_back(readData<T>(file));
    }

    file->seek(back);
    return array;
}

void CWitcherMDLMeshFileLoader::loadNode(io::IReadFile* file)
{
    file->seek(24, true); // Function pointers
    file->seek(8, true); // inherit color flag + id


    core::stringc name = readStringFixedSize(file, 64);
    //std::cout << "Name=" << name.c_str() << std::endl;

    file->seek(8, true); // parent geometry + parent node

    // Children nodes
    ArrayDef def = readArrayDef(file);
    //std::cout << "def count = " << def.nbUsedEntries << ", allocated = " << def.nbAllocatedEntries << ", offset = " << def.firstElemOffest << std::endl;
    core::array<u32> children = readArray<u32>(file, def);
    //std::cout << "child count = " << children.size() << std::endl;


    // Controllers
    ArrayDef controllerKeyDef = readArrayDef(file);
    ArrayDef controllerDataDef = readArrayDef(file);
    //core::matrix4 transform = readNodeControllers(file, controllerKeyDef, controllerDataDef);
    core::matrix4 transform;


    file->seek(4, true); // node flags/type

    file->seek(8, true); // fixed rot + imposter group ?

    s32 minLOD = readData<s32>(file);
    s32 maxLOD = readData<s32>(file);

    NodeType type = (NodeType) readData<u32>(file);
    //std::cout << "type = " << type << std::endl;


    switch (type)
    {
        case kNodeTypeTrimesh:
            std::cout << "Trimesh node" << std::endl;
            readMesh(file, transform);
            break;

        case kNodeTypeTexturePaint:
            std::cout << "Texture paint node" << std::endl;
            readTexturePaint(file, transform);
            break;

        default:
            break;
    }


    // Load the children
    for (u32 i = 0; i < children.size(); ++i)
    {
        file->seek(ModelInfos.offsetModelData + children[i]);
        loadNode(file);
    }
}


void CWitcherMDLMeshFileLoader::readTextures(io::IReadFile* file, core::array<core::stringc> &textures)
{
    u32 offset;
    if (ModelInfos.fileVersion == 133)
        offset = ModelInfos.offsetRawData + ModelInfos.offsetTexData;
    else
        offset = ModelInfos.offsetTexData + ModelInfos.offsetTextureInfo;

    file->seek(offset);

    u32 textureCount = readData<u32>(file);
    u32 offTexture = readData<u32>(file);

    core::array<core::stringc> textureLine;
    for (u32 i = 0; i < textureCount; ++i)
    {
        core::stringc line = readStringUntilNull(file);
        file->seek(1, true);
        line.trim();

        textureLine.push_back(line);
    }

    int hasShaderTex = false;

    for (u32 i = 0; i < textureCount; ++i)
    {
        int s = -1;
        int n = 0;

        core::stringc texture = textureLine[i];
        //std::cout << "texture= " << texture.c_str() <<  std::endl;

        if (stringBeginWith(texture, "texture texture0 "))
        {
            s = 17;
            n =  0 + (hasShaderTex ? 1 : 0);
        }
        if (stringBeginWith(texture, "texture texture1 "))
        {
            s = 17;
            n =  1 + (hasShaderTex ? 1 : 0);
        }
        if (stringBeginWith(texture, "texture texture2 "))
        {
            s = 17;
            n =  2 + (hasShaderTex ? 1 : 0);
        }
        if (stringBeginWith(texture, "texture texture3 "))
        {
            s = 17;
            n =  3;
        }
        if (stringBeginWith(texture, "texture tex "))
        {
            s = 12;
            n =  0 + (hasShaderTex ? 1 : 0);
        }
        if (stringBeginWith(texture, "shader "))
        {
            hasShaderTex = true;

            core::stringc shader = texture.subString(7, texture.size() - 7);
            if ((shader == "dadd_al_mul_alp") ||
                (shader == "corona") ||
                (shader == "normalmap") ||
                (shader == "norm_env_rim_ao") ||
                (shader == "transparency_2ps") ||
                (shader == "skin_n_rim_ao"))
                hasShaderTex = false;
        }

        if (s != -1)
        {
            textures.push_back(texture.subString(s, texture.size() - s));
        }
    }
}
