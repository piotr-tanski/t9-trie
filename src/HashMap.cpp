#include "HashMap.hpp"

#include <stdexcept>

namespace T9
{
bool HashMap::insert(Word word)
{
    if (word.empty())
    {
        return false;
    }

    const auto key = keyFromChars(word);
    if (!key.has_value())
    {
        return false;
    }
    dictionary[key.value()].push_back(word);
    return true;
}

std::optional<HashMap::DictionaryKey> HashMap::keyFromChars(const Word &chars) noexcept
{
    DictionaryKey key = 0;
    for (const auto character : chars)
    {
        const auto index = toIndex(character);
        if (index == -1)
        {
            return std::nullopt;
        }
        key = key * 10 + index;
    }
    return key;
}

Words HashMap::search(const NumberSequence &numbers) const noexcept
{
    if (numbers.empty())
    {
        return {};
    }

    const auto key = keyFromNumbers(numbers);
    try {
        return dictionary.at(key);
    }
    catch (const std::out_of_range &) {
        return {};
    }
}

HashMap::DictionaryKey HashMap::keyFromNumbers(const NumberSequence &numbers) noexcept
{
    DictionaryKey key = 0;
    for (const auto number : numbers)
    {
        key = key * 10 + number;
    }
    return key;
}
}  // namespace T9
