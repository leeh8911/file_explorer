set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

enable_testing()

add_executable(FILE_EXPLORER_TEST ${SRC_FILES})

target_link_libraries(
    FILE_EXPLORER_TEST
    GTest::gtest_main
    FILE_EXPLORER
)

target_include_directories(FILE_EXPLORER_TEST PUBLIC
"${CMAKE_SOURCE_DIR}/src"
"${CMAKE_SOURCE_DIR}")

include(GoogleTest)
gtest_discover_tests(FILE_EXPLORER_TEST)