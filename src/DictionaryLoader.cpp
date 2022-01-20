#include <t9trie/DictionaryLoader.hpp>

#include <fstream>

namespace T9
{
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
        static_cast<void>(t.insert(line));
    }
    return t;
}
} // namespace T9
