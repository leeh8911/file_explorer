/*!
 * @file factory.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/filesystem/factory.h"

namespace file_explorer::entity::filesystem {

FileInterfacePtr Factory::CreateFile(std::string name,
                                     FileInterfacePtr parent) {
  return std::make_shared<File>(name, parent);
}

FileInterfacePtr Factory::CreateFolder(std::string name,
                                       FileInterfacePtr parent) {
  return std::make_shared<Folder>(name, parent);
}

}  // namespace file_explorer::entity::filesystem