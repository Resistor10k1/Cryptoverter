/**
 ****************************************************************
 * @file    Algorithm.h
 ****************************************************************
 * @brief   This module handles diffrent types of algorithms.
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

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QFile>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "algorithms/Engine.h"
#include "algorithms/LinearKeyShift.h"
#include "algorithms/SimpleDemo.h"
#include "algorithms/CaesarEncryption.h"
#include "algorithms/AES.h"

typedef enum {INPUT, OUTPUT} BufferType;
typedef enum {DECRYPT, ENCRYPT} ConversationType;

class Algorithm
{
  public:
    /**
     ****************************************************************
     * @brief  Constructor
     ****************************************************************
     */
    Algorithm (void);

    /**
     ****************************************************************
     * @brief  Selects a specific algorithm by its numeric index
     * @param  index        Integer value
     ****************************************************************
     */
    void setType (int index = 0);

    /**
     ****************************************************************
     * @brief  Returns the name of the selected algorithm
     * @return Name
     ****************************************************************
     */
    QString getName (void);

    /**
     ****************************************************************
     * @brief  Returns a list of names of all algorithms
     * @return Namelist
     ****************************************************************
     */
    QStringList getNameList (void);

    /**
     ****************************************************************
     * @brief  Checks if currently active algorithm has a private key
     * @return hasKey
     ****************************************************************
     */
    bool hasPrivateKey (void);

    /**
     ****************************************************************
     * @brief  Sets the private key
     * @param  key          Password as a string
     ****************************************************************
     */
    void setPrivateKey (const QString& key);

    /**
     ****************************************************************
     * @brief  Loads empty data into buffers (cleares them)
     ****************************************************************
     */
    void load (void);

    /**
     ****************************************************************
     * @brief  Loads a string into input buffer (text import)
     * @param  input        Input as a string
     ****************************************************************
     */
    void load (const QString& input);

    /**
     ****************************************************************
     * @brief  Loads a file into input buffer (file import)
     * @param  input        Input as a binary file
     ****************************************************************
     */
    void load (QFile& input);

    /**
     ****************************************************************
     * @brief  Saves a file from output buffer (file export)
     * @param  output       Output as a binary file
     ****************************************************************
     */
    void save (QFile& output);

    /**
     ****************************************************************
     * @brief  Copys the output buffer to the input buffer
     ****************************************************************
     */
    void copyOutputToInput (void);

    /**
     ****************************************************************
     * @brief  Shows if selected buffer has pintable characters
     * @param  type        Selected Buffer
     * @return isPrintable
     ****************************************************************
     */
    bool isPrintable (BufferType type);

    /**
     ****************************************************************
     * @brief  Prepare selected buffer to print its content
     * @param  type        Selected Buffer
     * @return string to display
     ****************************************************************
     */
    QString showContent (BufferType type);

    /**
     ****************************************************************
     * @brief  Get access to selected buffer for data inspection
     * @param  type        Selected Buffer
     * @return array reference
     ****************************************************************
     */
    QByteArray& getContent (BufferType type);

    /**
     ****************************************************************
     * @brief  Starts encryption or decryption
     * @param  type        Selected conversation type
     * @return true if conversation was successful
     ****************************************************************
     */
    bool convert (ConversationType type);

  private:
    static const int typeCount = 6;                   // Set here total algorithm count and add them in following array
    Engine* engine [typeCount] = {new AES(128),
                                  new AES(192),
                                  new AES(256),
                                  new CaesarEncryption(),
                                  new LinearKeyShift(),
                                  new SimpleDemo()};

    int selectedAlgorithm = 0;
    QByteArray inputBuffer, outputBuffer;
    const size_t displayContentLimit = 10000;         // Max number of characters printed in text fields
};

#endif // ALGORITHM_H
