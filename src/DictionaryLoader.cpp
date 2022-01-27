#include <fstream>

#include <t9trie/DictionaryLoader.hpp>

namespace T9
{
Trie DictionaryLoader::loadFromFile(const std::filesystem::path &path)
{
    std::ifstream infile(path);
    if (!infile)
    {
        throw LoadError("No such dictionary file");
    }

    Trie t{};
    std::string line;
    while (std::getline(infile, line))
    {
        // Words should be either transformed to lower case or dictionary pre-processed appropriately.
        static_cast<void>(t.insert(line));
    }
    return t;
}
}  // namespace T9
