/*!
 * @file worker.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_MODEL_WORKER_H_
#define SRC_FILE_EXPLORER_MODEL_WORKER_H_

#include <functional>
#include <future>
#include <tuple>

namespace file_explorer::model {

template <typename F, typename... Args>
class Worker {
 public:
  using ReturnType = std::invoke_result_t<F, Args...>;
  using PromiseType = std::promise<ReturnType>;
  using FutureType = std::future<ReturnType>;

  Worker(F&& job, Args&&... args)
      : job_{job}, args_{std::forward<Args>(args)...} {}

  void AsyncInvoke() {
    std::async(std::launch::async, [this]() {
      result_ = std::apply(job_, args_);
      promise_.set_value(result_);
    });
  }

  void Wait() {
    future_ = promise_.get_future();
    future_.wait();
  }

  ReturnType Get() { return future_.get(); }

 private:
  std::function<ReturnType(Args...)> job_{};
  std::tuple<Args...> args_{};
  ReturnType result_{};
  std::promise<ReturnType> promise_{};
  std::future<ReturnType> future_{};
};
}  // namespace file_explorer::model

#endif  // SRC_FILE_EXPLORER_MODEL_WORKER_H_
