﻿file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(FILE_EXPLORER STATIC
    ${SRC_FILES})


target_include_directories(FILE_EXPLORER PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(FILE_EXPLORER PRIVATE -Werror -Wall -Wextra -Wuninitialized -pedantic)
endif()
if ( MSVC )
    target_compile_options(FILE_EXPLORER PRIVATE /W4)
endif()