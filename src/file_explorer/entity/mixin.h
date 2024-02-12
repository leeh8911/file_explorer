/*!
 * @file mixin.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_MIXIN_H_
#define SRC_FILE_EXPLORER_ENTITY_MIXIN_H_

namespace file_explorer::entity {

template <typename T>
class Singleton<T> {
 public:
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static T &GetInstance() {
    static T instance;
    return instance;
  }

 private:
  Singleton() = default;
};
}  // namespace file_explorer::entity

#endif  // SRC_FILE_EXPLORER_ENTITY_MIXIN_H_
