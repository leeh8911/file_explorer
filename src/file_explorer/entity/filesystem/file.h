/*!
 * @file file.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FILE_H_
#define SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FILE_H_

#include <string>

#include "file_explorer/entity/filesystem/file_interface.h"

namespace file_explorer::entity::filesystem {

class File : public FileInterface {
 public:
  explicit File(std::string name, FileInterfacePtr parent = nullptr);

  bool IsDirectory() const override;
  const FileSet& GetChildren() const override;
};
}  // namespace file_explorer::entity::filesystem

#endif  // SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FILE_H_
