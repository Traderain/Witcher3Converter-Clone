/********************************************************************************
** Form generated from reading UI file 'tw1bifextractorui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TW1BIFEXTRACTORUI_H
#define UI_TW1BIFEXTRACTORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_tw1bifextractorUI
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_keyFile;
    QLineEdit *lineEdit_keyFile;
    QPushButton *pushButton_selectFile;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_exportFolder;
    QLineEdit *lineEdit_exportFolder;
    QPushButton *pushButton_selectFolder;
    QPushButton *pushButton_extract;
    QLabel *label_state;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tw1bifextractorUI)
    {
        if (tw1bifextractorUI->objectName().isEmpty())
            tw1bifextractorUI->setObjectName(QStringLiteral("tw1bifextractorUI"));
        tw1bifextractorUI->resize(400, 261);
        verticalLayout = new QVBoxLayout(tw1bifextractorUI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(tw1bifextractorUI);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setPointSize(12);
        label_title->setFont(font);

        verticalLayout->addWidget(label_title);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_keyFile = new QLabel(tw1bifextractorUI);
        label_keyFile->setObjectName(QStringLiteral("label_keyFile"));

        horizontalLayout_2->addWidget(label_keyFile);

        lineEdit_keyFile = new QLineEdit(tw1bifextractorUI);
        lineEdit_keyFile->setObjectName(QStringLiteral("lineEdit_keyFile"));

        horizontalLayout_2->addWidget(lineEdit_keyFile);

        pushButton_selectFile = new QPushButton(tw1bifextractorUI);
        pushButton_selectFile->setObjectName(QStringLiteral("pushButton_selectFile"));

        horizontalLayout_2->addWidget(pushButton_selectFile);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_exportFolder = new QLabel(tw1bifextractorUI);
        label_exportFolder->setObjectName(QStringLiteral("label_exportFolder"));

        horizontalLayout_3->addWidget(label_exportFolder);

        lineEdit_exportFolder = new QLineEdit(tw1bifextractorUI);
        lineEdit_exportFolder->setObjectName(QStringLiteral("lineEdit_exportFolder"));

        horizontalLayout_3->addWidget(lineEdit_exportFolder);

        pushButton_selectFolder = new QPushButton(tw1bifextractorUI);
        pushButton_selectFolder->setObjectName(QStringLiteral("pushButton_selectFolder"));

        horizontalLayout_3->addWidget(pushButton_selectFolder);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton_extract = new QPushButton(tw1bifextractorUI);
        pushButton_extract->setObjectName(QStringLiteral("pushButton_extract"));

        verticalLayout->addWidget(pushButton_extract);

        label_state = new QLabel(tw1bifextractorUI);
        label_state->setObjectName(QStringLiteral("label_state"));

        verticalLayout->addWidget(label_state);

        progressBar = new QProgressBar(tw1bifextractorUI);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        buttonBox = new QDialogButtonBox(tw1bifextractorUI);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(tw1bifextractorUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), tw1bifextractorUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), tw1bifextractorUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(tw1bifextractorUI);
    } // setupUi

    void retranslateUi(QDialog *tw1bifextractorUI)
    {
        tw1bifextractorUI->setWindowTitle(QApplication::translate("tw1bifextractorUI", "TW1 BIF extractor", Q_NULLPTR));
        label_title->setText(QApplication::translate("tw1bifextractorUI", "The Witcher 1 BIF extractor", Q_NULLPTR));
        label_keyFile->setText(QApplication::translate("tw1bifextractorUI", "Key file :", Q_NULLPTR));
        pushButton_selectFile->setText(QApplication::translate("tw1bifextractorUI", "...", Q_NULLPTR));
        label_exportFolder->setText(QApplication::translate("tw1bifextractorUI", "Destination folder :", Q_NULLPTR));
        pushButton_selectFolder->setText(QApplication::translate("tw1bifextractorUI", "...", Q_NULLPTR));
        pushButton_extract->setText(QApplication::translate("tw1bifextractorUI", "Extract", Q_NULLPTR));
        label_state->setText(QApplication::translate("tw1bifextractorUI", "State : Waiting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class tw1bifextractorUI: public Ui_tw1bifextractorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TW1BIFEXTRACTORUI_H
