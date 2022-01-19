#include "../src/Trie.hpp"

#include <cassert>
#include <iostream>

void TestSearchOnEmptyTrie() {
    Trie t{};

    const auto words = t.search({1, 2, 3});
    assert(words.empty());
}

void TestEmptyStringInsertion() {
    Trie t{};
    t.insert("");

    const auto words = t.search({});
    assert(words.empty());
}

void TestSimpleWordsSearch() {
    Trie t{};
    t.insert("hell");
    t.insert("gell");

    auto words = t.search({4, 3, 5, 5});
    assert(words.size() == 2);

    words = t.search({2, 3, 4});
    assert(words.size() == 0);
}

void TestSpecialCharactersSearch() {
    Trie t{};
    t.insert("ain't");

    const auto words = t.search({2, 4, 6, 1, 8});
    assert(words.size() == 1);
    assert(words[0] == "ain't");
}

void TestInsertionOfIncompatibleWords() {
    Trie t{};
    t.insert("a\\b");
    t.insert("a/b");
    t.insert("a-b");
    t.insert("a_b");
    t.insert("a=b");
    t.insert("a+b");
    t.insert("a>b");
    t.insert("a<b");
    t.insert("a.b");
    t.insert("a,b");
    t.insert("ab!");
    t.insert("ab?");
}

int main()
{
    TestSearchOnEmptyTrie();
    TestEmptyStringInsertion();
    TestSimpleWordsSearch();
    TestSpecialCharactersSearch();
    TestInsertionOfIncompatibleWords();
}
