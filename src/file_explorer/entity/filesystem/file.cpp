/*!
 * @file file.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/filesystem/file.h"

#include <string>

namespace file_explorer::entity::filesystem {

File::File(std::string name, FileInterfacePtr parent)
    : FileInterface(name, parent) {}

bool File::IsDirectory() const { return false; }

const FileSet& File::GetChildren() const { return {}; };

}  // namespace file_explorer::entity::filesystem