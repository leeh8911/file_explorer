/*!
 * @file folder.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/filesystem/folder.h"

#include <string>

namespace file_explorer::entity::filesystem {

Folder::Folder(std::string name, FileInterfacePtr parent)
    : FileInterface(name, parent) {}

bool Folder::IsDirectory() const { return true; }

const FileSet& Folder::GetChildren() const { return m_children; }

void Folder::Add(FileInterfacePtr file) { m_children.insert(file); }
}  // namespace file_explorer::entity::filesystem