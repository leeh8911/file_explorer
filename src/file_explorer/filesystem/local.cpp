/*!
 * @file local.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/filesystem/local.h"

#include <filesystem>

#include "file_explorer/filesystem/file.h"

namespace fs = std::filesystem;

namespace file_explorer::domain::filesystem {
IFilePtr LocalFilesystem::ReadLocalFilesystem(
    const std::string& root_path) const {
  if (fs::exists(root_path) == false) {
    throw std::invalid_argument("Invalid path");
  }

  auto root = fs::directory_entry(root_path);

  if (!root.is_directory()) {
    return std::make_shared<File>(root.path().stem().string(),
                                  root.path().extension().string(), nullptr,
                                  root.last_write_time(), root.file_size());
  }
}
}  // namespace file_explorer::domain::filesystem