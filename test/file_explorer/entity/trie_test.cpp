/*!
 * @file trie_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/trie.h"

#include <gtest/gtest.h>

namespace file_explorer::entity::test {
TEST(TrieTest, SampleCase) {
  Trie trie;

  trie.Insert("file_name", "root/file/path/file_name.exe");
  trie.Insert("file_name_2", "root/other/path/file_name_2.txt");
  trie.Insert("file_name", "another/root/file/path/file_name.txt");
  trie.Insert("new_file", "root/file/path/new_file.exe");

  auto found_file_name = trie.Search("file_name");

  EXPECT_EQ(found_file_name.size(), 3);

  auto found_file = trie.Search("file");

  EXPECT_EQ(found_file.size(), 4);

  auto found_xxxx = trie.Search("xxxx");
  EXPECT_EQ(found_xxxx.size(), 0);
}
}  // namespace file_explorer::entity::test