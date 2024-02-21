/*!
 * @file file.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/filesystem/file.h"

#include <utility>

namespace file_explorer::domain::filesystem {

size_t IFileHasher::operator()(const IFilePtr& file) const {
  return std::hash<std::string>{}(file->Path());
}

IFile::IFile(std::string name, IFilePtr parent,
             core::TimePoint last_modified_time)
    : m_name{std::move(name)},
      m_parent{std::move(parent)},
      m_last_modified_time{std::move(last_modified_time)} {}

std::string_view IFile::Name() const { return m_name; }

std::string& IFile::Name() { return m_name; }

IFilePtr IFile::Parent() const { return m_parent; }
IFilePtr IFile::Parent() { return m_parent; }
std::string IFile::Path() const {
  if (m_parent == nullptr) {
    return m_name;
  }
  return m_parent->Path() + "/" + m_name;
}

const core::TimePoint& IFile::LastModifiedTime() const {
  return m_last_modified_time;
}

core::TimePoint& IFile::LastModifiedTime() { return m_last_modified_time; }

std::string IFile::LastModifiedTimeString() const {
  return core::TimePointToString(m_last_modified_time);
}

File::File(std::string name, std::string extension, IFilePtr parent,
           core::TimePoint last_modified_time, size_t size)
    : IFile(std::move(name), std::move(parent), std::move(last_modified_time)),
      m_extension{std::move(extension)},
      m_size{size} {}

bool File::IsFile() const { return true; }

size_t File::Size() const { return m_size; }

std::string File::FullName() const {
  std::string result{};
  result += this->Name();
  result += ".";
  result += m_extension;
  return result;
}

std::string_view File::Extension() const { return m_extension; }

std::string& File::Extension() { return m_extension; }

Folder::Folder(std::string name, IFilePtr parent,
               core::TimePoint last_modified_time)
    : IFile(std::move(name), parent, std::move(last_modified_time)) {}

bool Folder::IsFile() const { return false; }

size_t Folder::Size() const {
  size_t size = 0;
  for (const auto& child : m_children) {
    size += child->Size();
  }
  return size;
}

const IFileList& Folder::Children() const { return m_children; }
IFileList& Folder::Children() { return m_children; }

void Folder::AddChild(IFilePtr child) {
  m_children.push_back(std::move(child));
}

}  // namespace file_explorer::domain::filesystem
