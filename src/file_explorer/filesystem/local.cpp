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
#include <memory>
#include <string>
#include <utility>

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
  } else {
    auto folder = std::make_shared<Folder>(root.path().stem().string(), nullptr,
                                           root.last_write_time());

    for (const auto& entry : fs::directory_iterator(root.path())) {
      RecursiveFind(folder, entry.path().string());
    }
    return folder;
  }
}

void LocalFilesystem::RecursiveFind(IFilePtr root,
                                    const std::string& path) const {
  auto current_entry = fs::directory_entry(path);

  if (current_entry.is_directory()) {
    auto folder =
        std::make_shared<Folder>(current_entry.path().filename().string(), root,
                                 current_entry.last_write_time());
    auto parent = dynamic_cast<Folder*>(root.get());
    parent->AddChild(folder);

    for (const auto& entry : fs::directory_iterator(current_entry.path())) {
      RecursiveFind(folder, entry.path().string());
    }
  } else {
    auto file = std::make_shared<File>(
        current_entry.path().stem().string(),
        current_entry.path().extension().string(), root,
        current_entry.last_write_time(), current_entry.file_size());
    auto parent = dynamic_cast<Folder*>(root.get());
    parent->AddChild(file);
  }
}
}  // namespace file_explorer::domain::filesystem
