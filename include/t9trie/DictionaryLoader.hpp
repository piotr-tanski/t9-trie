#pragma once

#include "Dictionary.hpp"

#include <istream>
#include <filesystem>
#include <stdexcept>

namespace T9
{
class LoadError : public std::runtime_error
{
   public:
    using std::runtime_error::runtime_error;
};

class DictionaryLoader
{
   public:
    static std::unique_ptr<Dictionary> loadFromStream(std::istream &is, DictionaryImplementation impl = DictionaryImplementation::Trie);
    static std::unique_ptr<Dictionary> loadFromFile(const std::filesystem::path &path, DictionaryImplementation impl = DictionaryImplementation::Trie);

   private:
    static std::unique_ptr<Dictionary> createDictionary(DictionaryImplementation impl);
    static void loadDictionary(std::istream &is, Dictionary *dictionary);
};
}  // namespace T9
