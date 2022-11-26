/********************************************************************************
** Form generated from reading UI file 'IssueDescribe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUEDESCRIBE_H
#define UI_ISSUEDESCRIBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <date_edit.h>

QT_BEGIN_NAMESPACE

class Ui_IssueInfoPanelClass
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_13;
    QComboBox *VehicleModel_comboBox;
    QLabel *label_15;
    QComboBox *Program_comboBox;
    QLabel *label_21;
    QComboBox *IssueType_comboBox;
    QLabel *label_20;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_18;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_9;
    QTextEdit *Solution_textEdit;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_17;
    CDateEdit *Estimate_dateEdit;
    QComboBox *Supplier_comboBox;
    QSpacerItem *horizontalSpacer_10;
    QComboBox *State_comboBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *ID_lineEdit;
    QLabel *label_17;
    CDateEdit *Actual_dateEdit;
    QTextEdit *IssueDescribe_textEdit;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_16;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QComboBox *Reason_comboBox;
    QLineEdit *RecordPerson_lineEdit;
    QComboBox *SafeLevel_comboBox;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *FourRingType_comboBox;
    QLineEdit *PersonInCharge_lineEdit;
    QLineEdit *VehicleVersion_lineEdit;
    QSpacerItem *horizontalSpacer_12;
    QComboBox *Level_comboBox;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *FourRing_comboBox;
    QLabel *label_13;
    QDateEdit *Record_dateEdit;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *IssueResson_textEdit;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *APPVersion_lineEdit;
    QSpacerItem *horizontalSpacer_8;
    QTextEdit *Result_textEdit;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *CleanEstimateDateBtn;
    QPushButton *CleanActualDateBtn;

    void setupUi(QWidget *IssueInfoPanelClass)
    {
        if (IssueInfoPanelClass->objectName().isEmpty())
            IssueInfoPanelClass->setObjectName(QStringLiteral("IssueInfoPanelClass"));
        IssueInfoPanelClass->resize(916, 836);
        scrollArea = new QScrollArea(IssueInfoPanelClass);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 9, 581, 581));
        scrollArea->setMinimumSize(QSize(490, 491));
        scrollArea->setAutoFillBackground(true);
        scrollArea->setStyleSheet(QStringLiteral("background-color:white"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -711, 562, 1300));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1300));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, 10, 551, 1081));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 14, 0, 1, 2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 10, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 2, 6, 1, 3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 11, 0, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 1, 2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 0, 6, 1, 3);

        VehicleModel_comboBox = new QComboBox(layoutWidget);
        VehicleModel_comboBox->setObjectName(QStringLiteral("VehicleModel_comboBox"));

        gridLayout->addWidget(VehicleModel_comboBox, 2, 2, 1, 3);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 12, 0, 1, 2);

        Program_comboBox = new QComboBox(layoutWidget);
        Program_comboBox->setObjectName(QStringLiteral("Program_comboBox"));

        gridLayout->addWidget(Program_comboBox, 0, 2, 1, 3);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 7, 0, 1, 2);

        IssueType_comboBox = new QComboBox(layoutWidget);
        IssueType_comboBox->setObjectName(QStringLiteral("IssueType_comboBox"));

        gridLayout->addWidget(IssueType_comboBox, 3, 2, 1, 3);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 3, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 9, 0, 1, 2);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 1, 0, 1, 2);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 2, 0, 1, 2);

        horizontalSpacer_9 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 20, 4, 1, 1);

        Solution_textEdit = new QTextEdit(layoutWidget);
        Solution_textEdit->setObjectName(QStringLiteral("Solution_textEdit"));

        gridLayout->addWidget(Solution_textEdit, 18, 2, 1, 8);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 17, 0, 1, 2);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_16, 3, 6, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout->addWidget(label_22, 8, 0, 1, 2);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 1, 6, 1, 3);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_17, 7, 6, 1, 1);

        Estimate_dateEdit = new CDateEdit(layoutWidget);
        Estimate_dateEdit->setObjectName(QStringLiteral("Estimate_dateEdit"));
        Estimate_dateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(Estimate_dateEdit, 20, 2, 1, 1);

        Supplier_comboBox = new QComboBox(layoutWidget);
        Supplier_comboBox->setObjectName(QStringLiteral("Supplier_comboBox"));

        gridLayout->addWidget(Supplier_comboBox, 1, 2, 1, 3);

        horizontalSpacer_10 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 21, 4, 1, 1);

        State_comboBox = new QComboBox(layoutWidget);
        State_comboBox->setObjectName(QStringLiteral("State_comboBox"));

        gridLayout->addWidget(State_comboBox, 16, 2, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 10, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 14, 5, 1, 1);

        ID_lineEdit = new QLineEdit(layoutWidget);
        ID_lineEdit->setObjectName(QStringLiteral("ID_lineEdit"));

        gridLayout->addWidget(ID_lineEdit, 4, 2, 1, 4);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 0, 0, 1, 2);

        Actual_dateEdit = new CDateEdit(layoutWidget);
        Actual_dateEdit->setObjectName(QStringLiteral("Actual_dateEdit"));
        Actual_dateEdit->setAccelerated(false);
        Actual_dateEdit->setProperty("showGroupSeparator", QVariant(false));
        Actual_dateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(Actual_dateEdit, 21, 2, 1, 1);

        IssueDescribe_textEdit = new QTextEdit(layoutWidget);
        IssueDescribe_textEdit->setObjectName(QStringLiteral("IssueDescribe_textEdit"));

        gridLayout->addWidget(IssueDescribe_textEdit, 5, 2, 1, 8);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 18, 0, 1, 2);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 16, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 15, 0, 1, 2);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 13, 0, 1, 2);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 19, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 6, 1, 3);

        Reason_comboBox = new QComboBox(layoutWidget);
        Reason_comboBox->setObjectName(QStringLiteral("Reason_comboBox"));

        gridLayout->addWidget(Reason_comboBox, 12, 2, 1, 3);

        RecordPerson_lineEdit = new QLineEdit(layoutWidget);
        RecordPerson_lineEdit->setObjectName(QStringLiteral("RecordPerson_lineEdit"));

        gridLayout->addWidget(RecordPerson_lineEdit, 14, 2, 1, 3);

        SafeLevel_comboBox = new QComboBox(layoutWidget);
        SafeLevel_comboBox->setObjectName(QStringLiteral("SafeLevel_comboBox"));

        gridLayout->addWidget(SafeLevel_comboBox, 13, 2, 1, 3);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 12, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 9, 4, 1, 1);

        FourRingType_comboBox = new QComboBox(layoutWidget);
        FourRingType_comboBox->setObjectName(QStringLiteral("FourRingType_comboBox"));

        gridLayout->addWidget(FourRingType_comboBox, 11, 2, 1, 3);

        PersonInCharge_lineEdit = new QLineEdit(layoutWidget);
        PersonInCharge_lineEdit->setObjectName(QStringLiteral("PersonInCharge_lineEdit"));

        gridLayout->addWidget(PersonInCharge_lineEdit, 15, 2, 1, 3);

        VehicleVersion_lineEdit = new QLineEdit(layoutWidget);
        VehicleVersion_lineEdit->setObjectName(QStringLiteral("VehicleVersion_lineEdit"));

        gridLayout->addWidget(VehicleVersion_lineEdit, 7, 2, 1, 3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 13, 5, 1, 1);

        Level_comboBox = new QComboBox(layoutWidget);
        Level_comboBox->setObjectName(QStringLiteral("Level_comboBox"));

        gridLayout->addWidget(Level_comboBox, 9, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 4, 1, 1);

        FourRing_comboBox = new QComboBox(layoutWidget);
        FourRing_comboBox->setObjectName(QStringLiteral("FourRing_comboBox"));

        gridLayout->addWidget(FourRing_comboBox, 10, 2, 1, 3);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 20, 0, 1, 2);

        Record_dateEdit = new QDateEdit(layoutWidget);
        Record_dateEdit->setObjectName(QStringLiteral("Record_dateEdit"));
        Record_dateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(Record_dateEdit, 6, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 11, 6, 1, 1);

        IssueResson_textEdit = new QTextEdit(layoutWidget);
        IssueResson_textEdit->setObjectName(QStringLiteral("IssueResson_textEdit"));

        gridLayout->addWidget(IssueResson_textEdit, 17, 2, 1, 8);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 15, 5, 1, 1);

        APPVersion_lineEdit = new QLineEdit(layoutWidget);
        APPVersion_lineEdit->setObjectName(QStringLiteral("APPVersion_lineEdit"));

        gridLayout->addWidget(APPVersion_lineEdit, 8, 2, 1, 3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 16, 5, 1, 1);

        Result_textEdit = new QTextEdit(layoutWidget);
        Result_textEdit->setObjectName(QStringLiteral("Result_textEdit"));

        gridLayout->addWidget(Result_textEdit, 19, 2, 1, 8);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 21, 0, 1, 2);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 8, 6, 1, 1);

        CleanEstimateDateBtn = new QPushButton(layoutWidget);
        CleanEstimateDateBtn->setObjectName(QStringLiteral("CleanEstimateDateBtn"));

        gridLayout->addWidget(CleanEstimateDateBtn, 20, 3, 1, 1);

        CleanActualDateBtn = new QPushButton(layoutWidget);
        CleanActualDateBtn->setObjectName(QStringLiteral("CleanActualDateBtn"));

        gridLayout->addWidget(CleanActualDateBtn, 21, 3, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(IssueInfoPanelClass);

        QMetaObject::connectSlotsByName(IssueInfoPanelClass);
    } // setupUi

    void retranslateUi(QWidget *IssueInfoPanelClass)
    {
        IssueInfoPanelClass->setWindowTitle(QApplication::translate("IssueInfoPanelClass", "Form", Q_NULLPTR));
        label_7->setText(QApplication::translate("IssueInfoPanelClass", "\350\250\230\351\214\204\344\272\272:", Q_NULLPTR));
        label_5->setText(QApplication::translate("IssueInfoPanelClass", "\345\233\233\347\222\260:", Q_NULLPTR));
        label_6->setText(QApplication::translate("IssueInfoPanelClass", "\345\233\233\347\222\260\345\210\206\351\241\236:", Q_NULLPTR));
        label_2->setText(QApplication::translate("IssueInfoPanelClass", "\345\225\217\351\241\214\346\217\217\350\277\260:", Q_NULLPTR));
        VehicleModel_comboBox->setCurrentText(QString());
        label_15->setText(QApplication::translate("IssueInfoPanelClass", "\347\234\237\345\233\240\345\210\206\351\241\236:", Q_NULLPTR));
        Program_comboBox->setCurrentText(QString());
        label_21->setText(QApplication::translate("IssueInfoPanelClass", "\350\273\212\347\253\257\350\273\237\351\253\224\347\211\210\346\234\254:", Q_NULLPTR));
        IssueType_comboBox->setCurrentText(QString());
        label_20->setText(QApplication::translate("IssueInfoPanelClass", "\351\241\236\345\236\213:", Q_NULLPTR));
        label->setText(QApplication::translate("IssueInfoPanelClass", "ID:", Q_NULLPTR));
        label_3->setText(QApplication::translate("IssueInfoPanelClass", "\350\250\230\351\214\204\346\227\245\346\234\237:", Q_NULLPTR));
        label_4->setText(QApplication::translate("IssueInfoPanelClass", "\345\232\264\351\207\215\347\255\211\347\264\232:", Q_NULLPTR));
        label_18->setText(QApplication::translate("IssueInfoPanelClass", "\350\273\212\345\273\240:", Q_NULLPTR));
        label_19->setText(QApplication::translate("IssueInfoPanelClass", "\350\273\212\345\236\213:", Q_NULLPTR));
        label_10->setText(QApplication::translate("IssueInfoPanelClass", "\351\227\256\351\242\230\345\216\237\345\233\240:", Q_NULLPTR));
        label_22->setText(QApplication::translate("IssueInfoPanelClass", "APP\347\211\210\346\234\254:", Q_NULLPTR));
        Supplier_comboBox->setCurrentText(QString());
        State_comboBox->setCurrentText(QString());
        label_17->setText(QApplication::translate("IssueInfoPanelClass", "\351\240\205\347\233\256:", Q_NULLPTR));
        label_11->setText(QApplication::translate("IssueInfoPanelClass", "\350\247\243\345\206\263\346\226\271\346\241\210:", Q_NULLPTR));
        label_9->setText(QApplication::translate("IssueInfoPanelClass", "\347\213\200\346\205\213:", Q_NULLPTR));
        label_8->setText(QApplication::translate("IssueInfoPanelClass", "\350\262\240\350\262\254\344\272\272:", Q_NULLPTR));
        label_16->setText(QApplication::translate("IssueInfoPanelClass", "\345\256\211\345\205\250\347\255\211\347\272\247:", Q_NULLPTR));
        label_12->setText(QApplication::translate("IssueInfoPanelClass", "\346\224\271\345\226\204\347\213\200\346\263\201\346\217\217\350\277\260:", Q_NULLPTR));
        Reason_comboBox->setCurrentText(QString());
        SafeLevel_comboBox->setCurrentText(QString());
        FourRingType_comboBox->setCurrentText(QString());
        Level_comboBox->setCurrentText(QString());
        FourRing_comboBox->setCurrentText(QString());
        label_13->setText(QApplication::translate("IssueInfoPanelClass", "\351\242\204\350\256\241\345\256\214\346\210\220\346\227\245\346\234\237:", Q_NULLPTR));
        label_14->setText(QApplication::translate("IssueInfoPanelClass", "\345\256\236\351\231\205\345\256\214\346\210\220\346\227\245\346\234\237:", Q_NULLPTR));
        CleanEstimateDateBtn->setText(QApplication::translate("IssueInfoPanelClass", "\346\270\205\351\231\244\346\227\245\346\234\237", Q_NULLPTR));
        CleanActualDateBtn->setText(QApplication::translate("IssueInfoPanelClass", "\346\270\205\351\231\244\346\227\245\346\234\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IssueInfoPanelClass: public Ui_IssueInfoPanelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUEDESCRIBE_H
