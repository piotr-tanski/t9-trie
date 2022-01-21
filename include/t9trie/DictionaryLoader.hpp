#pragma once

#include "Trie.hpp"

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
    static Trie loadFromFile(const std::filesystem::path &path);
};
}  // namespace T9
