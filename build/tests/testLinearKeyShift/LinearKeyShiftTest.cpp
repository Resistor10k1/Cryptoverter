/*
 * LinearKeyShiftTest.cpp
 *
 *  Created on: Dec 10, 2020
 *      Author: David Schneider
 */

#include <gtest/gtest.h>
#include "LinearKeyShift.h"


//---------------------------------------------------------------------------
TEST(LinearKeyShiftTest, testEncrypt)
{
  char myLetterSend = 'y';
  char myLetterReceive;
  LinearKeyShift lks1;
  lks1.setPrivateKey("ab");
  
  lks1.encrypt(&myLetterSend, &myLetterReceive, 1);
  
  EXPECT_EQ(myLetterReceive, "TODO!!!!!!!");
}


//---------------------------------------------------------------------------
TEST(LinearKeyShiftTest, testDecrypt)
{
  char myLetterSend = 'TODO!!!!!!!!!';
  char myLetterReceive;
  LinearKeyShift lks2;
  
  lks2.setPrivateKey("ab");
  lks2.decrypt(&myLetterSend, &myLetterReceive, 1);
  
  EXPECT_EQ(myLetterReceive, "TODO!!!!!");
}