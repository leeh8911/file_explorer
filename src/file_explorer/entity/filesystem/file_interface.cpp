/*!
 * @file file_interface.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/filesystem/file_interface.h"

namespace file_explorer::entity::filesystem {

FileInterface::FileInterface(std::string name, FileInterfacePtr parent)
    : m_name(name), m_parent(parent) {}

const std::string& FileInterface::GetName() const { return m_name; }

FileInterfacePtr FileInterface::GetParent() const { return m_parent; }

bool FileSystemPtrComparator::operator()(FileInterfacePtr lhs,
                                         FileInterfacePtr rhs) const {
  return lhs->GetName() < rhs->GetName();
}
}  // namespace file_explorer::entity::filesystem
