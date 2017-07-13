/********************************************************************************
** Form generated from reading UI file 'cleantexturespath.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEANTEXTURESPATH_H
#define UI_CLEANTEXTURESPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_CleanTexturesPath
{
public:
    QProgressBar *progressBar;
    QLabel *label_tex;
    QLabel *label_progression;
    QLabel *label_pleaseWait;

    void setupUi(QDialog *CleanTexturesPath)
    {
        if (CleanTexturesPath->objectName().isEmpty())
            CleanTexturesPath->setObjectName(QStringLiteral("CleanTexturesPath"));
        CleanTexturesPath->resize(400, 120);
        progressBar = new QProgressBar(CleanTexturesPath);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 70, 371, 23));
        progressBar->setValue(24);
        label_tex = new QLabel(CleanTexturesPath);
        label_tex->setObjectName(QStringLiteral("label_tex"));
        label_tex->setGeometry(QRect(10, 100, 381, 16));
        label_progression = new QLabel(CleanTexturesPath);
        label_progression->setObjectName(QStringLiteral("label_progression"));
        label_progression->setGeometry(QRect(10, 40, 381, 16));
        label_pleaseWait = new QLabel(CleanTexturesPath);
        label_pleaseWait->setObjectName(QStringLiteral("label_pleaseWait"));
        label_pleaseWait->setGeometry(QRect(10, 10, 111, 16));
        QFont font;
        font.setPointSize(12);
        label_pleaseWait->setFont(font);

        retranslateUi(CleanTexturesPath);

        QMetaObject::connectSlotsByName(CleanTexturesPath);
    } // setupUi

    void retranslateUi(QDialog *CleanTexturesPath)
    {
        CleanTexturesPath->setWindowTitle(QApplication::translate("CleanTexturesPath", "The filename of the textures is modified...", Q_NULLPTR));
        label_tex->setText(QApplication::translate("CleanTexturesPath", "TextLabel", Q_NULLPTR));
        label_progression->setText(QApplication::translate("CleanTexturesPath", "Texture 1 of 2568", Q_NULLPTR));
        label_pleaseWait->setText(QApplication::translate("CleanTexturesPath", "Please wait...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CleanTexturesPath: public Ui_CleanTexturesPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEANTEXTURESPATH_H
