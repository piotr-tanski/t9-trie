cmake_minimum_required(VERSION 3.19)
project(
  T9Trie
  VERSION 0.1
  LANGUAGES CXX)

add_subdirectory(src)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
