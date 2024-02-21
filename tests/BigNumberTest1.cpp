#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, translation_to_string1) {
    ASSERT_EQ(BigNumber("-12231234543894395437589734753.328423492349817287381").to_string(), "-12231234543894395437589734753.328423492349817287381");
}

TEST(BigNumberTest, translation_to_string2) {
    ASSERT_EQ(BigNumber("10000000000007589734753.328000423492349817287381").to_string(), "10000000000007589734753.328000423492349817287381");
}

TEST(BigNumberTest, translation_to_string3) {
    ASSERT_EQ(BigNumber("213.12302193").to_string(), "213.12302193");
}