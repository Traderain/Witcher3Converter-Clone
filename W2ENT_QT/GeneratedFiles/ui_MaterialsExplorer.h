/********************************************************************************
** Form generated from reading UI file 'MaterialsExplorer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSEXPLORER_H
#define UI_MATERIALSEXPLORER_H

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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MaterialsExplorer
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *button_selectFile;
    QLabel *label_fileType;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelMaterials;
    QListWidget *listWidgetMaterials;
    QTableWidget *tableWidget_properties;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MaterialsExplorer)
    {
        if (MaterialsExplorer->objectName().isEmpty())
            MaterialsExplorer->setObjectName(QStringLiteral("MaterialsExplorer"));
        MaterialsExplorer->resize(780, 412);
        verticalLayout_2 = new QVBoxLayout(MaterialsExplorer);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(MaterialsExplorer);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(MaterialsExplorer);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        button_selectFile = new QPushButton(MaterialsExplorer);
        button_selectFile->setObjectName(QStringLiteral("button_selectFile"));

        horizontalLayout->addWidget(button_selectFile);


        verticalLayout_2->addLayout(horizontalLayout);

        label_fileType = new QLabel(MaterialsExplorer);
        label_fileType->setObjectName(QStringLiteral("label_fileType"));

        verticalLayout_2->addWidget(label_fileType);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelMaterials = new QLabel(MaterialsExplorer);
        labelMaterials->setObjectName(QStringLiteral("labelMaterials"));

        verticalLayout->addWidget(labelMaterials);

        listWidgetMaterials = new QListWidget(MaterialsExplorer);
        listWidgetMaterials->setObjectName(QStringLiteral("listWidgetMaterials"));

        verticalLayout->addWidget(listWidgetMaterials);


        horizontalLayout_2->addLayout(verticalLayout);

        tableWidget_properties = new QTableWidget(MaterialsExplorer);
        if (tableWidget_properties->columnCount() < 3)
            tableWidget_properties->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_properties->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_properties->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_properties->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_properties->setObjectName(QStringLiteral("tableWidget_properties"));
        tableWidget_properties->setColumnCount(3);
        tableWidget_properties->horizontalHeader()->setVisible(true);
        tableWidget_properties->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_properties->horizontalHeader()->setStretchLastSection(true);
        tableWidget_properties->verticalHeader()->setVisible(false);
        tableWidget_properties->verticalHeader()->setDefaultSectionSize(19);

        horizontalLayout_2->addWidget(tableWidget_properties);


        verticalLayout_2->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(MaterialsExplorer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(MaterialsExplorer);
        QObject::connect(buttonBox, SIGNAL(accepted()), MaterialsExplorer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MaterialsExplorer, SLOT(reject()));

        QMetaObject::connectSlotsByName(MaterialsExplorer);
    } // setupUi

    void retranslateUi(QDialog *MaterialsExplorer)
    {
        MaterialsExplorer->setWindowTitle(QApplication::translate("MaterialsExplorer", "Materials explorer", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        MaterialsExplorer->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("MaterialsExplorer", "Materials in ", Q_NULLPTR));
        button_selectFile->setText(QApplication::translate("MaterialsExplorer", "....", Q_NULLPTR));
        label_fileType->setText(QApplication::translate("MaterialsExplorer", "File Type :", Q_NULLPTR));
        labelMaterials->setText(QApplication::translate("MaterialsExplorer", "Materials", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_properties->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MaterialsExplorer", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_properties->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MaterialsExplorer", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_properties->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MaterialsExplorer", "Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MaterialsExplorer: public Ui_MaterialsExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSEXPLORER_H
