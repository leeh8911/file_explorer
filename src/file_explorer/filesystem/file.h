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
#include <vector>

#include "file_explorer/core/core.h"

namespace file_explorer::domain::filesystem {
class IFile;
using IFilePtr = std::shared_ptr<IFile>;
using IFileList = std::vector<IFilePtr>;

class IFile {
 public:
  IFile() = default;

  virtual ~IFile() = default;

  virtual std::string_view Name() const = 0;
  virtual std::string& Name() = 0;

  virtual std::string_view Path() const = 0;

  virtual bool IsFile() const = 0;

  virtual size_t Size() const = 0;
  virtual core::TimePoint LastModifiedTime() const = 0;
};
class File : public IFile {};
class Folder : public IFile {};

}  // namespace file_explorer::domain::filesystem

#endif  // SRC_FILE_EXPLORER_FILESYSTEM_FILE_H_
