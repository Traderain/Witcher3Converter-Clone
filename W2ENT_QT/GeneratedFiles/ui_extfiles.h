/********************************************************************************
** Form generated from reading UI file 'extfiles.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTFILES_H
#define UI_EXTFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExtFiles
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *button_selectFile;
    QLabel *label_fileType;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_back;
    QPushButton *button_checkW2MI;
    QPushButton *button_close;

    void setupUi(QDialog *ExtFiles)
    {
        if (ExtFiles->objectName().isEmpty())
            ExtFiles->setObjectName(QStringLiteral("ExtFiles"));
        ExtFiles->resize(400, 326);
        verticalLayout = new QVBoxLayout(ExtFiles);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ExtFiles);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(ExtFiles);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        button_selectFile = new QPushButton(ExtFiles);
        button_selectFile->setObjectName(QStringLiteral("button_selectFile"));

        horizontalLayout->addWidget(button_selectFile);


        verticalLayout->addLayout(horizontalLayout);

        label_fileType = new QLabel(ExtFiles);
        label_fileType->setObjectName(QStringLiteral("label_fileType"));

        verticalLayout->addWidget(label_fileType);

        listWidget = new QListWidget(ExtFiles);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        button_back = new QPushButton(ExtFiles);
        button_back->setObjectName(QStringLiteral("button_back"));
        button_back->setEnabled(false);

        horizontalLayout_2->addWidget(button_back);

        button_checkW2MI = new QPushButton(ExtFiles);
        button_checkW2MI->setObjectName(QStringLiteral("button_checkW2MI"));
        button_checkW2MI->setEnabled(false);

        horizontalLayout_2->addWidget(button_checkW2MI);


        verticalLayout->addLayout(horizontalLayout_2);

        button_close = new QPushButton(ExtFiles);
        button_close->setObjectName(QStringLiteral("button_close"));

        verticalLayout->addWidget(button_close);


        retranslateUi(ExtFiles);

        QMetaObject::connectSlotsByName(ExtFiles);
    } // setupUi

    void retranslateUi(QDialog *ExtFiles)
    {
        ExtFiles->setWindowTitle(QApplication::translate("ExtFiles", "Linked files", Q_NULLPTR));
        label_2->setText(QApplication::translate("ExtFiles", "Files linked in ", Q_NULLPTR));
        button_selectFile->setText(QApplication::translate("ExtFiles", "....", Q_NULLPTR));
        label_fileType->setText(QApplication::translate("ExtFiles", "File type :", Q_NULLPTR));
        button_back->setText(QApplication::translate("ExtFiles", "Back", Q_NULLPTR));
        button_checkW2MI->setText(QApplication::translate("ExtFiles", "Check the selected w2mi", Q_NULLPTR));
        button_close->setText(QApplication::translate("ExtFiles", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExtFiles: public Ui_ExtFiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTFILES_H
