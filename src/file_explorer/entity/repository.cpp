/*!
 * @file repository.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/repository.h"

namespace file_explorer::entity {

Repository::Repository(std::string_view file_path) {
  m_db_status = sqlite3_open(file_path.data(), &m_db);
}
}  // namespace file_explorer::entity