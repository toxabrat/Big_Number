#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, equality1) {
    ASSERT_EQ((BigNumber("-9832434324343243424.2343284939248324938249324") == BigNumber("-9832434324343243424.2343284939248324938249324")), 1);
}

TEST(BigNumberTest, equality2) {
    ASSERT_EQ((BigNumber("9832434324343243424.2343284939248324938249324") == BigNumber("-9832434324343243424.2343284939248324938249324")), 0);
}

TEST(BigNumberTest, equality3) {
    ASSERT_EQ((BigNumber("9213123.0213") == BigNumber("20130210301")), 0);
}

TEST(BigNumberTest, equality4) {
    ASSERT_EQ((BigNumber("2139.0001") == BigNumber("2139.0001")), 1);
}