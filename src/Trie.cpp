#include "Trie.hpp"

namespace T9
{
namespace
{
constexpr int toChildIndex(char character) noexcept
{
    const auto index = toIndex(character);
    if (index == -1)
    {
        return -1;
    }
    return index - 2;
}

constexpr int indexFromNumber(int number)
{
    return number - 2;
}
} // namespace

void Trie::Node::free()
{
    for (auto child : children)
    {
        if (child != nullptr)
        {
            child->free();
            delete child;
            child = nullptr;
        }
    }
}

Trie::~Trie() noexcept
{
    if (root)
    {
        root->free();
    }
}

bool Trie::insert(Word word)
{
    if (word.empty())
    {
        return false;
    }

    Node *node = root.get();
    for (const auto character : word)
    {
        const auto index = toChildIndex(character);
        if (index == -1)
        {
            return false;
        }

        if (node->children[index] == nullptr)
        {
            node->children[index] = new Node();
        }
        node = node->children[index];
    }
    node->words.push_back(std::move(word));
    return true;
}

Words Trie::search(const NumberSequence &numbers) const noexcept
{
    if (numbers.empty())
    {
        return {};
    }

    auto node = root.get();
    for (const auto number : numbers)
    {
        const auto index = indexFromNumber(number);
        if (node->children[index] == nullptr)
        {
            return {};
        }
        node = node->children[index];
    }
    return node->words;
}
}  // namespace T9
