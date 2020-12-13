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
  lks1.setPrivateKey("hsrost");
  
  lks1.encrypt(&myLetterSend, &myLetterReceive, 1);
  
  EXPECT_EQ(myLetterReceive, 'p');
}


//---------------------------------------------------------------------------
TEST(LinearKeyShiftTest, testDecrypt)
{
  char myLetterSend = 'h';
  char myLetterReceive;
  LinearKeyShift lks2;
  
  lks2.setPrivateKey("hsrost");
  lks2.decrypt(&myLetterSend, &myLetterReceive, 1);
  
  EXPECT_EQ(myLetterReceive, 121);
}