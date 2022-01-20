#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <t9trie/Trie.hpp>

using namespace T9;

TEST_CASE("TestSearchOnEmptyTrie") {
    Trie t{};

    const auto words = t.search({1, 2, 3});
    REQUIRE(words.empty());
}

TEST_CASE("TestEmptyStringInsertion") {
    Trie t{};
    REQUIRE(t.insert("") == false);

    const auto words = t.search({});
    REQUIRE(words.empty());
}

TEST_CASE("TestSimpleWordsSearch") {
    Trie t{};
    REQUIRE(t.insert("hell"));
    REQUIRE(t.insert("gell"));

    auto words = t.search({4, 3, 5, 5});
    REQUIRE(words.size() == 2);

    words = t.search({2, 3, 4});
    REQUIRE(words.size() == 0);
}

TEST_CASE("TestSpecialCharactersSearch") {
    Trie t{};
    REQUIRE(t.insert("ain't"));

    const auto words = t.search({2, 4, 6, 1, 8});
    REQUIRE(words.size() == 1);
    REQUIRE(words[0] == "ain't");
}

TEST_CASE("TestInsertionOfIncompatibleWords") {
    Trie t{};

    // This needs to be re-worked.
    REQUIRE(t.insert("a\\b") == false);
    REQUIRE(t.insert("a/b"));
    REQUIRE(t.insert("a-b"));
    REQUIRE(t.insert("a_b") == false);
    REQUIRE(t.insert("a=b") == false);
    REQUIRE(t.insert("a+b") == false);
    REQUIRE(t.insert("a>b") == false);
    REQUIRE(t.insert("a<b") == false);
    REQUIRE(t.insert("a.b") == false);
    REQUIRE(t.insert("a,b") == false);
    REQUIRE(t.insert("ab!") == false);
    REQUIRE(t.insert("ab?") == false);
}
