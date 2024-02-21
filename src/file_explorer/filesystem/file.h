/*!
 * @file file.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_FILESYSTEM_FILE_H_
#define SRC_FILE_EXPLORER_FILESYSTEM_FILE_H_

#include <chrono>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "file_explorer/core/core.h"


namespace file_explorer::domain::filesystem {
class IFile;
using IFilePtr = std::shared_ptr<IFile>;

class IFileHasher {
 public:
  size_t operator()(const IFilePtr& file) const;
};
using IFileSet = std::unordered_set<IFilePtr, IFileHasher>;
using IFileMap = std::unordered_map<std::string, IFilePtr>;
using IFileList = std::vector<IFilePtr>;

class IFile {
 public:
  IFile() = default;

  virtual ~IFile() = default;

  IFile(std::string name, IFilePtr parent, core::TimePoint last_modified_time);

  virtual std::string_view Name() const;
  virtual std::string& Name();

  virtual IFilePtr Parent() const;
  virtual IFilePtr Parent();

  virtual std::string Path() const;

  virtual bool IsFile() const = 0;

  virtual size_t Size() const = 0;
  virtual const core::TimePoint& LastModifiedTime() const;
  virtual core::TimePoint& LastModifiedTime();
  virtual std::string LastModifiedTimeString() const;

 private:
  std::string m_name{};
  IFilePtr m_parent{nullptr};
  core::TimePoint m_last_modified_time{};
};

class File : public IFile {
 public:
  File(std::string name, std::string extension, IFilePtr parent,
       core::TimePoint last_modified_time, size_t size);

  bool IsFile() const override;

  size_t Size() const override;

  std::string FullName() const;

  std::string_view Extension() const;
  std::string& Extension();

 private:
  size_t m_size{};
  std::string m_extension{};
};

class Folder : public IFile {
 public:
  Folder(std::string name, IFilePtr parent, core::TimePoint last_modified_time);

  bool IsFile() const override;

  size_t Size() const override;

  const IFileList& Children() const;
  IFileList& Children();

  void AddChild(IFilePtr child);

 private:
  IFileList m_children{};
};

}  // namespace file_explorer::domain::filesystem

#endif  // SRC_FILE_EXPLORER_FILESYSTEM_FILE_H_
