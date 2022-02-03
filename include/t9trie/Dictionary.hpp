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
} // namespace T9
