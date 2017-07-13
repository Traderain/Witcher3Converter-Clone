/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_4;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout;
    QLabel *label_extensions;
    QLineEdit *lineEdit_extensionsFilter;
    QPushButton *pushButton_reset;
    QSplitter *splitter_2;
    QCheckBox *checkBox_folder;
    QPushButton *pushButton_search;
    QSplitter *splitter;
    QLabel *label_progression;
    QProgressBar *progressBar_search;
    QLabel *label_result;
    QListWidget *listWidget_results;
    QSplitter *splitter_3;
    QPushButton *pushButton_load;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(599, 386);
        verticalLayout = new QVBoxLayout(Search);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_4 = new QSplitter(Search);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_name = new QLabel(splitter_4);
        label_name->setObjectName(QStringLiteral("label_name"));
        splitter_4->addWidget(label_name);
        lineEdit_name = new QLineEdit(splitter_4);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        splitter_4->addWidget(lineEdit_name);

        verticalLayout->addWidget(splitter_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_extensions = new QLabel(Search);
        label_extensions->setObjectName(QStringLiteral("label_extensions"));

        horizontalLayout->addWidget(label_extensions);

        lineEdit_extensionsFilter = new QLineEdit(Search);
        lineEdit_extensionsFilter->setObjectName(QStringLiteral("lineEdit_extensionsFilter"));

        horizontalLayout->addWidget(lineEdit_extensionsFilter);

        pushButton_reset = new QPushButton(Search);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        horizontalLayout->addWidget(pushButton_reset);


        verticalLayout->addLayout(horizontalLayout);

        splitter_2 = new QSplitter(Search);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        checkBox_folder = new QCheckBox(splitter_2);
        checkBox_folder->setObjectName(QStringLiteral("checkBox_folder"));
        splitter_2->addWidget(checkBox_folder);
        pushButton_search = new QPushButton(splitter_2);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        pushButton_search->setAutoDefault(true);
        splitter_2->addWidget(pushButton_search);

        verticalLayout->addWidget(splitter_2);

        splitter = new QSplitter(Search);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_progression = new QLabel(splitter);
        label_progression->setObjectName(QStringLiteral("label_progression"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_progression->sizePolicy().hasHeightForWidth());
        label_progression->setSizePolicy(sizePolicy);
        splitter->addWidget(label_progression);
        progressBar_search = new QProgressBar(splitter);
        progressBar_search->setObjectName(QStringLiteral("progressBar_search"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar_search->sizePolicy().hasHeightForWidth());
        progressBar_search->setSizePolicy(sizePolicy1);
        progressBar_search->setValue(0);
        splitter->addWidget(progressBar_search);

        verticalLayout->addWidget(splitter);

        label_result = new QLabel(Search);
        label_result->setObjectName(QStringLiteral("label_result"));

        verticalLayout->addWidget(label_result);

        listWidget_results = new QListWidget(Search);
        listWidget_results->setObjectName(QStringLiteral("listWidget_results"));

        verticalLayout->addWidget(listWidget_results);

        splitter_3 = new QSplitter(Search);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        pushButton_load = new QPushButton(splitter_3);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        pushButton_load->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_load->sizePolicy().hasHeightForWidth());
        pushButton_load->setSizePolicy(sizePolicy2);
        splitter_3->addWidget(pushButton_load);

        verticalLayout->addWidget(splitter_3);

        buttonBox = new QDialogButtonBox(Search);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Search);
        QObject::connect(buttonBox, SIGNAL(accepted()), Search, SLOT(accept()));

        pushButton_search->setDefault(true);


        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "Search", Q_NULLPTR));
        label_name->setText(QApplication::translate("Search", "Name :", Q_NULLPTR));
        label_extensions->setText(QApplication::translate("Search", "Extensions filter :", Q_NULLPTR));
        pushButton_reset->setText(QApplication::translate("Search", "Reset", Q_NULLPTR));
        checkBox_folder->setText(QApplication::translate("Search", "Check also the folders name (more results)", Q_NULLPTR));
        pushButton_search->setText(QApplication::translate("Search", "Search", Q_NULLPTR));
        label_progression->setText(QApplication::translate("Search", "Progression", Q_NULLPTR));
        label_result->setText(QApplication::translate("Search", "Result :", Q_NULLPTR));
        pushButton_load->setText(QApplication::translate("Search", "Load", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
