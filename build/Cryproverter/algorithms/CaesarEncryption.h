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
		CaesarEncryption(const char* newCharColl, int length);
		
		///
		///\brief Destructor
		///
		~CaesarEncryption();
		
		///
		///\brief
		///\param
		///\param
		///\param
		///
		bool encrypt(const char* input, char* output, size_t size) override;
		
		///
		///\brief
		///\param
		///\param
		///\param
		///
		bool decrypt(const char* input, char* output, size_t size) override;
		
		
	private:
	char* pCharColl;
	int charCollLength;
	//const char charSetStd[26] = {};
};

#endif // CAESARENCRYPTION_H