#ifndef TST_TESTENCRYPTION_H
#define TST_TESTENCRYPTION_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "CaesarEncryption.h"

using namespace testing;

TEST(CaesarEncryptionTest, testEncryption)
{
    CaesarEncryption ce;
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_TESTENCRYPTION_H
