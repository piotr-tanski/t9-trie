#pragma once

#include <t9trie/Dictionary.hpp>

#include <unordered_map>

namespace T9
{
class HashMap : public Dictionary
{
   public:
    [[nodiscard]] bool insert(Word word) override;
    [[nodiscard]] Words search(const NumberSequence& numbers) const noexcept override;

   private:
    using DictionaryKey = std::uint64_t;
    using DictionaryValue = Words;

    std::unordered_map<DictionaryKey, DictionaryValue> dictionary;
};
}  // namespace T9
