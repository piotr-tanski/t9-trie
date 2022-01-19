cmake_minimum_required(VERSION 3.19)
project(t9)

set(CMAKE_CXX_STANDARD 20)

add_executable(t9
    src/main.cpp
    src/Trie.cpp
    src/DictionaryLoader.cpp
)

add_executable(TEST_1
    tests/trie_tests_main.cpp
    src/Trie.cpp
)
