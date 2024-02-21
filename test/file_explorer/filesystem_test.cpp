/*!
 * @file filesystem_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <gtest/gtest.h>

#include "file_explorer/filesystem/file.h"
#include "file_explorer/filesystem/local.h"

namespace file_explorer::domain::filesystem::test {
TEST(FileSystemTest, CreateFile) {
  auto file = std::make_shared<File>("test", "txt", nullptr,
                                     std::chrono::file_clock::now(), 100);
  EXPECT_EQ(file->Name(), "test");
  EXPECT_EQ(file->Extension(), "txt");
  EXPECT_EQ(file->Size(), 100);
  EXPECT_EQ(file->IsFile(), true);
}

TEST(FileSystemTest, LocalFileSampleCase) {
  LocalFilesystem fs;
  auto result = fs.ReadLocalFilesystem(
      "D:/sangwon/repositories/workspace/file_explorer/README.md");

  auto file = std::dynamic_pointer_cast<File>(result);

  EXPECT_EQ(file->Name(), "README");
  EXPECT_EQ(file->Extension(), ".md");
}
}  // namespace file_explorer::domain::filesystem::test