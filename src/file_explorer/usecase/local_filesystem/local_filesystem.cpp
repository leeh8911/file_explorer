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
  // Start from home directory
  std::string home = std::filesystem::path(getenv("HOME")).string();

  std::cout << "Home directory: " << home << std::endl;
}

}  // namespace file_explorer::usecase::local_filesystem