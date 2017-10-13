/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnglish;
    QAction *actionQuitter;
    QAction *actionWireframe;
    QAction *actionWebpage;
    QAction *actionSearch;
    QAction *actionOptions;
    QAction *actionSize;
    QAction *actionLOD0;
    QAction *actionLOD1;
    QAction *actionLOD2;
    QAction *actionClear_current_LOD;
    QAction *actionRigging;
    QAction *actionClear_all_LODs;
    QAction *actionCollision_mesh;
    QAction *actionClean_textures_path;
    QAction *actionShow_linked_files;
    QAction *actionSet_rig;
    QAction *actionAdd_mesh;
    QAction *actionAdd_mesh_2;
    QAction *actionBIF_extractor;
    QAction *actionSet_animations;
    QAction *actionMaterials_explorer;
    QWidget *centralWidget;
    QPushButton *button_convert;
    QComboBox *comboBox_format;
    QLineEdit *lineEdit_exportedFilename;
    QLabel *label_exportedFilename;
    QLineEdit *lineEdit_ImportedFile;
    QLabel *label_logs;
    QPushButton *button_fileSelector;
    QTextEdit *textEdit_log;
    QFrame *line;
    QPushButton *button_selectDir;
    QLineEdit *lineEdit_folder;
    QLabel *label_baseDir;
    QLabel *label_format;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuLanguages;
    QMenu *menuDisplay;
    QMenu *menuHelp;
    QMenu *menu_RE_tools;
    QMenu *menuLOD;
    QMenu *menuThe_Witcher_3_tools;
    QMenu *menuThe_Witcher_1_tools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(768, 647);
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionWireframe = new QAction(MainWindow);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        actionWireframe->setCheckable(true);
        actionWebpage = new QAction(MainWindow);
        actionWebpage->setObjectName(QStringLiteral("actionWebpage"));
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QStringLiteral("actionSearch"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionSize = new QAction(MainWindow);
        actionSize->setObjectName(QStringLiteral("actionSize"));
        actionSize->setEnabled(false);
        actionLOD0 = new QAction(MainWindow);
        actionLOD0->setObjectName(QStringLiteral("actionLOD0"));
        actionLOD0->setCheckable(true);
        actionLOD0->setChecked(true);
        actionLOD1 = new QAction(MainWindow);
        actionLOD1->setObjectName(QStringLiteral("actionLOD1"));
        actionLOD1->setCheckable(true);
        actionLOD2 = new QAction(MainWindow);
        actionLOD2->setObjectName(QStringLiteral("actionLOD2"));
        actionLOD2->setCheckable(true);
        actionClear_current_LOD = new QAction(MainWindow);
        actionClear_current_LOD->setObjectName(QStringLiteral("actionClear_current_LOD"));
        actionClear_current_LOD->setEnabled(true);
        actionRigging = new QAction(MainWindow);
        actionRigging->setObjectName(QStringLiteral("actionRigging"));
        actionRigging->setCheckable(true);
        actionClear_all_LODs = new QAction(MainWindow);
        actionClear_all_LODs->setObjectName(QStringLiteral("actionClear_all_LODs"));
        actionCollision_mesh = new QAction(MainWindow);
        actionCollision_mesh->setObjectName(QStringLiteral("actionCollision_mesh"));
        actionCollision_mesh->setCheckable(true);
        actionClean_textures_path = new QAction(MainWindow);
        actionClean_textures_path->setObjectName(QStringLiteral("actionClean_textures_path"));
        actionShow_linked_files = new QAction(MainWindow);
        actionShow_linked_files->setObjectName(QStringLiteral("actionShow_linked_files"));
        actionShow_linked_files->setEnabled(false);
        actionSet_rig = new QAction(MainWindow);
        actionSet_rig->setObjectName(QStringLiteral("actionSet_rig"));
        actionAdd_mesh = new QAction(MainWindow);
        actionAdd_mesh->setObjectName(QStringLiteral("actionAdd_mesh"));
        actionAdd_mesh_2 = new QAction(MainWindow);
        actionAdd_mesh_2->setObjectName(QStringLiteral("actionAdd_mesh_2"));
        actionBIF_extractor = new QAction(MainWindow);
        actionBIF_extractor->setObjectName(QStringLiteral("actionBIF_extractor"));
        actionSet_animations = new QAction(MainWindow);
        actionSet_animations->setObjectName(QStringLiteral("actionSet_animations"));
        actionSet_animations->setEnabled(true);
        actionMaterials_explorer = new QAction(MainWindow);
        actionMaterials_explorer->setObjectName(QStringLiteral("actionMaterials_explorer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button_convert = new QPushButton(centralWidget);
        button_convert->setObjectName(QStringLiteral("button_convert"));
        button_convert->setEnabled(false);
        button_convert->setGeometry(QRect(420, 460, 91, 51));
        comboBox_format = new QComboBox(centralWidget);
        comboBox_format->setObjectName(QStringLiteral("comboBox_format"));
        comboBox_format->setGeometry(QRect(580, 490, 171, 21));
        lineEdit_exportedFilename = new QLineEdit(centralWidget);
        lineEdit_exportedFilename->setObjectName(QStringLiteral("lineEdit_exportedFilename"));
        lineEdit_exportedFilename->setGeometry(QRect(560, 460, 201, 21));
        label_exportedFilename = new QLabel(centralWidget);
        label_exportedFilename->setObjectName(QStringLiteral("label_exportedFilename"));
        label_exportedFilename->setGeometry(QRect(520, 460, 41, 21));
        lineEdit_ImportedFile = new QLineEdit(centralWidget);
        lineEdit_ImportedFile->setObjectName(QStringLiteral("lineEdit_ImportedFile"));
        lineEdit_ImportedFile->setGeometry(QRect(10, 490, 401, 21));
        label_logs = new QLabel(centralWidget);
        label_logs->setObjectName(QStringLiteral("label_logs"));
        label_logs->setGeometry(QRect(10, 522, 46, 13));
        button_fileSelector = new QPushButton(centralWidget);
        button_fileSelector->setObjectName(QStringLiteral("button_fileSelector"));
        button_fileSelector->setGeometry(QRect(10, 460, 401, 25));
        textEdit_log = new QTextEdit(centralWidget);
        textEdit_log->setObjectName(QStringLiteral("textEdit_log"));
        textEdit_log->setEnabled(true);
        textEdit_log->setGeometry(QRect(10, 540, 751, 81));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 510, 751, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        button_selectDir = new QPushButton(centralWidget);
        button_selectDir->setObjectName(QStringLiteral("button_selectDir"));
        button_selectDir->setGeometry(QRect(680, 0, 88, 20));
        lineEdit_folder = new QLineEdit(centralWidget);
        lineEdit_folder->setObjectName(QStringLiteral("lineEdit_folder"));
        lineEdit_folder->setGeometry(QRect(120, 0, 561, 20));
        label_baseDir = new QLabel(centralWidget);
        label_baseDir->setObjectName(QStringLiteral("label_baseDir"));
        label_baseDir->setGeometry(QRect(10, 0, 111, 16));
        label_format = new QLabel(centralWidget);
        label_format->setObjectName(QStringLiteral("label_format"));
        label_format->setGeometry(QRect(520, 490, 41, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuLanguages = new QMenu(menuBar);
        menuLanguages->setObjectName(QStringLiteral("menuLanguages"));
        menuDisplay = new QMenu(menuBar);
        menuDisplay->setObjectName(QStringLiteral("menuDisplay"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menu_RE_tools = new QMenu(menuBar);
        menu_RE_tools->setObjectName(QStringLiteral("menu_RE_tools"));
        menu_RE_tools->setEnabled(true);
        menuLOD = new QMenu(menu_RE_tools);
        menuLOD->setObjectName(QStringLiteral("menuLOD"));
        menuThe_Witcher_3_tools = new QMenu(menuBar);
        menuThe_Witcher_3_tools->setObjectName(QStringLiteral("menuThe_Witcher_3_tools"));
        menuThe_Witcher_1_tools = new QMenu(menuBar);
        menuThe_Witcher_1_tools->setObjectName(QStringLiteral("menuThe_Witcher_1_tools"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menu_RE_tools->menuAction());
        menuBar->addAction(menuThe_Witcher_3_tools->menuAction());
        menuBar->addAction(menuThe_Witcher_1_tools->menuAction());
        menuBar->addAction(menuDisplay->menuAction());
        menuBar->addAction(menuLanguages->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionSearch);
        menuMenu->addAction(actionShow_linked_files);
        menuMenu->addSeparator();
        menuMenu->addAction(actionOptions);
        menuMenu->addSeparator();
        menuMenu->addAction(actionAdd_mesh_2);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuitter);
        menuDisplay->addAction(actionWireframe);
        menuDisplay->addAction(actionRigging);
        menuHelp->addAction(actionWebpage);
        menu_RE_tools->addAction(actionSize);
        menu_RE_tools->addAction(menuLOD->menuAction());
        menuLOD->addAction(actionLOD0);
        menuLOD->addAction(actionLOD1);
        menuLOD->addAction(actionLOD2);
        menuLOD->addSeparator();
        menuLOD->addAction(actionCollision_mesh);
        menuLOD->addSeparator();
        menuLOD->addAction(actionClear_current_LOD);
        menuLOD->addAction(actionClear_all_LODs);
        menuThe_Witcher_3_tools->addAction(actionClean_textures_path);
        menuThe_Witcher_3_tools->addAction(actionSet_rig);
        menuThe_Witcher_3_tools->addAction(actionSet_animations);
        menuThe_Witcher_3_tools->addAction(actionMaterials_explorer);
        menuThe_Witcher_1_tools->addAction(actionBIF_extractor);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "The Witcher 3D models converter", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionWireframe->setText(QApplication::translate("MainWindow", "Wireframe", Q_NULLPTR));
        actionWebpage->setText(QApplication::translate("MainWindow", "Webpage", Q_NULLPTR));
        actionSearch->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSearch->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOptions->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        actionSize->setText(QApplication::translate("MainWindow", "Size", Q_NULLPTR));
        actionLOD0->setText(QApplication::translate("MainWindow", "LOD0 (empty)", Q_NULLPTR));
        actionLOD1->setText(QApplication::translate("MainWindow", "LOD1 (empty)", Q_NULLPTR));
        actionLOD2->setText(QApplication::translate("MainWindow", "LOD2 (empty)", Q_NULLPTR));
        actionClear_current_LOD->setText(QApplication::translate("MainWindow", "Clear current LOD", Q_NULLPTR));
        actionRigging->setText(QApplication::translate("MainWindow", "Skeleton", Q_NULLPTR));
        actionClear_all_LODs->setText(QApplication::translate("MainWindow", "Clear all LODs", Q_NULLPTR));
        actionCollision_mesh->setText(QApplication::translate("MainWindow", "Collision mesh (empty)", Q_NULLPTR));
        actionClean_textures_path->setText(QApplication::translate("MainWindow", "LUA utils : Clean textures path", Q_NULLPTR));
        actionShow_linked_files->setText(QApplication::translate("MainWindow", "Show linked files", Q_NULLPTR));
        actionSet_rig->setText(QApplication::translate("MainWindow", "Set rig", Q_NULLPTR));
        actionAdd_mesh->setText(QApplication::translate("MainWindow", "Add mesh(es)", Q_NULLPTR));
        actionAdd_mesh_2->setText(QApplication::translate("MainWindow", "Add mesh(es)", Q_NULLPTR));
        actionBIF_extractor->setText(QApplication::translate("MainWindow", "BIF extractor", Q_NULLPTR));
        actionSet_animations->setText(QApplication::translate("MainWindow", "Set animations", Q_NULLPTR));
        actionMaterials_explorer->setText(QApplication::translate("MainWindow", "Materials explorer", Q_NULLPTR));
        button_convert->setText(QApplication::translate("MainWindow", "Convert ->", Q_NULLPTR));
        comboBox_format->clear();
        comboBox_format->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", ".obj (Wavefront OBJ)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".dae (Collada)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".ply (Polygon File Format)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".stl (STereoLithography)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".irrmesh (Irrlicht mesh)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".b3d (Blitz3D)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".re (Red Engine)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".x (DirectX)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".3ds (Autodesk 3DS)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".assbin (Assimp binary)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".assxml (Assimp XML)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".stp (Step files)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".gltf (GL Transmission Format)", Q_NULLPTR)
         << QApplication::translate("MainWindow", ".glb (GL Transmission Format - Binary)", Q_NULLPTR)
        );
        label_exportedFilename->setText(QApplication::translate("MainWindow", "Name :", Q_NULLPTR));
        label_logs->setText(QApplication::translate("MainWindow", "Logs :", Q_NULLPTR));
        button_fileSelector->setText(QApplication::translate("MainWindow", "Select .w2ent file", Q_NULLPTR));
        button_selectDir->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_baseDir->setText(QApplication::translate("MainWindow", "Base directory :", Q_NULLPTR));
        label_format->setText(QApplication::translate("MainWindow", "Format :", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
        menuLanguages->setTitle(QApplication::translate("MainWindow", "Languages", Q_NULLPTR));
        menuDisplay->setTitle(QApplication::translate("MainWindow", "Display", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menu_RE_tools->setTitle(QApplication::translate("MainWindow", "Redkit tools", Q_NULLPTR));
        menuLOD->setTitle(QApplication::translate("MainWindow", "LOD", Q_NULLPTR));
        menuThe_Witcher_3_tools->setTitle(QApplication::translate("MainWindow", "The Witcher 3 tools", Q_NULLPTR));
        menuThe_Witcher_1_tools->setTitle(QApplication::translate("MainWindow", "The Witcher 1 tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
