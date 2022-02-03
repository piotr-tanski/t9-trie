#include <t9trie/DictionaryLoader.hpp>

#include <iostream>

int main(int, char**)
{
    auto dictionary = T9::DictionaryLoader::loadFromFile("./10k_english.txt", T9::DictionaryImplementation::HashMap);
    const auto suggestions = dictionary->search({4, 3, 5, 5, 6});
    for (const auto& word : suggestions)
    {
        std::cout << word << '\n';
    }
    return 0;
}
