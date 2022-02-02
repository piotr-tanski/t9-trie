#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../src/Trie.hpp"
#include "../src/HashMap.hpp"

using namespace T9;

TEST_CASE("T_TestSearchOnEmpty", "[trie]") {
    Trie t{};

    const auto words = t.search({3, 4, 5});
    REQUIRE(words.empty());
}

TEST_CASE("T_TestEmptyStringInsertion", "[trie]") {
    Trie t{};
    REQUIRE(t.insert("") == false);

    const auto words = t.search({});
    REQUIRE(words.empty());
}

TEST_CASE("T_TestSimpleWordsSearch", "[trie]") {
    Trie t{};
    REQUIRE(t.insert("hell"));
    REQUIRE(t.insert("gell"));

    auto words = t.search({4, 3, 5, 5});
    REQUIRE(words.size() == 2);

    words = t.search({2, 3, 4});
    REQUIRE(words.size() == 0);
}
TEST_CASE("HM_TestSearchOnEmpty", "[hash_map]") {
    HashMap hm{};

    const auto words = hm.search({3, 4, 5});
    REQUIRE(words.empty());
}

TEST_CASE("HM_TestEmptyStringInsertion", "[hash_map]") {
    HashMap hm{};
    REQUIRE(hm.insert("") == false);

    const auto words = hm.search({});
    REQUIRE(words.empty());
}

TEST_CASE("HM_TestSimpleWordsSearch", "[hash_map]") {
    HashMap hm{};
    REQUIRE(hm.insert("hell"));
    REQUIRE(hm.insert("gell"));

    auto words = hm.search({4, 3, 5, 5});
    REQUIRE(words.size() == 2);

    words = hm.search({2, 3, 4});
    REQUIRE(words.size() == 0);
}
