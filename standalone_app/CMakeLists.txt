add_executable(standalone_app main.cpp)
target_link_libraries(standalone_app PRIVATE t9::t9)

configure_file("${CMAKE_SOURCE_DIR}/dictionaries/10k_english.txt" "${CMAKE_CURRENT_BINARY_DIR}/10k_english.txt" COPYONLY)
configure_file("${CMAKE_SOURCE_DIR}/dictionaries/466k_english.txt" "${CMAKE_CURRENT_BINARY_DIR}/466k_english.txt" COPYONLY)
