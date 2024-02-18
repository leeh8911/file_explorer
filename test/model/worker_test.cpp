/*!
 * @file worker_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <gtest/gtest.h>

#include "file_explorer/file_explorer.h"

namespace file_explorer::test {

TEST(WorkerTest, SampleTest) {
  //   file_explorer::WorkerPool::GetInstance().Init(0);

  auto job = [](int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
      sum += i;
    }
    return sum;
  };

  auto worker = file_explorer::model::Worker(std::move(job), 0, 1000);

  worker.AsyncInvoke();

  worker.Wait();

  EXPECT_EQ(worker.Get(), 499500);
}
}  // namespace file_explorer::test
