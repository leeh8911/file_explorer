/*!
 * @file local_filesystem.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_USECASE_LOCAL_FILESYSTEM_LOCAL_FILESYSTEM_H_
#define SRC_FILE_EXPLORER_USECASE_LOCAL_FILESYSTEM_LOCAL_FILESYSTEM_H_

#include "file_explorer/entity/filesystem/filesystem.h"

namespace file_explorer::usecase::local_filesystem {

class LocalFileSystem {
 public:
  LocalFileSystem();

  entity::filesystem::FileInterfacePtr GetRoot() const;

 private:
  void Indexing();

  entity::filesystem::FileInterfacePtr m_root{};
};
}  // namespace file_explorer::usecase::local_filesystem

#endif  // SRC_FILE_EXPLORER_USECASE_LOCAL_FILESYSTEM_LOCAL_FILESYSTEM_H_
