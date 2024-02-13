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

class ColumnTemplate {
 public:
  ColumnTemplate(std::string_view name, std::string_view type);
  ~ColumnTemplate();

  ColumnTemplate(ColumnTemplate&& other);
  ColumnTemplate& operator=(ColumnTemplate&& other);

  ColumnTemplate(const ColumnTemplate&);
  ColumnTemplate& operator=(const ColumnTemplate&);

  std::string_view GetName() const;
  std::string_view GetType() const;

 private:
  struct Impl;
  std::unique_ptr<Impl> m_pimpl{nullptr};
};

class TableTemplate {
 public:
  explicit TableTemplate(std::string_view name);
  ~TableTemplate();

  TableTemplate(TableTemplate&& other);
  TableTemplate& operator=(TableTemplate&& other);

  TableTemplate(const TableTemplate&);
  TableTemplate& operator=(const TableTemplate&);

  std::string_view GetName() const;

  void AddColumn(const ColumnTemplate& column);
  void DeleteColumn(std::string_view name);

  size_t GetColumnCount() const;
  std::string_view GetColumnName(size_t idx) const;
  std::string_view GetColumnType(size_t idx) const;
  std::string_view GetColumnType(std::string_view col_name) const;

 private:
  struct Impl;
  std::unique_ptr<Impl> m_pimpl{nullptr};
};

class Repository {
 public:
  enum class Status {
    Begin = 0,
    Commit,
  };
  explicit Repository(std::string_view file_path);
  ~Repository();

  Repository(Repository&& other);
  Repository& operator=(Repository&& other);

  Repository(const Repository&) = delete;
  Repository& operator=(const Repository&) = delete;

  int32_t GetStatus() const;

  Repository& CreateTable(const TableTemplate& table);

  Repository& Into(std::string_view table_name);
  Repository& Insert(std::vector<std::string_view> values);

 private:
  struct Impl;
  std::unique_ptr<Impl> m_pimpl{nullptr};
};

}  // namespace file_explorer::entity

#endif  // SRC_FILE_EXPLORER_ENTITY_REPOSITORY_H_
