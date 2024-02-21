#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, difference) {
    ASSERT_EQ(BigNumber("11230000429213209590834920903290438992000234.20000002342342304023424938249324") - BigNumber("9843294234023040120.2343284939248324938249324"),
                              BigNumber("11230000429213209590834911059996204968960113.96567152949859054640931698249324"));
}