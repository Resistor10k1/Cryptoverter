/**
 ****************************************************************
 * @file    CaesarEncryption.cpp
 ****************************************************************
 * @brief   This module implements the functions declared in CaesarEncryption.h
 ****************************************************************
 * @author  Andri Trottmann
 * @version 1.0
 * @date    2020-12-10
 ****************************************************************
 * @copyright
 * MIT License
 *
 * Copyright (c) 2020 Andri Trottmann
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


#include "CaesarEncryption.h"

CaesarEncryption::CaesarEncryption(const char* newCharColl, int length)
                                : Engine ("Caesar Encryption", false)
{
  name = "Caesar Encryption (Default)";
  if(newCharColl != nullptr)
	{	
        name = "Caesar Encryption (Custom Character Collection)";
		pCharColl = new char[length];
		for(int i=0; i<length; ++i)
		{
			pCharColl[i] = newCharColl[i];
		}
		
		pCharCollSize = length;
	}
	else
	{
		pCharCollSize = 256;
		pCharColl = new char[pCharCollSize];

		for(int i=0; i<pCharCollSize; ++i)
		{
		  pCharColl[i] = i;
		}
	}
}
	
CaesarEncryption::~CaesarEncryption()
{
  delete[] pCharColl;
}


bool CaesarEncryption::encrypt(const char* input, char* output, size_t size)
{
  // For each element i in input...
  for(int i=0; i<size; ++i)
  {
    // For each element e in pCharColl...
    for(int e=0; e<pCharCollSize; ++e)
    {
      // If character matches
      if(pCharColl[e] == input[i])
      {
        output[i] = pCharColl[getShift(pCharColl[e], i, true)];
        break;
      }
    }
  }
	
	return true;
}

bool CaesarEncryption::decrypt(const char* input, char* output, size_t size)
{
  // For each element i in input...
  for(int i=0; i<size; ++i)
  {
    // For each element e in pCharColl...
    for(int e=0; e<pCharCollSize; ++e)
    {
      // If character matches
      if(pCharColl[e] == input[i])
      {
        output[i] = pCharColl[getShift(pCharColl[e], i, false)];
        break;
      }
    }
  }

	return true;
}


int CaesarEncryption::getShift(int character, int index, bool mode) const
{
  int shift = 0;

  if(mode == true) // Encrypt shift
  {
    shift = character + index;

    while(shift > (pCharCollSize-1))
    {
      shift -= pCharCollSize;
    }
  }
  else // Decrypt shift
  {
    shift = character - index;

    while(shift < 0)
    {
      shift += pCharCollSize;
    }
  }

	return shift;
}
