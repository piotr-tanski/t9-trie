#include <fstream>

#include <t9trie/DictionaryLoader.hpp>
#include "Trie.hpp"
#include "HashMap.hpp"

namespace T9
{
std::unique_ptr<Dictionary> DictionaryLoader::loadFromStream(std::istream &is, DictionaryImplementation impl)
{
    auto dictionary = createDictionary(impl);
    loadDictionary(is, dictionary.get());
    return dictionary;
}

std::unique_ptr<Dictionary> DictionaryLoader::loadFromFile(const std::filesystem::path &path, DictionaryImplementation impl)
{
    std::ifstream infile(path);
    if (!infile)
    {
        throw LoadError("No such dictionary file");
    }

    auto dictionary = createDictionary(impl);
    loadDictionary(infile, dictionary.get());
    return dictionary;
}

std::unique_ptr<Dictionary> DictionaryLoader::createDictionary(DictionaryImplementation impl)
{
    if (impl == DictionaryImplementation::Trie) {
        return std::make_unique<Trie>();
    }
    return std::make_unique<HashMap>();
}

void DictionaryLoader::loadDictionary(std::istream &is, Dictionary *dictionary)
{
    std::string line;
    while (std::getline(is, line))
    {
        // Words should be either transformed to lower case or dictionary pre-processed appropriately.
        static_cast<void>(dictionary->insert(line));
    }
}
}  // namespace T9
