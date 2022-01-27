set(HEADER_LIST
    "${T9Trie_SOURCE_DIR}/include/t9trie/DictionaryLoader.hpp"
    "${T9Trie_SOURCE_DIR}/include/t9trie/Trie.hpp"
)

add_library(t9trie)
add_library(t9::trie ALIAS t9trie)

target_sources(t9trie
    PUBLIC
     ${HEADER_LIST}
    PRIVATE
     DictionaryLoader.cpp
     Trie.cpp
)
target_include_directories(t9trie PUBLIC "${T9Trie_SOURCE_DIR}/include")
