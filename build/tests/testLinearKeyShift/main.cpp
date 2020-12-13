/*
 * main.cpp
 *
 *  Created on: Dec 9, 2020
 *      Author: Andri Trottmann
 */

#include <iostream>
#include "CaesarEncryption.h"

using namespace std;

int main()
{
  char cryptoText[256] = {'0'};
  char text[256] = {'0'};

  int textSize = 256;
  char testText[256] = {0};

  int counter = 0x00;

  for(int i=0; i<textSize; ++i)
  {
    //if(counter > 0x7E) counter = 0x20;
    testText[i] = counter;
    ++counter;
  }

  if(testText[0] == 0x00)
  {
    cout << "Original text: Not printable" << endl;
  }
  else
  {
    cout << "Original text: " << testText << endl;
  }

  CaesarEncryption converter;

  converter.encrypt(testText, cryptoText, textSize);

  if(cryptoText[0] == 0x00)
  {
    cout << "Encrypted text: Not printable" << endl;
  }
  else
  {
    cout << "Encrypted text: " << cryptoText << endl;
  }

  converter.decrypt(cryptoText, text, textSize);
  if(text[0] == 0x00)
  {
    cout << "Decrypted text: Not printable" << endl;
  }
  else
  {
    cout << "Decrypted text: " << text << endl;
  }


  // Check if easy encryption correct
  counter = 1;
  for(int i=0; i<textSize; ++i)
  {
    if(text[i] != testText[i])
    {
      counter = 0;
    }
  }

  if(counter == 1)
  {
    cout << "Encryption and decryption successful!!" << endl;
  }
  else
  {
    cout << "Encryption and decryption failed!!" << endl;
  }

  return 0;
}

