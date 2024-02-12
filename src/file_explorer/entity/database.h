/*!
 * @file database.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_DATABASE_H_
#define SRC_FILE_EXPLORER_ENTITY_DATABASE_H_

#include <memory>
#include <string_view>
namespace file_explorer::entity {
class Database {
 public:
  Database(const Database&) = delete;
  Database& operator=(const Database&) = delete;

  Database(Database&&) = default;
  Database& operator=(Database&&) = default;

  static Database& GetInstance();

  void LoadDb(std::string_view path);
  bool IsLoaded() const;

 private:
  Database() = default;
};
}  // namespace file_explorer::entity

#endif  // SRC_FILE_EXPLORER_ENTITY_DATABASE_H_
