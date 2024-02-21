/*!
 * @file core.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_FILE_EXPLORER_CORE_CORE_H_
#define SRC_FILE_EXPLORER_CORE_CORE_H_

#include <chrono>
#include <string>

namespace file_explorer::domain::core {

using TimePoint = std::chrono::file_clock::time_point;
std::string TimePointToString(TimePoint tp);
}  // namespace file_explorer::domain::core

#endif  // SRC_FILE_EXPLORER_CORE_CORE_H_
