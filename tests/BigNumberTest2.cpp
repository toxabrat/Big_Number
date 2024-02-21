#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, comparisonisless) {
    ASSERT_EQ(BigNumber("32434324343243424.2343284939248324938249324") < BigNumber("343247243982453295487954783.5473915875894378954357438"), 1);
}
