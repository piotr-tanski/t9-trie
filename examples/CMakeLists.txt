add_executable(trie_example trie_example_main.cpp)
target_link_libraries(trie_example PRIVATE t9::t9)

add_executable(hashmap_example hashmap_example_main.cpp)
target_link_libraries(hashmap_example PRIVATE t9::t9)

configure_file("${CMAKE_SOURCE_DIR}/dictionaries/10k_english.txt" "${CMAKE_CURRENT_BINARY_DIR}/10k_english.txt" COPYONLY)
configure_file("${CMAKE_SOURCE_DIR}/dictionaries/466k_english.txt" "${CMAKE_CURRENT_BINARY_DIR}/466k_english.txt" COPYONLY)
