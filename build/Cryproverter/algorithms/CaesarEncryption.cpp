/*
* Name: CaesarEncryption.cpp
* Author: Andri Trottmann
* Date: 07.12.20
*/


#include <QString>
#include "CaesarEncryption.h"

CaesarEncryption::CaesarEncryption(const char* newCharColl, int length)
                                : Engine ("Caesar Encryption", false)
{
    name = "Caesar Encryption (Default)";
    if(newCharColl != nullptr)
	{	
        name = "Caesar Encryption (Custom Character Set)";
		pCharColl = new char[length];
		for(int i=0; i<length; ++i)
		{
			pCharColl[i] = newCharColl[i];
		}
		
		charCollLength = length;
	}
}
	
CaesarEncryption::~CaesarEncryption()
{
	delete[] pCharColl;
}


bool CaesarEncryption::encrypt(const char* input, char* output, size_t size)
{
	//memcpy (output, input, size);
	
	for(int i=0; i<size; ++i)
	{
		
	}
	
	
	return false;
}

bool CaesarEncryption::decrypt(const char* input, char* output, size_t size)
{
	memcpy (output, input, size);
	return false;
}


int CaesarEncryption::getShift(int index)
{
	return 0;
}
