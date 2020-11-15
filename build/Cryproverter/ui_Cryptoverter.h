/********************************************************************************
** Form generated from reading UI file 'Cryptoverter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRYPTOVERTER_H
#define UI_CRYPTOVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cryptoverter
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QComboBox *comboBoxAlgorithm;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLineEdit *lineEditPrivateKey;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextDataInfo;
    QSpacerItem *verticalSpacer_3;
    QPushButton *buttonDirection;
    QPushButton *buttonConvert;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *buttonLoadFile;
    QPlainTextEdit *plainTextOutput;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *buttonSaveFile;
    QPlainTextEdit *plainTextInput;

    void setupUi(QWidget *Cryptoverter)
    {
        if (Cryptoverter->objectName().isEmpty())
            Cryptoverter->setObjectName(QString::fromUtf8("Cryptoverter"));
        Cryptoverter->setEnabled(true);
        Cryptoverter->resize(856, 517);
        gridLayout = new QGridLayout(Cryptoverter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(Cryptoverter);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        comboBoxAlgorithm = new QComboBox(Cryptoverter);
        comboBoxAlgorithm->addItem(QString());
        comboBoxAlgorithm->addItem(QString());
        comboBoxAlgorithm->setObjectName(QString::fromUtf8("comboBoxAlgorithm"));
        comboBoxAlgorithm->setEnabled(true);
        comboBoxAlgorithm->setLayoutDirection(Qt::LeftToRight);
        comboBoxAlgorithm->setEditable(false);

        verticalLayout_2->addWidget(comboBoxAlgorithm);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        label_4 = new QLabel(Cryptoverter);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        lineEditPrivateKey = new QLineEdit(Cryptoverter);
        lineEditPrivateKey->setObjectName(QString::fromUtf8("lineEditPrivateKey"));

        verticalLayout_2->addWidget(lineEditPrivateKey);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_3 = new QLabel(Cryptoverter);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        plainTextDataInfo = new QPlainTextEdit(Cryptoverter);
        plainTextDataInfo->setObjectName(QString::fromUtf8("plainTextDataInfo"));
        plainTextDataInfo->setEnabled(false);

        verticalLayout_2->addWidget(plainTextDataInfo);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_3);

        buttonDirection = new QPushButton(Cryptoverter);
        buttonDirection->setObjectName(QString::fromUtf8("buttonDirection"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonDirection->sizePolicy().hasHeightForWidth());
        buttonDirection->setSizePolicy(sizePolicy);
        buttonDirection->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(buttonDirection);

        buttonConvert = new QPushButton(Cryptoverter);
        buttonConvert->setObjectName(QString::fromUtf8("buttonConvert"));
        buttonConvert->setMinimumSize(QSize(0, 60));

        verticalLayout_2->addWidget(buttonConvert);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Cryptoverter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        buttonLoadFile = new QPushButton(Cryptoverter);
        buttonLoadFile->setObjectName(QString::fromUtf8("buttonLoadFile"));

        horizontalLayout->addWidget(buttonLoadFile);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plainTextOutput = new QPlainTextEdit(Cryptoverter);
        plainTextOutput->setObjectName(QString::fromUtf8("plainTextOutput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextOutput->sizePolicy().hasHeightForWidth());
        plainTextOutput->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plainTextOutput, 1, 4, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(Cryptoverter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        buttonSaveFile = new QPushButton(Cryptoverter);
        buttonSaveFile->setObjectName(QString::fromUtf8("buttonSaveFile"));

        horizontalLayout_3->addWidget(buttonSaveFile);


        gridLayout->addLayout(horizontalLayout_3, 0, 4, 1, 1);

        plainTextInput = new QPlainTextEdit(Cryptoverter);
        plainTextInput->setObjectName(QString::fromUtf8("plainTextInput"));

        gridLayout->addWidget(plainTextInput, 1, 0, 1, 1);


        retranslateUi(Cryptoverter);

        QMetaObject::connectSlotsByName(Cryptoverter);
    } // setupUi

    void retranslateUi(QWidget *Cryptoverter)
    {
        Cryptoverter->setWindowTitle(QApplication::translate("Cryptoverter", "Cryptoverter", nullptr));
        label_5->setText(QApplication::translate("Cryptoverter", "Encryption Algorithm", nullptr));
        comboBoxAlgorithm->setItemText(0, QApplication::translate("Cryptoverter", "AES 128-Bit", nullptr));
        comboBoxAlgorithm->setItemText(1, QApplication::translate("Cryptoverter", "Test", nullptr));

        label_4->setText(QApplication::translate("Cryptoverter", "Private Key", nullptr));
        label_3->setText(QApplication::translate("Cryptoverter", "Input Data Information", nullptr));
        buttonDirection->setText(QApplication::translate("Cryptoverter", "Encrypt", nullptr));
        buttonConvert->setText(QApplication::translate("Cryptoverter", "Convert", nullptr));
        label_2->setText(QApplication::translate("Cryptoverter", "Input:", nullptr));
        buttonLoadFile->setText(QApplication::translate("Cryptoverter", "Load File", nullptr));
        label->setText(QApplication::translate("Cryptoverter", "Output:", nullptr));
        buttonSaveFile->setText(QApplication::translate("Cryptoverter", "Save File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cryptoverter: public Ui_Cryptoverter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRYPTOVERTER_H
