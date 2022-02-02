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

    std::uint64_t key = 0;
    for (const auto character : word)
    {
        const auto index = toIndex(character);
        if (index == -1)
        {
            return false;
        }

        key = key * 10 + index;
    }
    dictionary[key].push_back(word);
    return true;
}

Words HashMap::search(const NumberSequence &numbers) const noexcept
{
    if (numbers.empty())
    {
        return {};
    }

    std::uint64_t key = 0;
    for (const auto number : numbers)
    {
        key = key * 10 + number;
    }

    try {
        return dictionary.at(key);
    }
    catch (const std::out_of_range &) {
        return {};
    }
}
}  // namespace T9
