/*!
 * @file trie.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_ENTITY_TRIE_H_
#define SRC_FILE_EXPLORER_ENTITY_TRIE_H_

#include <memory>
#include <string>
#include <vector>

namespace file_explorer::entity {

class Trie {
 public:
  Trie() = default;
  ~Trie() = default;

  void Insert(const std::string& name, const std::string& path);
  void Remove(const std::string& name, const std::string& path);
  std::vector<std::string> Search(const std::string& name);

  Trie(const Trie&) = delete;
  Trie& operator=(const Trie&) = delete;

  Trie(Trie&&) = delete;
  Trie& operator=(Trie&&) = delete;

 private:
  class Node;

  std::unique_ptr<Node> m_root = nullptr;
}
}  // namespace file_explorer::entity
#endif  // SRC_FILE_EXPLORER_ENTITY_TRIE_H_
