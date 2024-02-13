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
#include <vector>

namespace file_explorer::entity {

struct ColumnTemplate::Impl {
  std::string name;
  std::string type;

  Impl(std::string_view name_, std::string_view type_)
      : name(name_), type(type_) {}
};

ColumnTemplate::ColumnTemplate(std::string_view name_, std::string_view type_)
    : m_pimpl(std::make_unique<Impl>(name_, type_)) {}

ColumnTemplate::~ColumnTemplate() = default;

ColumnTemplate::ColumnTemplate(ColumnTemplate&& other) = default;
ColumnTemplate& ColumnTemplate::operator=(ColumnTemplate&& other) = default;

ColumnTemplate::ColumnTemplate(const ColumnTemplate& other) {
  m_pimpl = std::make_unique<Impl>(other.m_pimpl->name, other.m_pimpl->type);
}
ColumnTemplate& ColumnTemplate::operator=(const ColumnTemplate& other) {
  m_pimpl = std::make_unique<Impl>(other.m_pimpl->name, other.m_pimpl->type);

  return *this;
}

std::string_view ColumnTemplate::GetName() const { return m_pimpl->name; }
std::string_view ColumnTemplate::GetType() const { return m_pimpl->type; }

struct TableTemplate::Impl {
  std::string name;
  std::vector<ColumnTemplate> columns;

  Impl(std::string_view name_) : name(name_), columns() {}
  Impl(std::string_view name_, const std::vector<ColumnTemplate>& columns_)
      : name(name_), columns(columns_) {}
};

TableTemplate::TableTemplate(std::string_view name_)
    : m_pimpl(std::make_unique<Impl>(name_)) {}

TableTemplate::~TableTemplate() = default;

TableTemplate::TableTemplate(TableTemplate&& other) = default;

TableTemplate& TableTemplate::operator=(TableTemplate&& other) = default;

TableTemplate::TableTemplate(const TableTemplate& other) {
  m_pimpl = std::make_unique<Impl>(other.m_pimpl->name, other.m_pimpl->columns);
}

TableTemplate& TableTemplate::operator=(const TableTemplate& other) {
  m_pimpl = std::make_unique<Impl>(other.m_pimpl->name, other.m_pimpl->columns);

  return *this;
}

void TableTemplate::AddColumn(const ColumnTemplate& column) {
  auto iter = std::find_if(m_pimpl->columns.begin(), m_pimpl->columns.end(),
                           [column](const ColumnTemplate& c) {
                             return c.GetName() == column.GetName();
                           });

  if (iter == m_pimpl->columns.end()) {
    m_pimpl->columns.push_back(column);
  }
}

void TableTemplate::DeleteColumn(std::string_view name) {
  auto iter = std::find_if(m_pimpl->columns.begin(), m_pimpl->columns.end(),
                           [name](const ColumnTemplate& column) {
                             return column.GetName() == name;
                           });

  if (iter != m_pimpl->columns.end()) {
    m_pimpl->columns.erase(iter);
  }
}

size_t TableTemplate::GetColumnCount() const { return m_pimpl->columns.size(); }

std::string_view TableTemplate::GetColumnName(size_t idx) const {
  return m_pimpl->columns[idx].GetName();
}

std::string_view TableTemplate::GetColumnType(size_t idx) const {
  return m_pimpl->columns[idx].GetType();
}

std::string_view TableTemplate::GetColumnType(std::string_view col_name) const {
  auto iter = std::find_if(m_pimpl->columns.begin(), m_pimpl->columns.end(),
                           [col_name](const ColumnTemplate& column) {
                             return column.GetName() == col_name;
                           });

  if (iter != m_pimpl->columns.end()) {
    return iter->GetType();
  }

  return "";
}

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
