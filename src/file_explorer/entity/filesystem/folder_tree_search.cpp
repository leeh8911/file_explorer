/*!
 * @file folder_tree_search.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/filesystem/folder_tree_search.h"

#include <queue>
#include <stack>

namespace file_explorer::entity::filesystem {

std::vector<FileInterfacePtr> FolderTreeSearch::Search(
    FileInterfacePtr root, const std::string& target) const {
  std::vector<FileInterfacePtr> result;

  std::queue<FileInterfacePtr> q;

  q.push(root);

  while (!q.empty()) {
    auto current = q.front();
    q.pop();

    if (current->GetName() == target) {
      result.push_back(current);
    }

    if (current->IsDirectory()) {
      auto folder = std::dynamic_pointer_cast<Folder>(current);
      for (const auto& child : folder->GetChildren()) {
        q.push(child);
      }
    }

    if (current->GetParent()) {
      q.push(current->GetParent());
    }
  }

  return result;
}
}  // namespace file_explorer::entity::filesystem