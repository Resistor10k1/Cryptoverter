#ifndef CRYPTOVERTER_H
#define CRYPTOVERTER_H

#include <QWidget>
#include "Algorithm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Cryptoverter; }
class QLineEdit;
class QPushButton;
class QToolButton;
class QTextEdit;
class QComboBox;
QT_END_NAMESPACE


typedef enum {MODE_ENCRYPT, MODE_DECRYPT} Mode;


class Cryptoverter : public QWidget
{
    Q_OBJECT

public:
    explicit Cryptoverter(QWidget *parent = nullptr);
    ~Cryptoverter ();

private slots:

    void on_buttonConvert_clicked();
    void on_buttonLoadFile_clicked();
    void on_buttonSaveFile_clicked();
    void on_buttonDirection_clicked();
    void on_comboBoxAlgorithm_currentIndexChanged(int index);
    void on_plainTextInput_textChanged();
    void on_buttonPrivateKey_clicked();

private:
    Ui::Cryptoverter *ui;
    Algorithm algorithm;

    Mode mode = MODE_ENCRYPT;

    void showTextInfo (QString input = "");
};

#endif // CRYPTOVERTER_H
