/*
 * LinearKeyShiftTest.cpp
 *
 *  Created on: Dec 10, 2020
 *      Author: David Schneider
 */

#include <gtest/gtest.h>
#include "LinearKeyShift.h"


//---------------------------------------------------------------------------
TEST(LinearKeyShiftTest, testLetter_A)
{
  char myLetterSend = 'A';
  char myLetterReceive;
  LinearKeyShift lks1;
  lks1.setPrivateKey("ab");
  
  lks1.encrypt(&myLetterSend, &myLetterReceive, 1);
  
  EXPECT_EQ(myLetterReceive, 0);
}

