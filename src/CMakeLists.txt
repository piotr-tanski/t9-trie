set(HEADER_LIST
    "${T9Trie_SOURCE_DIR}/include/t9trie/DictionaryLoader.hpp"
    "${T9Trie_SOURCE_DIR}/include/t9trie/Trie.hpp"
)

add_library(t9trie DictionaryLoader.cpp Trie.cpp ${HEADER_LIST})
add_library(t9::trie ALIAS t9trie)
target_include_directories(t9trie PUBLIC "${T9Trie_SOURCE_DIR}/include")
target_compile_features(t9trie PUBLIC cxx_std_17)

source_group(
  TREE "${T9Trie_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)
