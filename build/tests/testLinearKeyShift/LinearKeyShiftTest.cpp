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
  int myIntReceive;
  LinearKeyShift lks1;
  lks1.setPrivateKey("hsrost");
  
  lks1.encrypt(&myLetterSend, &myIntReceive, 1);
  
  EXPECT_EQ(myIntReceive, 17);
}


//---------------------------------------------------------------------------
TEST(LinearKeyShiftTest, testDecrypt)
{
  char myLetterSend = 'c';
  char myLetterReceive;
  LinearKeyShift lks2;
  
  lks2.setPrivateKey("hsrost");
  lks2.decrypt(&myLetterSend, &myLetterReceive, 1);
  
  EXPECT_EQ(myLetterReceive, "TODO!!!!!");
}