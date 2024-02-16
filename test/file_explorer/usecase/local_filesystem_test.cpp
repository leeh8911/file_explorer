/*!
 * @file local_filesystem_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/usecase/local_filesystem/local_filesystem.h"

#include <gtest/gtest.h>

#include <iostream>

namespace file_explorer::usecase::local_filesystem::test {

TEST(LocalFileSystemTest, SampleCase) {
  std::cout << "Start LocalFileSystemTest\n";
  LocalFileSystem lfs{};

  EXPECT_NE(lfs.GetRoot(), nullptr);
  std::cout << "End LocalFileSystemTest\n";
}
}  // namespace file_explorer::usecase::local_filesystem::test
