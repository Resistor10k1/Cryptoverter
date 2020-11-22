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
  showDataInfo ();

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
    fileLoading = true;                     // Ignore slot "textChanged" from next line
    if (algorithm.isPrintable (INPUT))      // If content is not printable, dissable text editor
    {
      ui->plainTextInput->setEnabled (true);
      ui->plainTextInput->setPlainText(algorithm.showContent (INPUT));
    }
    else
    {
      ui->plainTextInput->setEnabled (false);
      ui->plainTextInput->clear ();
    }
    showDataInfo (algorithm.getContent (INPUT), algorithm.isPrintable (INPUT));
  }
}

void Cryptoverter::on_buttonSaveFile_clicked()
{
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), inputFileName);
  if (!fileName.isEmpty())
  {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::information(this, tr("Unable to open file"), file.errorString());
      return;
    }
    algorithm.save (file);
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
  algorithm.convert ((mode == MODE_DECRYPT) ? DECRYPT : ENCRYPT);

  ui->plainTextOutput->clear ();
  if (algorithm.isPrintable (OUTPUT))      // If content is not printable, dissable output text editor
  {
    ui->plainTextOutput->setEnabled (true);
    ui->plainTextOutput->setPlainText(algorithm.showContent (OUTPUT));
  }
  else
  {
    ui->plainTextOutput->setEnabled (false);
  }
}

void Cryptoverter::on_comboBoxAlgorithm_currentIndexChanged(int index)
{
  algorithm.setType(index);
  if (algorithm.hasPrivateKey())          // Check if new selected algorithms has private key
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
  ui->plainTextOutput->clear();           // Clear the output window if the algorithm has changed
}

void Cryptoverter::on_plainTextInput_textChanged()
{
  if (fileLoading)
  {
    fileLoading = false;
    return;
  }
  algorithm.load (ui->plainTextInput->toPlainText());
  showDataInfo (algorithm.getContent (INPUT), algorithm.isPrintable (INPUT));
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

void Cryptoverter::on_buttonClear_clicked()
{
  algorithm.load ();
  ui->plainTextInput->clear ();
  ui->plainTextOutput->clear ();
  ui->plainTextInput->setEnabled (true);
  ui->plainTextOutput->setEnabled (true);
}

void Cryptoverter::showDataInfo (const QByteArray& data, bool printable)
{
  QString info;
  info += QString("Total Size:          %1\n").arg (data.size());
  info += QString("Regular Characters:  %1\n").arg (printable ? QString::number(QString::fromUtf8(data).count (QRegExp ("[^\\s]"))) : "-");
  info += QString("Control Characters:  %1\n").arg (printable ? QString::number(QString::fromUtf8(data).count (QRegExp ("[\\s]"))) : "-");
  info += QString("Lines:               %1\n").arg (printable ? QString::number(QString::fromUtf8(data).count ("\n")) : "-");
  // Maybe add some more? Any ideas?

  ui->plainTextDataInfo->setPlainText(info);
}
