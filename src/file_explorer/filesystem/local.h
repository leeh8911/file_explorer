/*!
 * @file local.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_FILESYSTEM_LOCAL_H_
#define SRC_FILE_EXPLORER_FILESYSTEM_LOCAL_H_

#include "file_explorer/filesystem/file.h"

namespace file_explorer::domain::filesystem {
class LocalFilesystem {
 public:
  LocalFilesystem() = default;

  IFilePtr ReadLocalFilesystem(const std::string& path) const;

 private:
  void RecursiveFind(IFilePtr root, const std::string& path) const;
};
}  // namespace file_explorer::domain::filesystem

#endif  // SRC_FILE_EXPLORER_FILESYSTEM_LOCAL_H_
