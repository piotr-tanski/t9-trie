#pragma once

#include <t9trie/Dictionary.hpp>

#include <optional>
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

    static std::optional<DictionaryKey> keyFromChars(const Word& chars) noexcept;
    static DictionaryKey keyFromNumbers(const NumberSequence& numbers) noexcept;

    std::unordered_map<DictionaryKey, DictionaryValue> dictionary;
};
}  // namespace T9
