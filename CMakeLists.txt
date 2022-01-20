cmake_minimum_required(VERSION 3.19)
project(
  T9Trie
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
