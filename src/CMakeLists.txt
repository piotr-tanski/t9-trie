set(HEADER_LIST
    "${T9Trie_SOURCE_DIR}/include/t9trie/DictionaryLoader.hpp"
    "${T9Trie_SOURCE_DIR}/include/t9trie/Dictionary.hpp"
)

add_library(t9lib)
add_library(t9::t9 ALIAS t9lib)

target_sources(t9lib
    PUBLIC
        ${HEADER_LIST}
    PRIVATE
        DictionaryLoader.cpp
        Trie.cpp
        Trie.hpp
        HashMap.cpp
        HashMap.hpp
)
target_include_directories(t9lib PUBLIC "${T9Trie_SOURCE_DIR}/include")
