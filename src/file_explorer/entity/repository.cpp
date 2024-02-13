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

#include <sqlite3.h>

#include <format>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <utility>

namespace file_explorer::entity {

struct Repository::Impl {
  sqlite3* db{nullptr};
  sqlite3_stmt* res{nullptr};
  int32_t status{SQLITE_OK};
};

Repository::Repository(std::string_view file_path)
    : m_pimpl(std::make_unique<Impl>()) {
  m_pimpl->status = sqlite3_open(file_path.data(), &m_pimpl->db);
}

Repository::~Repository() {
  if (m_pimpl->db) {
    sqlite3_close(m_pimpl->db);
  }
}

Repository::Repository(Repository&& other) = default;
Repository& Repository::operator=(Repository&& other) = default;

int32_t Repository::GetStatus() const { return m_pimpl->status; }

void Repository::SendStatement(std::string_view statement) {
  char* err_msg = nullptr;
  m_pimpl->status =
      sqlite3_exec(m_pimpl->db, statement.data(), nullptr, nullptr, &err_msg);

  if (m_pimpl->status != SQLITE_OK) {
    std::cout << std::format("SQL error: {}", err_msg) << std::endl;

    sqlite3_free(err_msg);
  }
}
}  // namespace file_explorer::entity
