#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, addition1) {
    ASSERT_EQ(BigNumber("-112300004292192000234.2343284939248324938249324") + BigNumber("-9843294234023040120.2343284939248324938249324"),
                              BigNumber("-122143298526215040354.4686569878496649876498648"));
}

TEST(BigNumberTest, addition3) {
    ASSERT_EQ(BigNumber("101010101010.101010101") + BigNumber("10101010101.01010101"),
                              BigNumber("111111111111.111111111"));
}

TEST(BigNumberTest, addition4) {
    ASSERT_EQ(BigNumber("1") + BigNumber("2"), BigNumber("3"));
}

