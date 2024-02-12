/*!
 * @file database_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/database.h"

#include <gtest/gtest.h>

namespace file_explorer::entity {
TEST(DatabaseTest, SampleCase) {
  auto &db = Database::GetInstance();

  db.LoadDb("");
  EXPECT_TRUE(db.IsLoaded());
}
}  // namespace file_explorer::entity