/*!
 * @file local_filesystem.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/usecase/local_filesystem/local_filesystem.h"

#include <filesystem>
#include <iostream>
#include <stack>
#include <string>

#include "file_explorer/entity/filesystem/filesystem.h"

namespace file_explorer::usecase::local_filesystem {

LocalFileSystem ::LocalFileSystem() {
  std::cout << "LocalFileSystem::Creator\n";
  Indexing();
}

entity::filesystem::FileInterfacePtr LocalFileSystem::GetRoot() const {
  return m_root;
}

void LocalFileSystem::Indexing() {
  using fs = std::filesystem;

  // Start from home directory
  auto home = fs::path("/");

  // Create root folder
  m_root = std::make_shared<entity::filesystem::Folder>(home.string());

  // Create stack for DFS
  std::stack<fs::path> stack;

  // Push home directory to stack
  stack.push(home);

  // DFS
  while (!stack.empty()) {
    auto current = stack.top();
    stack.pop();

    // Create file or folder
    auto file = std::make_shared<entity::filesystem::File>(current.string());
    m_root->Add(file);

    // If current is directory, push all children to stack
    if (fs::is_directory(current)) {
      for (const auto& entry : fs::directory_iterator(current)) {
        stack.push(entry.path());
      }
    }
  }
}

}  // namespace file_explorer::usecase::local_filesystem