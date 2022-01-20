include(FetchContent)

FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(catch)

add_executable(trie_tests trie_tests.cpp)
target_compile_features(trie_tests PRIVATE cxx_std_17)
target_compile_options(trie_tests PRIVATE "-Wa,-mbig-obj")
target_link_libraries(trie_tests PRIVATE t9trie Catch2::Catch2)

add_test(NAME trietests COMMAND trie_tests)
