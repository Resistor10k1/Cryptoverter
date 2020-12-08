/*
* Name: CaesarEncryption.h
* Author: Andri Trottmann
* Date: 07.12.20
*/


#ifndef CAESARENCRYPTION_H
#define CAESARENCRYPTION_H

#include "Engine.h"

class CaesarEncryption : public Engine
{
	public:
	
		///
		///\brief Constructor
		///\param newCharColl New character collection for the encryption. A text can (but don't has to) contain these characters.
		///					  The user of this class must know which characters appear in the text to encrypt.
		///\param length Length of the newCharColl Array.
		///
        CaesarEncryption(const char* newCharColl = nullptr, int length = 0);
		
		///
		///\brief Destructor
		///
		~CaesarEncryption();
		
		///
		///\brief Encrypts the input and writes the encrypted data into the output.
		///\param input The data which has to be encrypted.
		///\param output The enyrypted data
		///\param size The size of the arrays
		///
		bool encrypt(const char* input, char* output, size_t size) override;
		
		///
		///\brief Decrypts the input and writes the decrypted data into the output.
		///\param input The data which has to be decrypted.
		///\param output The deyrypted data
		///\param size The size of the arrays
		///
		bool decrypt(const char* input, char* output, size_t size) override;
		
		
	private:
		char* pCharColl;
		int charCollLength;
		
		char stdCharColl[53] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
		int stdCharCollSize = 53;
	
		///
		///\brief This function calculates the shift of the character in the alphabet.
		///\param index The index of the character which is shifted.
		///
		int getShift(int index);
};

#endif // CAESARENCRYPTION_H
