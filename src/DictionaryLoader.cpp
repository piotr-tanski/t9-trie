#include "DictionaryLoader.hpp"

#include <fstream>

Trie DictionaryLoader::loadFromFile(const std::filesystem::path &path)
{
    std::ifstream infile(path);
    if (!infile) {
        throw LoadError("No such file");
    }

    Trie t{};
    std::string line;
    while (std::getline(infile, line))
    {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        t.insert(line);
    }
    return t;
}
