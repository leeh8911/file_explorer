/*!
 * @file folder_tree_search.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FOLDER_TREE_SEARCH_H_
#define SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FOLDER_TREE_SEARCH_H_

#include <string>
#include <vector>

#include "file_explorer/entity/filesystem/file.h"
#include "file_explorer/entity/filesystem/file_interface.h"
#include "file_explorer/entity/filesystem/folder.h"

namespace file_explorer::entity::filesystem {

class FolderTreeSearch {
 public:
  FolderTreeSearch() = default;

  std::vector<FileInterfacePtr> Search(FileInterfacePtr root,
                                       const std::string& target) const;

 private:
};
}  // namespace file_explorer::entity::filesystem

#endif  // SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FOLDER_TREE_SEARCH_H_
