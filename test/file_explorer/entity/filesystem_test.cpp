/*!
 * @file filesystem_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/filesystem/filesystem.h"

#include <gtest/gtest.h>

namespace file_explorer::entity::filesystem::test {

TEST(FileSystemTest, SampleCase) {
  auto file_a_1 = std::make_shared<File>("file_a_1.txt");
  auto file_a_2 = std::make_shared<File>("file_a_2.txt");

  auto file_b_1 = std::make_shared<File>("file_b_1.txt");
  auto file_b_2 = std::make_shared<File>("file_b_2.txt");
  auto file_b_3 = std::make_shared<File>("file_b_3.txt");

  auto folder_a = std::make_shared<Folder>("folder_a");
  auto folder_b = std::make_shared<Folder>("folder_b");
  auto folder = std::make_shared<Folder>("folder");

  folder_a->Add(file_a_1);
  folder_a->Add(file_a_2);

  folder_b->Add(file_b_1);
  folder_b->Add(file_b_2);
  folder_b->Add(file_b_3);

  folder->Add(folder_a);
  folder->Add(folder_b);

  FolderTreeSearch search;

  {
    auto result = search.Search(folder, "folder_a");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0]->GetName(), "folder_a");
  }

  {
    auto result = search.Search(folder, "file_a_1.txt");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0]->GetName(), "file_a_1.txt");
  }
}
}  // namespace file_explorer::entity::filesystem::test