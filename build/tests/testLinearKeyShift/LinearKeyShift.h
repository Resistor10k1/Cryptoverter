/**
 ****************************************************************
 * @file    LinearKeyShift.h
 ****************************************************************
 * @brief   This module implements a simple key shift algorithm.
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

#ifndef LINEARKEYSHIFT_H
#define LINEARKEYSHIFT_H

#include <QString>
#include <QChar>
#include "Engine.h"

class LinearKeyShift : public Engine
{
  public:
    /**
     ****************************************************************
     * @brief  Constructor
     ****************************************************************
     */
    LinearKeyShift (void) : Engine ("LinearKeyShift", true) {}

    /**
     ****************************************************************
     * @brief  Performs a simple linear character shift encryption
     * @param  input        Input buffer
     * @param  output       Output buffer
     * @param  size         Size of input buffer
     * @return conversation result (true if successful)
     ****************************************************************
     */
    bool encrypt (const char* input, char* output, size_t size)
    {
      for (size_t i = 0; i < size; i++)
      {
        char character = input [i];
        if (character >= 'A' && character <= 'Z')
        {
          character += getKeyShift (privateKey);
          if (character < 'A' || character > 'Z') character -= 26;
        }
        if (character >= 'a' && character <= 'z')
        {
          character += getKeyShift (privateKey);
          if (character < 'a' || character > 'z') character -= 26;
        }
        output[i] = character;
      }
      return true; // Success
    }

    /**
     ****************************************************************
     * @brief  Performs a simple linear character shift decryption
     * @param  input        Input buffer
     * @param  output       Output buffer
     * @param  size         Size of input buffer
     * @return conversation result (true if successful)
     ****************************************************************
     */
    bool decrypt (const char* input, char* output, size_t size)
    {
      for (size_t i = 0; i < size; i++)
      {
        char character = input [i];
        if (character >= 'A' && character <= 'Z')
        {
          character -= getKeyShift (privateKey);
          if (character < 'A' || character > 'Z') character += 26;
        }
        if (character >= 'a' && character <= 'z')
        {
          character -= getKeyShift (privateKey);
          if (character < 'a' || character > 'z') character += 26;
        }
        output[i] = character;
      }
      return true; // Success
    }

private:
  /**
   ****************************************************************
   * @brief  Returns character shift value based on private key
   * @param  key          Private Key
   * @return character shift value
   ****************************************************************
   */
  int getKeyShift (const QString& key)
  {
    int shift = 0;
    for (int i = 0; i < key.length (); i++)
    {
      QChar qchar (key [i]);
      shift += qchar.toLatin1() * (i + 1) * (i + 1);
    }
    return shift % 26;
  }
};

#endif // LINEARKEYSHIFT_H
