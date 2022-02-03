#include "HashMap.hpp"

namespace T9
{
namespace
{
constexpr int toIndex(char character) noexcept
{
    switch (character)
    {
        case 'a':
        case 'b':
        case 'c':
            return 2;
        case 'd':
        case 'e':
        case 'f':
            return 3;
        case 'g':
        case 'h':
        case 'i':
            return 4;
        case 'j':
        case 'k':
        case 'l':
            return 5;
        case 'm':
        case 'n':
        case 'o':
            return 6;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 7;
        case 't':
        case 'u':
        case 'v':
            return 8;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 9;
        default:
            return -1;
    }
}
} // namespace

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
