/*!
 * @file dummy_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/dummy.h"

#include <gtest/gtest.h>

namespace explorer::test {
TEST(DummyTest, Add) { EXPECT_EQ(3, Dummy(1, 2)); }
}  // namespace explorer::test
