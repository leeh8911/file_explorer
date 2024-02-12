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

#include <sqlite3.h>

#include <memory>
#include <string_view>

namespace file_explorer::entity {

class Repository {
 public:
  explicit Repository(std::string_view file_path);
  ~Repository() = default;

 private:
  std::unique_ptr<sqlite3, decltype(&sqlite3_close)> m_db{nullptr,
                                                          sqlite3_close};

  int32_t m_db_status{SQLITE_NOTFOUND};
};
}  // namespace file_explorer::entity

#endif  // SRC_FILE_EXPLORER_ENTITY_REPOSITORY_H_
