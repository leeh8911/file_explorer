/*!
 * @file repository.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_REPOSITORY_H_
#define SRC_FILE_EXPLORER_ENTITY_REPOSITORY_H_

#include <memory>
#include <string_view>

namespace file_explorer::entity {

class Repository {
 public:
  explicit Repository(std::string_view file_path);
  ~Repository();

  Repository(Repository&& other);
  Repository& operator=(Repository&& other);

  Repository(const Repository&) = delete;
  Repository& operator=(const Repository&) = delete;

  int32_t GetStatus() const;

  void SendStatement(std::string_view statement);

 private:
  struct Impl;
  std::unique_ptr<Impl> m_pimpl{nullptr};
};

}  // namespace file_explorer::entity

#endif  // SRC_FILE_EXPLORER_ENTITY_REPOSITORY_H_
