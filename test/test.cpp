#include <limits.h>
#include <gtest/gtest.h>
#include "header.h"

namespace{
  TEST(FactorialTest, Negative) { 
    EXPECT_EQ(1, main(1)); 
    EXPECT_EQ(-1, main(-1));
  }
}
