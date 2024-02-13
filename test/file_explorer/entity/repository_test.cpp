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

  Repository repository(":memory:");

  EXPECT_EQ(repository.GetStatus(), SQLITE_OK);

  // 데이터베이스 테이블 생성

  const char* sql =
      "DROP TABLE IF EXISTS Cars;"
      "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);"
      "INSERT INTO Cars VALUES(1, 'Audi', 52642);"
      "INSERT INTO Cars VALUES(2, 'Mercedes', 57127);"
      "INSERT INTO Cars VALUES(3, 'Skoda', 9000);"
      "INSERT INTO Cars VALUES(4, 'Volvo', 29000);"
      "INSERT INTO Cars VALUES(5, 'Bentley', 350000);"
      "INSERT INTO Cars VALUES(6, 'Citroen', 21000);"
      "INSERT INTO Cars VALUES(7, 'Hummer', 41400);"
      "INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);";
  repository.SendStatement(sql);
}

}  // namespace file_explorer::entity::test