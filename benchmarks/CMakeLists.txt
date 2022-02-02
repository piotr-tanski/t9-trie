find_package(benchmark REQUIRED)

add_executable(trie_vs_hashmap TrieVsHashMap.cpp)
target_link_libraries(trie_vs_hashmap t9::t9 benchmark::benchmark)

configure_file("${CMAKE_SOURCE_DIR}/dictionaries/english.txt" "${CMAKE_CURRENT_BINARY_DIR}/english.txt" COPYONLY)
