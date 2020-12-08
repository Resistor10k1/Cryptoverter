/**
 ****************************************************************
 * @file    Engine.h
 ****************************************************************
 * @brief   This module acts as a base class for multiple algorithms.
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

#ifndef ENGINE_H
#define ENGINE_H

#include <QString>

class Engine
{
  public:
    /**
     ****************************************************************
     * @brief  Constructor
     * @param  n            String with algorythm name
     * @param  key          Specifies if algorythm has private key
     ****************************************************************
     */
    Engine (QString n, bool key): name (n), hasPrivateKey (key) {}

    /**
     ****************************************************************
     * @brief  Sets the private key
     * @param  key          Private Key as a character string
     ****************************************************************
     */
    void setPrivateKey (const QString& key) {privateKey = key;}

    /**
     ****************************************************************
     * @brief  Get size of encrypted data based on input buffer
     * @param  inputSize    Size of input buffer
     * @return outputSize of encrypted data
     ****************************************************************
     */
    virtual int getEncryptedSize (int inputSize) {return inputSize;}

    /**
     ****************************************************************
     * @brief  Get size of decrypted data based on input buffer
     * @param  inputSize    Size of input buffer
     * @return outputSize of decrypted data
     ****************************************************************
     */
    virtual int getDecryptedSize (int inputSize) {return inputSize;}

    /**
     ****************************************************************
     * @brief  Encrypts data from input buffer
     * @param  input        Input buffer
     * @param  output       Output buffer
     * @param  size         Size of input buffer
     * @return conversation result (true if successful)
     ****************************************************************
     */
    virtual bool encrypt (const char* input, char* output, size_t size) = 0;

    /**
     ****************************************************************
     * @brief  Decrypts data from input buffer
     * @param  input        Input buffer
     * @param  output       Output buffer
     * @param  size         Size of input buffer
     * @return conversation result (true if successful)
     ****************************************************************
     */
    virtual bool decrypt (const char* input, char* output, size_t size) = 0;

    QString name;
    QString privateKey;
    const bool hasPrivateKey;
};

#endif // ENGINE_H
