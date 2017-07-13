/********************************************************************************
** Form generated from reading UI file 'resize.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZE_H
#define UI_RESIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ReSize
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *spinbox_sizeX;
    QDoubleSpinBox *spinbox_sizeY;
    QDoubleSpinBox *spinbox_sizeZ;
    QLabel *label_unitX;
    QLabel *label_unitY;
    QLabel *label_unitZ;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *combo_unit;

    void setupUi(QDialog *ReSize)
    {
        if (ReSize->objectName().isEmpty())
            ReSize->setObjectName(QStringLiteral("ReSize"));
        ReSize->resize(360, 205);
        buttonBox = new QDialogButtonBox(ReSize);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 160, 311, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ReSize);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 41, 16));
        label_2 = new QLabel(ReSize);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 41, 16));
        label_3 = new QLabel(ReSize);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 41, 16));
        spinbox_sizeX = new QDoubleSpinBox(ReSize);
        spinbox_sizeX->setObjectName(QStringLiteral("spinbox_sizeX"));
        spinbox_sizeX->setGeometry(QRect(90, 60, 91, 22));
        spinbox_sizeX->setDecimals(5);
        spinbox_sizeX->setMaximum(9999.99);
        spinbox_sizeY = new QDoubleSpinBox(ReSize);
        spinbox_sizeY->setObjectName(QStringLiteral("spinbox_sizeY"));
        spinbox_sizeY->setGeometry(QRect(90, 120, 91, 22));
        spinbox_sizeY->setDecimals(5);
        spinbox_sizeY->setMaximum(9999.99);
        spinbox_sizeZ = new QDoubleSpinBox(ReSize);
        spinbox_sizeZ->setObjectName(QStringLiteral("spinbox_sizeZ"));
        spinbox_sizeZ->setGeometry(QRect(90, 90, 91, 22));
        spinbox_sizeZ->setDecimals(5);
        spinbox_sizeZ->setMaximum(9999.99);
        label_unitX = new QLabel(ReSize);
        label_unitX->setObjectName(QStringLiteral("label_unitX"));
        label_unitX->setGeometry(QRect(190, 60, 21, 20));
        label_unitY = new QLabel(ReSize);
        label_unitY->setObjectName(QStringLiteral("label_unitY"));
        label_unitY->setGeometry(QRect(190, 90, 21, 20));
        label_unitZ = new QLabel(ReSize);
        label_unitZ->setObjectName(QStringLiteral("label_unitZ"));
        label_unitZ->setGeometry(QRect(190, 120, 21, 20));
        label_7 = new QLabel(ReSize);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 10, 251, 31));
        QFont font;
        font.setPointSize(12);
        label_7->setFont(font);
        label_8 = new QLabel(ReSize);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(310, 60, 31, 16));
        combo_unit = new QComboBox(ReSize);
        combo_unit->setObjectName(QStringLiteral("combo_unit"));
        combo_unit->setGeometry(QRect(270, 80, 69, 22));

        retranslateUi(ReSize);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReSize, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReSize, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReSize);
    } // setupUi

    void retranslateUi(QDialog *ReSize)
    {
        ReSize->setWindowTitle(QApplication::translate("ReSize", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ReSize", "Size X :", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReSize", "Size Y :", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReSize", "Size Z :", Q_NULLPTR));
        label_unitX->setText(QApplication::translate("ReSize", "cm", Q_NULLPTR));
        label_unitY->setText(QApplication::translate("ReSize", "cm", Q_NULLPTR));
        label_unitZ->setText(QApplication::translate("ReSize", "cm", Q_NULLPTR));
        label_7->setText(QApplication::translate("ReSize", "Size of the model in the Redkit :", Q_NULLPTR));
        label_8->setText(QApplication::translate("ReSize", "Unit :", Q_NULLPTR));
        combo_unit->clear();
        combo_unit->insertItems(0, QStringList()
         << QApplication::translate("ReSize", "cm", Q_NULLPTR)
         << QApplication::translate("ReSize", "m", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class ReSize: public Ui_ReSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZE_H
