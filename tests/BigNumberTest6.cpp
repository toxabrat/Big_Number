#include <gtest/gtest.h>
#include "BigNumber.h"

TEST(BigNumberTest, multiplication1) {
    ASSERT_EQ(BigNumber("11230000423242340009590834920903290438992000234.20000002342342304023424938249324") * BigNumber("-2340324920349032234903249029.234092340929423032324"),
                             BigNumber("-26281849846044227669247176406523359795804789724511943809421585021314940221.02240538290487583672844708461772070213849164023148976"));
}

TEST(BigNumberTest, multiplication2) {
    ASSERT_EQ(BigNumber("1") * BigNumber("0.0000000000000000000000000000000000000001"),
                              BigNumber("0.0000000000000000000000000000000000000001"));
}

TEST(BigNumberTest, multiplication3) {
    ASSERT_EQ(BigNumber("1") * BigNumber("0"), BigNumber("0"));
}

TEST(BigNumberTest, multiplication4) {
    ASSERT_EQ(BigNumber("8") * BigNumber("0.125"), BigNumber("1"));
}

TEST(BigNumberTest, multiplication5) {
    ASSERT_EQ(BigNumber("11") * BigNumber("11"), BigNumber("121"));
}