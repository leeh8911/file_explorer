/*!
 * @file factory.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FACTORY_H_
#define SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FACTORY_H_

#include <memory>

#include "file_explorer/entity/filesystem/file.h"
#include "file_explorer/entity/filesystem/file_interface.h"
#include "file_explorer/entity/filesystem/folder.h"

namespace file_explorer::entity::filesystem {

class FilesystemFactory {
 public:
  static FileInterfacePtr CreateFile(std::string name,
                                     FileInterfacePtr parent = nullptr);
  static FileInterfacePtr CreateFolder(std::string name,
                                       FileInterfacePtr parent = nullptr);
};

}  // namespace file_explorer::entity::filesystem

#endif  // SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FACTORY_H_
