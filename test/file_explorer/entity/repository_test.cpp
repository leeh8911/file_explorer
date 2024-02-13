/*!
 * @file repository_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/entity/repository.h"

#include <gtest/gtest.h>
#include <sqlite3.h>

namespace file_explorer::entity::test {

TEST(RepositoryTest, SampleCase) {
  Repository repository(":memory:");

  EXPECT_EQ(repository.GetStatus(), SQLITE_OK);
}

TEST(RepositoryTest, CreateTableTemplateCase) {
  TableTemplate table("Cars");

  table.AddColumn(ColumnTemplate("Id", "INT"));
  table.AddColumn(ColumnTemplate("Name", "TEXT"));
  table.AddColumn(ColumnTemplate("Price", "INT"));

  EXPECT_EQ(table.GetColumnCount(), 3);
  EXPECT_EQ(table.GetColumnName(0), "Id");
  EXPECT_EQ(table.GetColumnName(1), "Name");
  EXPECT_EQ(table.GetColumnName(2), "Price");
}
TEST(RepositoryTest, SampleUsecase) {
  // 메모리 상에 데이터베이스 생성
  // 데이터베이스 테이블 생성
  // 데이터베이스 테이블에 데이터 입력
  // 데이터베이스 테이블에서 데이터 조회
  // 데이터베이스 테이블에서 데이터 수정
  // 데이터베이스 테이블에서 데이터 다시 조회

  Repository repository("test.db");

  EXPECT_EQ(repository.GetStatus(), SQLITE_OK);

  // 데이터베이스 테이블 생성

  {
    TableTemplate table("Cars");

    table.AddColumn(ColumnTemplate("Id", "INT"));
    table.AddColumn(ColumnTemplate("Name", "TEXT"));
    table.AddColumn(ColumnTemplate("Price", "INT"));

    repository.CreateTable(table);
  }

  {
    repository.Insert({"1", "Audi", "52642"}).Into("Cars");
    repository.Insert({"2", "Mercedes", "57127"}).Into("Cars");
    repository.Insert({"3", "Skoda", "9000"}).Into("Cars");
    repository.Insert({"4", "Volvo", "29000"}).Into("Cars");
    repository.Insert({"5", "Bentley", "350000"}).Into("Cars");
    repository.Insert({"6", "Citroen", "21000"}).Into("Cars");
    repository.Insert({"7", "Hummer", "41400"}).Into("Cars");
    repository.Insert({"8", "Volkswagen", "21600"}).Into("Cars");
  }

  {
    repository.From("Cars").Select("Name").Where("Price > 30000").Execute();

    std::vector<std::string> result;
    while (repository.Next()) {
      result.push_back(repository.GetString(0));
    }

    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "Audi");
    EXPECT_EQ(result[1], "Mercedes");
    EXPECT_EQ(result[2], "Bentley");
  }
}

}  // namespace file_explorer::entity::test