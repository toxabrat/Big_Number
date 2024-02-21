#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, difference1) {
    ASSERT_EQ(BigNumber("11230000429213209590834920903290438992000234.20000002342342304023424938249324") - BigNumber("9843294234023040120.2343284939248324938249324"),
                              BigNumber("11230000429213209590834911059996204968960113.96567152949859054640931698249324"));
}

TEST(BigNumberTest, difference2) {
    ASSERT_EQ(BigNumber("-1") - BigNumber("-0.000000001"),
                              BigNumber("-0.999999999"));
}

TEST(BigNumberTest, difference3) {
    ASSERT_EQ(BigNumber("7.01") - BigNumber("-3"),
                              BigNumber("10.01"));
}