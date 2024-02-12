/*!
 * @file database.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/database.h"

#include <memory>
#include <utility>

namespace file_explorer::entity {

Database& Database::GetInstance() {
  static Database db;
  return db;
}

void Database::LoadDb(std::string_view path) {}

bool Database::IsLoaded() const { return true; }
}  // namespace file_explorer::entity