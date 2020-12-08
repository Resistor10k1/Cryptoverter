/**
 ****************************************************************
 * @file    SimpleDemo.h
 ****************************************************************
 * @brief   This module is an example of how to implement an algorithm.
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

#ifndef SIMPLEDEMO_H
#define SIMPLEDEMO_H

#include <QString>
#include <QChar>
#include "Engine.h"

class SimpleDemo : public Engine
{
  public:
    /**
     ****************************************************************
     * @brief  Constructor
     ****************************************************************
     */
    SimpleDemo (void) : Engine ("SimpleDemo", false) {}

    /**
     ****************************************************************
     * @brief  Copys input buffer to output buffer
     * @param  input        Input buffer
     * @param  output       Output buffer
     * @param  size         Size of input buffer
     * @return conversation result (true if successful)
     ****************************************************************
     */
    bool encrypt (const char* input, char* output, size_t size)
    {
      memcpy (output, input, size);
      return true; // Success
    }

    /**
     ****************************************************************
     * @brief  Copys input buffer to output buffer
     * @param  input        Input buffer
     * @param  output       Output buffer
     * @param  size         Size of input buffer
     * @return conversation result (true if successful)
     ****************************************************************
     */
    bool decrypt (const char* input, char* output, size_t size)
    {
      memcpy (output, input, size);
      return true; // Success
    }
};

#endif // SIMPLEDEMO_H
