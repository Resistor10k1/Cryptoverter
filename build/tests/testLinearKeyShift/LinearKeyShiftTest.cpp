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
  LinearKeyShift lks1;
  char myLetterSend = 'A'
  char myLetterReceive
  
  lks1.encrypt(&myLetterSend, &myLetterReceive, 1)
  EXPECT_EQ(myLetterReceive, 0);
  EXPECT_EQ(d1.getMonth(), 0);
  EXPECT_EQ(d1.getYear(), 0);
}

