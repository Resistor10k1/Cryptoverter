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
#include <QtWidgets/QToolButton>
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
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditPrivateKey;
    QToolButton *buttonPrivateKey;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextDataInfo;
    QSpacerItem *verticalSpacer_3;
    QToolButton *buttonDirection;
    QToolButton *buttonConvert;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *buttonClear;
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
        Cryptoverter->resize(1214, 745);
        gridLayout = new QGridLayout(Cryptoverter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(Cryptoverter);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        comboBoxAlgorithm = new QComboBox(Cryptoverter);
        comboBoxAlgorithm->setObjectName(QString::fromUtf8("comboBoxAlgorithm"));
        comboBoxAlgorithm->setEnabled(true);
        comboBoxAlgorithm->setLayoutDirection(Qt::LeftToRight);
        comboBoxAlgorithm->setEditable(false);

        verticalLayout_2->addWidget(comboBoxAlgorithm);

        verticalSpacer = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        label_4 = new QLabel(Cryptoverter);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEditPrivateKey = new QLineEdit(Cryptoverter);
        lineEditPrivateKey->setObjectName(QString::fromUtf8("lineEditPrivateKey"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditPrivateKey->sizePolicy().hasHeightForWidth());
        lineEditPrivateKey->setSizePolicy(sizePolicy);
        lineEditPrivateKey->setMinimumSize(QSize(0, 0));
        lineEditPrivateKey->setMaximumSize(QSize(16777215, 22));
        lineEditPrivateKey->setBaseSize(QSize(0, 20));
        lineEditPrivateKey->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEditPrivateKey);

        buttonPrivateKey = new QToolButton(Cryptoverter);
        buttonPrivateKey->setObjectName(QString::fromUtf8("buttonPrivateKey"));
        buttonPrivateKey->setMinimumSize(QSize(24, 24));
        buttonPrivateKey->setMaximumSize(QSize(24, 24));

        horizontalLayout_4->addWidget(buttonPrivateKey);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_3 = new QLabel(Cryptoverter);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        plainTextDataInfo = new QPlainTextEdit(Cryptoverter);
        plainTextDataInfo->setObjectName(QString::fromUtf8("plainTextDataInfo"));
        plainTextDataInfo->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        plainTextDataInfo->setFont(font);
        plainTextDataInfo->setFocusPolicy(Qt::NoFocus);
        plainTextDataInfo->setAcceptDrops(false);
        plainTextDataInfo->setAutoFillBackground(true);
        plainTextDataInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextDataInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextDataInfo->setUndoRedoEnabled(false);
        plainTextDataInfo->setReadOnly(true);
        plainTextDataInfo->setBackgroundVisible(false);

        verticalLayout_2->addWidget(plainTextDataInfo);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_3);

        buttonDirection = new QToolButton(Cryptoverter);
        buttonDirection->setObjectName(QString::fromUtf8("buttonDirection"));
        sizePolicy.setHeightForWidth(buttonDirection->sizePolicy().hasHeightForWidth());
        buttonDirection->setSizePolicy(sizePolicy);
        buttonDirection->setMinimumSize(QSize(0, 90));

        verticalLayout_2->addWidget(buttonDirection);

        buttonConvert = new QToolButton(Cryptoverter);
        buttonConvert->setObjectName(QString::fromUtf8("buttonConvert"));
        sizePolicy.setHeightForWidth(buttonConvert->sizePolicy().hasHeightForWidth());
        buttonConvert->setSizePolicy(sizePolicy);
        buttonConvert->setMinimumSize(QSize(0, 90));

        verticalLayout_2->addWidget(buttonConvert);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Cryptoverter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        buttonClear = new QPushButton(Cryptoverter);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(buttonClear);

        buttonLoadFile = new QPushButton(Cryptoverter);
        buttonLoadFile->setObjectName(QString::fromUtf8("buttonLoadFile"));
        buttonLoadFile->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(buttonLoadFile);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plainTextOutput = new QPlainTextEdit(Cryptoverter);
        plainTextOutput->setObjectName(QString::fromUtf8("plainTextOutput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextOutput->sizePolicy().hasHeightForWidth());
        plainTextOutput->setSizePolicy(sizePolicy1);
        plainTextOutput->setMinimumSize(QSize(350, 0));
        plainTextOutput->setFocusPolicy(Qt::ClickFocus);
        plainTextOutput->setReadOnly(true);

        gridLayout->addWidget(plainTextOutput, 1, 4, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(Cryptoverter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        buttonSaveFile = new QPushButton(Cryptoverter);
        buttonSaveFile->setObjectName(QString::fromUtf8("buttonSaveFile"));
        buttonSaveFile->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(buttonSaveFile);


        gridLayout->addLayout(horizontalLayout_3, 0, 4, 1, 1);

        plainTextInput = new QPlainTextEdit(Cryptoverter);
        plainTextInput->setObjectName(QString::fromUtf8("plainTextInput"));
        plainTextInput->setMinimumSize(QSize(350, 0));

        gridLayout->addWidget(plainTextInput, 1, 0, 1, 1);


        retranslateUi(Cryptoverter);

        QMetaObject::connectSlotsByName(Cryptoverter);
    } // setupUi

    void retranslateUi(QWidget *Cryptoverter)
    {
        Cryptoverter->setWindowTitle(QApplication::translate("Cryptoverter", "Cryptoverter", nullptr));
        label_5->setText(QApplication::translate("Cryptoverter", "Encryption Algorithm", nullptr));
        label_4->setText(QApplication::translate("Cryptoverter", "Private Key", nullptr));
        buttonPrivateKey->setText(QString());
        label_3->setText(QApplication::translate("Cryptoverter", "Input Data Information", nullptr));
        buttonDirection->setText(QApplication::translate("Cryptoverter", "Encrypt", nullptr));
        buttonConvert->setText(QApplication::translate("Cryptoverter", "Convert", nullptr));
        label_2->setText(QApplication::translate("Cryptoverter", "Input:", nullptr));
        buttonClear->setText(QApplication::translate("Cryptoverter", "Clear", nullptr));
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
