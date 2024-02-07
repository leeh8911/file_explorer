cmake_policy(SET CMP0048 NEW)

project(FILE_EXPLORER)

cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_DEPFILE_FLAGS_CXX "") # 불필요한 헤더파일 로그 출력 제거

add_subdirectory(src)

add_subdirectory(test)

find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
message(STATUS "activate clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option;-header-filter=${CMAKE_SOURCE_DIR}/src/*;-header-filter=-${CMAKE_BINARY_DIR}/*;-fix")
else()
message(SEND_ERROR "clang-tidy requested but executable not found")
endif()