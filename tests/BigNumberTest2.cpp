#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, comparisonisless1) {
    ASSERT_EQ(BigNumber("32434324343243424.2343284939248324938249324") < BigNumber("343247243982453295487954783.5473915875894378954357438"), 1);
}

TEST(BigNumberTest, comparisonisless2) {
    ASSERT_EQ(BigNumber("20.00000001") > BigNumber("20.1"), 0);
}

TEST(BigNumberTest, comparisonisless3) {
    ASSERT_EQ(BigNumber("21302.00000211") < BigNumber("21302.00000211"), 0);
}

TEST(BigNumberTest, comparisonisless4) {
    ASSERT_EQ(BigNumber("21302.00000211") < BigNumber("21302.00000212"), 1);
}