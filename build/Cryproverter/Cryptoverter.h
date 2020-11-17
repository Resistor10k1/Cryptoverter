#ifndef CRYPTOVERTER_H
#define CRYPTOVERTER_H

#include <QWidget>
#include "Algorithm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Cryptoverter; }
class QLineEdit;
class QPushButton;
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


    Mode mode = MODE_ENCRYPT;

private slots:

    void on_buttonConvert_clicked();
    void on_buttonLoadFile_clicked();
    void on_buttonSaveFile_clicked();
    void on_buttonDirection_clicked();

    void on_comboBoxAlgorithm_currentIndexChanged(int index);

private:
    Ui::Cryptoverter *ui;

    QPushButton* ui_buttonLoadFile;
    QPushButton* ui_buttonSaveFile;
    QPushButton* ui_buttonDirection;
    QPushButton* ui_buttonConvert;
    QTextEdit* ui_textEditInput;
    QTextEdit* ui_textEditOutput;
    QTextEdit* ui_textEditDataInfo;
    QLineEdit* ui_lineEditPrivateKey;
    QComboBox* ui_comboBoxAlgorithm;

    Algorithm algorithm;
};


#endif // CRYPTOVERTER_H
