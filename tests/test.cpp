#include <gtest/gtest.h>

#include "hello.h"

TEST(hello, test_case1)
{
    EXPECT_EQ(0, test());
}