/*
* Name: CaesarEncryption.h
* Author: Andri Trottmann
* Date: 26.11.20
*/


#ifndef CAESARENCRYPTION_H
#define CAESARENCRYPTION_H

class CaesarEncryption
{
	public:
		CaesarEncryption(const char* newCharSet = null, int length = 0);
		/*
		* Constructor
		* param:
		*	newCharSet: Neue Zeichen-Sammlung für die Verschlüsselung
		*	length: Länge des newCharSet-Arrays
		*/
		
		~CaesarEncryption();
		/*
		* Destructor
		* param: none
		*/
		
		
		
	private:
	char* charSet;
};

#endif // CAESARENCRYPTION_H