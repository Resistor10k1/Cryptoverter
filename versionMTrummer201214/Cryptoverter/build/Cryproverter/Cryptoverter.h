/**
 ****************************************************************
 * @file    Cryptoverter.h
 ****************************************************************
 * @brief   This module implements the main functionality of the application.
 ****************************************************************
 * @author  Florian Baumgartner
 * @version 1.0
 * @date    2020-12-08
 ****************************************************************
 * @copyright
 * MIT License
 *
 * Copyright (c) 2020 Florian Baumgartner
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
class QFileDialog;
QT_END_NAMESPACE


typedef enum {MODE_ENCRYPT, MODE_DECRYPT} Mode;

class Cryptoverter : public QWidget
{
    Q_OBJECT

public:
    /**
     ****************************************************************
     * @brief  Constructor sets up the UI
     * @param  parent       Parent widget of Qt framework
     ****************************************************************
     */
    explicit Cryptoverter(QWidget *parent = nullptr);

    /**
     ****************************************************************
     * @brief  Destructor
     ****************************************************************
     */
    ~Cryptoverter ();

private slots:

    /**
     ****************************************************************
     * @brief  Event Handler: Button Load File (clicked)
     ****************************************************************
     */
    void on_buttonConvert_clicked();

    /**
     ****************************************************************
     * @brief  Event Handler: Button Load File (clicked)
     ****************************************************************
     */
    void on_buttonLoadFile_clicked();

    /**
     ****************************************************************
     * @brief  Event Handler: Button Direction (clicked)
     ****************************************************************
     */
    void on_buttonSaveFile_clicked();

    /**
     ****************************************************************
     * @brief  Event Handler: Button Convert (clicked)
     ****************************************************************
     */
    void on_buttonDirection_clicked();

    /**
     ****************************************************************
     * @brief  Event Handler: Combobox Algorithm Type (index changed)
     ****************************************************************
     */
    void on_comboBoxAlgorithm_currentIndexChanged(int index);

    /**
     ****************************************************************
     * @brief  Event Handler: Text Input (text changed)
     ****************************************************************
     */
    void on_plainTextInput_textChanged();

    /**
     ****************************************************************
     * @brief  Event Handler: Button Private Key (clicked)
     ****************************************************************
     */
    void on_buttonPrivateKey_clicked();

    /**
     ****************************************************************
     * @brief  Event Handler: Button Clear (clicked)
     ****************************************************************
     */
    void on_buttonClear_clicked();

    /**
     ****************************************************************
     * @brief  Event Handler: Button Copy (clicked)
     ****************************************************************
     */
    void on_buttonCopy_clicked();

private:
    /**
     ****************************************************************
     * @brief  Extracts info from given data and displays it
     * @param  data         Input data array
     * @param  printable    Shows if data contains only printable characters
     ****************************************************************
     */
    void showDataInfo (const QByteArray& data = 0, bool printable = true);

    Ui::Cryptoverter *ui;
    Algorithm algorithm;
    Mode mode = MODE_ENCRYPT;
    QString inputFileName;
    bool fileLoading = false;         // This is an ugly solution to prevent overwriting of the inputBuffer after the text has changed on the input text field
};

#endif // CRYPTOVERTER_H
