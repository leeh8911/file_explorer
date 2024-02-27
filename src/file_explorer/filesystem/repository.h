/*!
 * @file repository.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_FILESYSTEM_REPOSITORY_H_
#define SRC_FILE_EXPLORER_FILESYSTEM_REPOSITORY_H_

#include <fstream>
#include <string>

#include "file_explorer/filesystem/file.h"

namespace file_explorer::domain::filesystem {

class Repository {
 public:
  Repository(const std::string& db) = default;

  void Update(const IFilePtr& file) const;
  void Query(const std::string& name) const;

 private:
};

}  // namespace file_explorer::domain::filesystem

#endif  // SRC_FILE_EXPLORER_FILESYSTEM_REPOSITORY_H_
