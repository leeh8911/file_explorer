/*!
 * @file folder.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FOLDER_H_
#define SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FOLDER_H_

#include <set>
#include <string>

#include "file_explorer/entity/filesystem/filesystem.h"

namespace file_explorer::entity::filesystem {

class Folder : public FileInterface {
 public:
  explicit Folder(std::string name, FileInterfacePtr parent = nullptr);

  bool IsDirectory() const override;
  const FileSet& GetChildren() const override;

  void Add(FileInterfacePtr file);

 private:
  FileSet m_children{};
};
}  // namespace file_explorer::entity::filesystem

#endif  // SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FOLDER_H_
