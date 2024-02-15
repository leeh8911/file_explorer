/*!
 * @file file_interface.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FILE_INTERFACE_H_
#define SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FILE_INTERFACE_H_

#include <memory>
#include <set>
#include <string>


namespace file_explorer::entity::filesystem {
class FileInterface;
using FileInterfacePtr = std::shared_ptr<FileInterface>;

class FileSystemPtrComparator;
using FileSet = std::set<FileInterfacePtr, FileSystemPtrComparator>;

class FileInterface {
 public:
  virtual ~FileInterface() = default;

  explicit FileInterface(std::string name, FileInterfacePtr parent = nullptr);

  virtual bool IsDirectory() const = 0;
  virtual const FileSet& GetChildren() const = 0;

  const std::string& GetName() const;
  FileInterfacePtr GetParent() const;

 private:
  std::string m_name{};
  FileInterfacePtr m_parent{};
};

class FileSystemPtrComparator {
 public:
  bool operator()(FileInterfacePtr lhs, FileInterfacePtr rhs) const;
};
}  // namespace file_explorer::entity::filesystem

#endif  // SRC_FILE_EXPLORER_ENTITY_FILESYSTEM_FILE_INTERFACE_H_
