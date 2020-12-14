/**
 ****************************************************************
 * @file    Algorithm.cpp
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

#include "Algorithm.h"

Algorithm::Algorithm (void)
{
}

void Algorithm::setType (int index)
{
  if (index < 0 || index >= typeCount) return;
  selectedAlgorithm = index;
}

QString Algorithm::getName (void)
{
  return engine [selectedAlgorithm]->name;
}

QStringList Algorithm::getNameList (void)
{
  QStringList nameList;
  for (int i = 0; i < typeCount; i++)
  {
    nameList.append (engine [i]->name);
  }
  return nameList;
}

bool Algorithm::hasPrivateKey (void)
{
  return engine [selectedAlgorithm]->hasPrivateKey;
}

void Algorithm::setPrivateKey (const QString& key)
{
  engine [selectedAlgorithm]->setPrivateKey(key);
}

void Algorithm::load (void)
{
  inputBuffer.clear ();
  outputBuffer.clear ();
}

void Algorithm::load (const QString& input)
{
  inputBuffer.clear ();
  inputBuffer = input.toUtf8 ();
}

void Algorithm::load (QFile& input)
{
  inputBuffer.clear ();
  inputBuffer = input.readAll ();
}

void Algorithm::save (QFile& output)
{
  output.write (outputBuffer);
}

void Algorithm::copyOutputToInput (void)
{
  inputBuffer.resize (outputBuffer.size ());
  inputBuffer = outputBuffer;
}

bool Algorithm::isPrintable (BufferType type)
{
  QByteArray& array = (type == INPUT) ? inputBuffer : outputBuffer;
  for (int i = 0; i < array.size (); i++)
  {
    QChar c = array.at (i);
    if (c.isNull ()) return true;
    if (!c.isSpace () && (c.isNonCharacter () || !c.isPrint ())) return false;
    if (c.toLatin1() == 0) return false;
  }
  return true;
}

QString Algorithm::showContent (BufferType type)
{
  QByteArray limited = (type == INPUT) ? inputBuffer : outputBuffer;
  limited.resize (displayContentLimit);
  return QString::fromUtf8(limited);
}

QByteArray& Algorithm::getContent (BufferType type)
{
  return (type == INPUT) ? inputBuffer : outputBuffer;
}

bool Algorithm::convert (ConversationType type)
{
  if (type == DECRYPT)
  {
    outputBuffer.resize (engine [selectedAlgorithm]->getDecryptedSize (inputBuffer.size ()));
    memset (outputBuffer.data (), 0, outputBuffer.size ());
    return engine [selectedAlgorithm]->decrypt(inputBuffer.constData (), outputBuffer.data (), inputBuffer.size ());
  }
  else
  {
    outputBuffer.resize (engine [selectedAlgorithm]->getEncryptedSize (inputBuffer.size ()));
    memset (outputBuffer.data (), 0, outputBuffer.size ());
    return engine [selectedAlgorithm]->encrypt(inputBuffer.constData (), outputBuffer.data (), inputBuffer.size ());
  }
}
