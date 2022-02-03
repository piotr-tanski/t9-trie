cmake_minimum_required(VERSION 3.19)
project(
  T9Trie
  VERSION 0.1
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(IS_TOPLEVEL_PROJECT TRUE)
else()
    set(IS_TOPLEVEL_PROJECT FALSE)
endif()
option(TRIE_OPT_BUILD_TESTS "Build and perform t9 tests" ${IS_TOPLEVEL_PROJECT})

add_subdirectory(src)

if (TRIE_OPT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(standalone_app)
    add_subdirectory(examples)
    add_subdirectory(tests)
    add_subdirectory(benchmarks)
endif()
