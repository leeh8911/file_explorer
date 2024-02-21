/*!
 * @file core.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "file_explorer/core/core.h"

#include <chrono>
#include <format>
#include <string>

namespace file_explorer::domain::core {

std::string TimePointToString(TimePoint tp) {
  return std::format("{:%Y-%m-%d %H:%M:%S}", tp);
}
}  // namespace file_explorer::domain::core