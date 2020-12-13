/*
 * LinearKeyShiftTest.cpp
 *
 *  Created on: Dec 10, 2020
 *      Author: David Schneider
 */

#include <gtest/gtest.h>
#include "LinearKeyShift.h"


/*
 * Hilfsfunktion, nur zum Testen. 
 */
bool equalDates(const MyDate & date, int day, int month, int year)

{
  if (date.getDay(), day)
    return false;
  if (date.getMonth(), month)
    return false;
  if (date.getYear(), year)
    return false;
  return true;
}

//---------------------------------------------------------------------------
TEST(LinearKeyShiftTest, testDefaultCtor)
{
  MyDate d1;
  EXPECT_EQ(d1.getDay(), 0);
  EXPECT_EQ(d1.getMonth(), 0);
  EXPECT_EQ(d1.getYear(), 0);
}






















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

