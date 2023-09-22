#include <gtest/gtest.h>
#include "../src/hamming_weight.cpp"

TEST(HW_compare, first_test) {
    EXPECT_EQ(hw_sum(1, 8), 13);
}

TEST(HW_compare, second_test) {
    EXPECT_EQ(hw_sum(3, 12), 20);
}

TEST(HW_compare, third_test) {
    EXPECT_EQ(hw_sum(12, 40), 82);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
