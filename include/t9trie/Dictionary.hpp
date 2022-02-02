#pragma once

#include <string>
#include <vector>

namespace T9
{
using Word  = std::string;
using Words = std::vector<Word>;
using NumberSequence = std::vector<int>;

enum class DictionaryImplementation
{
    Trie,
    HashMap
};

class Dictionary
{
   public:
    virtual ~Dictionary() noexcept = default;

    [[nodiscard]] virtual bool insert(Word word)                                     = 0;
    [[nodiscard]] virtual Words search(const NumberSequence& numbers) const noexcept = 0;
};
} // namespace T9
