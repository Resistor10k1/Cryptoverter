/*
* Name: CaesarEncryption.cpp
* Author: Andri Trottmann
* Date: 26.11.20
*/


#include "CaesarEncryption.h"

CaesarEncryption::CaesarEncryption(const char* newCharSet = null, int length = 0)
{
	if(newCharSet != null)
	{	
		charSet = new char[length];
		for(int i=0; i<length; ++i)
		{
			charSet[i] = newCharSet[i];
		}
	}
}
	
CaesarEncryption::~CaesarEncryption()
{
	delete[] charSet;
}