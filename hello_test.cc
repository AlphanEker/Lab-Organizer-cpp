#include <gtest/gtest.h>
#include "Cabinet.h"
#include <stdlib.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  Cabinet a = Cabinet(1,5,5);
  
  for (int i = 0; i < 26; i++)
  {
    EXPECT_EQ(a.plusCount(), i);
  }
  
  // Expect equality.
  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << RUN_ALL_TESTS();
  return 0;
}
