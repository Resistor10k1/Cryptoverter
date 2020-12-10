/**
 ****************************************************************
 * @file    CaesarEncryption.h
 ****************************************************************
 * @brief   This module performs the Caesar encryption. Inherits
 *          from Engine.h
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


#ifndef CAESARENCRYPTION_H
#define CAESARENCRYPTION_H

#include "Engine.h"

class CaesarEncryption : public Engine
{
	public:
    /**
     ****************************************************************
     * @brief  Constructor
     * @param  newCharColl  New character collection for the encryption.
     *                      A text can (but don't has to) contain these characters.
     *                      The user of this class must know which characters
     *                      appear in the text to encrypt.
     * @param  length       Length of the newCharColl Array.
     ****************************************************************
     */
    CaesarEncryption(const char* newCharColl = nullptr, int length = 0);
		
    /**
     ****************************************************************
     * @brief  Destructor
     ****************************************************************
     */
		~CaesarEncryption();
		
    /**
     ****************************************************************
     * @brief  Encrypts the input and writes the encrypted data into the output.
     * @param  input    The data which has to be encrypted.
     * @param  output   The enyrypted data
     * @param  size     The size of the arrays
     * @return          true if successful, false if failed
     ****************************************************************
     */
		bool encrypt(const char* input, char* output, size_t size) override;
		
    /**
     ****************************************************************
     * @brief  Decrypts the input and writes the decrypted data into the output.
     * @param  input    The data which has to be decrypted.
     * @param  output   The deyrypted data
     * @param  size     The size of the arrays
     * @return          true if successful, false if failed
     ****************************************************************
     */
		bool decrypt(const char* input, char* output, size_t size) override;


	private:
		char* pCharColl;
		int pCharCollSize;
	
    /**
     ****************************************************************
     * @brief  This function calculates the shift of the character in the alphabet.
     * @param  character    Character from the character collection.
     * @param  index        The index of the character which is shifted.
     * @param  mode         true for encryption mode, false for decryption mode
     * @return              New index for the character
     ****************************************************************
     */
		int getShift(int character, int index, bool mode) const;
};

#endif // CAESARENCRYPTION_H
