include(FetchContent)

FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(catch)

add_executable(t9_tests t9_tests.cpp)
target_compile_features(t9_tests PRIVATE cxx_std_17)
target_link_libraries(t9_tests PRIVATE t9::t9 Catch2::Catch2)

add_test(NAME t9_tests COMMAND t9_tests)

configure_file("${CMAKE_SOURCE_DIR}/dictionaries/10k_english.txt" "${CMAKE_CURRENT_BINARY_DIR}/10k_english.txt" COPYONLY)
