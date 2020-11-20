#include "ui_Cryptoverter.h"
#include "Cryptoverter.h"
#include "Algorithm.h"

#include <QFile>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QToolButton>
#include <QTextEdit>
#include <QTextStream>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Cryptoverter::Cryptoverter(QWidget *parent) : QWidget(parent), ui(new Ui::Cryptoverter)
{
  ui->setupUi(this);

  ui->comboBoxAlgorithm->clear();
  ui->comboBoxAlgorithm->addItems(algorithm.getNameList());

  ui->buttonConvert->setIcon(QIcon("graphics/icon_convert.svg"));
  ui->buttonConvert->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  ui->buttonConvert->setIconSize(QSize(80, 50));

  ui->buttonDirection->setIcon(QIcon("graphics/icon_encrypt.svg"));
  ui->buttonDirection->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  ui->buttonDirection->setIconSize(QSize(80, 50));

  ui->buttonPrivateKey->setIcon(QIcon("graphics/icon_show.svg"));
  ui->buttonPrivateKey->setIconSize(QSize(16, 16));

  ui->plainTextDataInfo->setStyleSheet("background-color: #F0F0F0"); // Set background color to light gray
  showTextInfo ();

  //QTextStream(stdout) << "GUI Start" << endl;
}

Cryptoverter::~Cryptoverter ()
{
  delete ui;
}


void Cryptoverter::on_buttonLoadFile_clicked()
{
  inputFileName = QFileDialog::getOpenFileName(this);
  if (!inputFileName.isEmpty())
  {
    QFile file(inputFileName);
    if (!file.open(QIODevice::ReadOnly))
    {
      QMessageBox::information(this, tr("Unable to open file"),
      file.errorString());
      return;
    }
    algorithm.load (file);
    fileLoading = true;       // Ignore slot "textChanged" from next line
    ui->plainTextInput->setPlainText(algorithm.showContent (INPUT));
    // update data info
  }
}

void Cryptoverter::on_buttonSaveFile_clicked()
{
  QString inputFileNameEnc = inputFileName;
  //inputFileNameEnc.insert(inputFileNameEnc.lastIndexOf ('.'), "_enc");
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), inputFileNameEnc);
  if (!fileName.isEmpty())
  {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::information(this, tr("Unable to open file"), file.errorString());
      return;
    }
    algorithm.save (file);
    //file.write(ui->plainTextOutput->toPlainText().toUtf8());
  }
}

void Cryptoverter::on_buttonDirection_clicked()
{
  if (mode == MODE_ENCRYPT)
  {
    mode = MODE_DECRYPT;
    ui->buttonDirection->setText("Decrypt");
    ui->buttonDirection->setIcon(QIcon("graphics/icon_decrypt.svg"));
  }
  else
  {
    mode = MODE_ENCRYPT;
    ui->buttonDirection->setText("Encrypt");
    ui->buttonDirection->setIcon(QIcon("graphics/icon_encrypt.svg"));
  }
}

void Cryptoverter::on_buttonConvert_clicked()
{
  QString input = ui->plainTextInput->toPlainText();
  algorithm.setPrivateKey (ui->lineEditPrivateKey->text());
  QString output;
  if (mode == MODE_DECRYPT)
  {
    algorithm.decrypt();
  }
  else
  {
    algorithm.encrypt();
  }

  ui->plainTextOutput->clear();
  ui->plainTextOutput->setPlainText(algorithm.showContent (OUTPUT));
}

void Cryptoverter::on_comboBoxAlgorithm_currentIndexChanged(int index)
{
  algorithm.setType(index);
  if (algorithm.hasPrivateKey())        // Check if new selected algorithms has private key
  {
    ui->lineEditPrivateKey->setEnabled(true);
    ui->buttonPrivateKey->setEnabled(true);
  }
  else
  {
    ui->lineEditPrivateKey->clear();
    ui->lineEditPrivateKey->setEnabled(false);
    ui->buttonPrivateKey->setEnabled(false);
  }
  ui->plainTextOutput->clear();         // Clear the output window if the algorithm has changed
}

void Cryptoverter::on_plainTextInput_textChanged()
{
  if (fileLoading)
  {
    fileLoading = false;
    return;
  }
  algorithm.load (ui->plainTextInput->toPlainText());
  // update data info
}

void Cryptoverter::showTextInfo (QString input)
{
  QString info;
  info += QString("Symbols:     %1\n").arg (input.length () - input.count ("\n"));
  info += QString("Characters:  %1\n").arg (input.length ());
  info += QString("Lines:       %1\n").arg (input.count ("\n"));
  // @TODO: add more counts
  ui->plainTextDataInfo->setPlainText(info);
}

void Cryptoverter::on_buttonPrivateKey_clicked()
{
  static bool showPrivateKey = false;
  showPrivateKey = !showPrivateKey;
  if (showPrivateKey)
  {
    ui->buttonPrivateKey->setIcon(QIcon("graphics/icon_hide.svg"));
    ui->lineEditPrivateKey->setEchoMode(QLineEdit::Normal);
  }
  else
  {
    ui->buttonPrivateKey->setIcon(QIcon("graphics/icon_show.svg"));
    ui->lineEditPrivateKey->setEchoMode(QLineEdit::Password);
  }
}
