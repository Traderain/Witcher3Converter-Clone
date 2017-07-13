/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *View;
    QWidget *tab_export;
    QRadioButton *radioButton_pack0;
    QRadioButton *radioButton_custom;
    QPushButton *button_selectDir;
    QLineEdit *lineEdit_exportFolder;
    QCheckBox *checkBox;
    QCheckBox *checkBox_mtNormalsMap;
    QCheckBox *checkBox_moveTextures;
    QCheckBox *checkBox_mtSpecularMap;
    QComboBox *comboBox_format;
    QCheckBox *checkBox_convertTextures;
    QWidget *tab_tw3;
    QPushButton *pushButton_TW3_selectTexFolder;
    QLineEdit *lineEdit_TW3_texFolder;
    QLabel *label_TW3_texFolder;
    QCheckBox *checkBox_TW3_loadSkel;
    QCheckBox *checkBox_TW3_loadBestLOD;
    QWidget *tab_view;
    QLabel *label_camera;
    QDoubleSpinBox *doubleSpinBox_cameraSpeed;
    QDoubleSpinBox *doubleSpinBox_cameraRotSpeed;
    QPushButton *button_colorSelector;
    QLabel *label_colorSelector;
    QLabel *label_movementSpeed;
    QLabel *label_rotSpeed;
    QPushButton *pushButton_reset;
    QWidget *tab_debug;
    QCheckBox *checkBox_debug;
    QLabel *label_debugLog;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QStringLiteral("Options"));
        Options->resize(400, 300);
        Options->setModal(true);
        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        View = new QTabWidget(Options);
        View->setObjectName(QStringLiteral("View"));
        View->setGeometry(QRect(10, 10, 381, 231));
        tab_export = new QWidget();
        tab_export->setObjectName(QStringLiteral("tab_export"));
        radioButton_pack0 = new QRadioButton(tab_export);
        radioButton_pack0->setObjectName(QStringLiteral("radioButton_pack0"));
        radioButton_pack0->setGeometry(QRect(20, 10, 341, 17));
        radioButton_custom = new QRadioButton(tab_export);
        radioButton_custom->setObjectName(QStringLiteral("radioButton_custom"));
        radioButton_custom->setGeometry(QRect(20, 30, 341, 17));
        button_selectDir = new QPushButton(tab_export);
        button_selectDir->setObjectName(QStringLiteral("button_selectDir"));
        button_selectDir->setGeometry(QRect(320, 60, 41, 23));
        lineEdit_exportFolder = new QLineEdit(tab_export);
        lineEdit_exportFolder->setObjectName(QStringLiteral("lineEdit_exportFolder"));
        lineEdit_exportFolder->setGeometry(QRect(16, 60, 301, 20));
        checkBox = new QCheckBox(tab_export);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setGeometry(QRect(170, 100, 81, 17));
        checkBox->setChecked(true);
        checkBox_mtNormalsMap = new QCheckBox(tab_export);
        checkBox_mtNormalsMap->setObjectName(QStringLiteral("checkBox_mtNormalsMap"));
        checkBox_mtNormalsMap->setGeometry(QRect(170, 120, 91, 17));
        checkBox_moveTextures = new QCheckBox(tab_export);
        checkBox_moveTextures->setObjectName(QStringLiteral("checkBox_moveTextures"));
        checkBox_moveTextures->setGeometry(QRect(20, 100, 141, 17));
        checkBox_moveTextures->setChecked(true);
        checkBox_mtSpecularMap = new QCheckBox(tab_export);
        checkBox_mtSpecularMap->setObjectName(QStringLiteral("checkBox_mtSpecularMap"));
        checkBox_mtSpecularMap->setGeometry(QRect(170, 140, 91, 17));
        comboBox_format = new QComboBox(tab_export);
        comboBox_format->setObjectName(QStringLiteral("comboBox_format"));
        comboBox_format->setEnabled(false);
        comboBox_format->setGeometry(QRect(250, 180, 69, 22));
        checkBox_convertTextures = new QCheckBox(tab_export);
        checkBox_convertTextures->setObjectName(QStringLiteral("checkBox_convertTextures"));
        checkBox_convertTextures->setGeometry(QRect(20, 180, 221, 17));
        View->addTab(tab_export, QString());
        tab_tw3 = new QWidget();
        tab_tw3->setObjectName(QStringLiteral("tab_tw3"));
        pushButton_TW3_selectTexFolder = new QPushButton(tab_tw3);
        pushButton_TW3_selectTexFolder->setObjectName(QStringLiteral("pushButton_TW3_selectTexFolder"));
        pushButton_TW3_selectTexFolder->setGeometry(QRect(290, 50, 75, 23));
        lineEdit_TW3_texFolder = new QLineEdit(tab_tw3);
        lineEdit_TW3_texFolder->setObjectName(QStringLiteral("lineEdit_TW3_texFolder"));
        lineEdit_TW3_texFolder->setGeometry(QRect(20, 50, 261, 20));
        label_TW3_texFolder = new QLabel(tab_tw3);
        label_TW3_texFolder->setObjectName(QStringLiteral("label_TW3_texFolder"));
        label_TW3_texFolder->setGeometry(QRect(20, 30, 341, 16));
        checkBox_TW3_loadSkel = new QCheckBox(tab_tw3);
        checkBox_TW3_loadSkel->setObjectName(QStringLiteral("checkBox_TW3_loadSkel"));
        checkBox_TW3_loadSkel->setGeometry(QRect(20, 130, 341, 17));
        checkBox_TW3_loadBestLOD = new QCheckBox(tab_tw3);
        checkBox_TW3_loadBestLOD->setObjectName(QStringLiteral("checkBox_TW3_loadBestLOD"));
        checkBox_TW3_loadBestLOD->setGeometry(QRect(20, 100, 341, 17));
        View->addTab(tab_tw3, QString());
        tab_view = new QWidget();
        tab_view->setObjectName(QStringLiteral("tab_view"));
        label_camera = new QLabel(tab_view);
        label_camera->setObjectName(QStringLiteral("label_camera"));
        label_camera->setGeometry(QRect(20, 20, 341, 16));
        doubleSpinBox_cameraSpeed = new QDoubleSpinBox(tab_view);
        doubleSpinBox_cameraSpeed->setObjectName(QStringLiteral("doubleSpinBox_cameraSpeed"));
        doubleSpinBox_cameraSpeed->setGeometry(QRect(180, 50, 62, 22));
        doubleSpinBox_cameraSpeed->setMinimum(-9999);
        doubleSpinBox_cameraSpeed->setMaximum(9999);
        doubleSpinBox_cameraRotSpeed = new QDoubleSpinBox(tab_view);
        doubleSpinBox_cameraRotSpeed->setObjectName(QStringLiteral("doubleSpinBox_cameraRotSpeed"));
        doubleSpinBox_cameraRotSpeed->setGeometry(QRect(180, 80, 62, 22));
        doubleSpinBox_cameraRotSpeed->setMinimum(-9999);
        doubleSpinBox_cameraRotSpeed->setMaximum(9999);
        button_colorSelector = new QPushButton(tab_view);
        button_colorSelector->setObjectName(QStringLiteral("button_colorSelector"));
        button_colorSelector->setGeometry(QRect(120, 140, 51, 41));
        label_colorSelector = new QLabel(tab_view);
        label_colorSelector->setObjectName(QStringLiteral("label_colorSelector"));
        label_colorSelector->setGeometry(QRect(20, 160, 101, 16));
        label_movementSpeed = new QLabel(tab_view);
        label_movementSpeed->setObjectName(QStringLiteral("label_movementSpeed"));
        label_movementSpeed->setGeometry(QRect(20, 50, 151, 16));
        label_rotSpeed = new QLabel(tab_view);
        label_rotSpeed->setObjectName(QStringLiteral("label_rotSpeed"));
        label_rotSpeed->setGeometry(QRect(20, 80, 151, 16));
        pushButton_reset = new QPushButton(tab_view);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(300, 180, 75, 23));
        View->addTab(tab_view, QString());
        tab_debug = new QWidget();
        tab_debug->setObjectName(QStringLiteral("tab_debug"));
        checkBox_debug = new QCheckBox(tab_debug);
        checkBox_debug->setObjectName(QStringLiteral("checkBox_debug"));
        checkBox_debug->setGeometry(QRect(20, 100, 251, 17));
        label_debugLog = new QLabel(tab_debug);
        label_debugLog->setObjectName(QStringLiteral("label_debugLog"));
        label_debugLog->setGeometry(QRect(20, 10, 331, 81));
        label_debugLog->setWordWrap(true);
        View->addTab(tab_debug, QString());

        retranslateUi(Options);
        QObject::connect(buttonBox, SIGNAL(rejected()), Options, SLOT(reject()));

        View->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Options", Q_NULLPTR));
        radioButton_pack0->setText(QApplication::translate("Options", "Export to the pack0 folder", Q_NULLPTR));
        radioButton_custom->setText(QApplication::translate("Options", "Export to an other folder", Q_NULLPTR));
        button_selectDir->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Options", "Diffuse map", Q_NULLPTR));
        checkBox_mtNormalsMap->setText(QApplication::translate("Options", "Normals map", Q_NULLPTR));
        checkBox_moveTextures->setText(QApplication::translate("Options", "Copy textures", Q_NULLPTR));
        checkBox_mtSpecularMap->setText(QApplication::translate("Options", "Specular map", Q_NULLPTR));
        comboBox_format->clear();
        comboBox_format->insertItems(0, QStringList()
         << QApplication::translate("Options", ".jpg", Q_NULLPTR)
         << QApplication::translate("Options", ".png", Q_NULLPTR)
         << QApplication::translate("Options", ".tga", Q_NULLPTR)
         << QApplication::translate("Options", ".pcx", Q_NULLPTR)
         << QApplication::translate("Options", ".ppm", Q_NULLPTR)
        );
        checkBox_convertTextures->setText(QApplication::translate("Options", "Convert textures (DDS format by default)", Q_NULLPTR));
        View->setTabText(View->indexOf(tab_export), QApplication::translate("Options", "Export", Q_NULLPTR));
        pushButton_TW3_selectTexFolder->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        label_TW3_texFolder->setText(QApplication::translate("Options", "Textures folder :", Q_NULLPTR));
        checkBox_TW3_loadSkel->setText(QApplication::translate("Options", "Load skeleton (experimental - disable it if you don't need it)", Q_NULLPTR));
        checkBox_TW3_loadBestLOD->setText(QApplication::translate("Options", "Load only the best LOD", Q_NULLPTR));
        View->setTabText(View->indexOf(tab_tw3), QApplication::translate("Options", "TW3 settings", Q_NULLPTR));
        label_camera->setText(QApplication::translate("Options", "Cam\303\251ra", Q_NULLPTR));
        button_colorSelector->setText(QApplication::translate("Options", "Change", Q_NULLPTR));
        label_colorSelector->setText(QApplication::translate("Options", "Background color", Q_NULLPTR));
        label_movementSpeed->setText(QApplication::translate("Options", "Movement Speed", Q_NULLPTR));
        label_rotSpeed->setText(QApplication::translate("Options", "Rotation speed", Q_NULLPTR));
        pushButton_reset->setText(QApplication::translate("Options", "Reset", Q_NULLPTR));
        View->setTabText(View->indexOf(tab_view), QApplication::translate("Options", "View", Q_NULLPTR));
        checkBox_debug->setText(QApplication::translate("Options", "Enable \"debug.log\"", Q_NULLPTR));
        label_debugLog->setText(QApplication::translate("Options", "If you have a problem to load a w2ent/w2mesh file, you can enable this option to generate a log file. This file can help me to solve your problem, so in case of problem, you can send me this file (via the forum or by mail at jeanlouis[dot]boudrand[at]hotmail[dot]fr.", Q_NULLPTR));
        View->setTabText(View->indexOf(tab_debug), QApplication::translate("Options", "Debug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
