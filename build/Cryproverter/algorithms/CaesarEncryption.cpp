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
	else
	{
		pCharColl = &stdCharColl;
		charCollLength = stdCharCollSize;
	}
}
	
CaesarEncryption::~CaesarEncryption()
{
	delete[] pCharColl;
}


bool CaesarEncryption::encrypt(const char* input, char* output, size_t size)
{
	//memcpy (output, input, size);
	int index = 0;
	
	for(int i=0; i<size; ++i)
	{
		for(int c=0; c<charCollLength; ++c)
		{
			if(pCharColl[c] == input[c])
			{
				index = c;
				break;
			}
		}
		
		output[i] = pCharColl[getShift(index)];
	}
	
	
	return true;
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
