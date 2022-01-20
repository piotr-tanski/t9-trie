#include <t9trie/Trie.hpp>

namespace T9
{
namespace
{
    constexpr auto toIndex(char character) noexcept {
        switch (character) {
            case '\'': case '-': case '/':              return 1;
            case 'a': case 'b': case 'c':               return 2;
            case 'd': case 'e': case 'f':               return 3;
            case 'g': case 'h': case 'i':               return 4;
            case 'j': case 'k': case 'l':               return 5;
            case 'm': case 'n': case 'o':               return 6;
            case 'p': case 'q': case 'r': case 's':     return 7;
            case 't': case 'u': case 'v':               return 8;
            case 'w': case 'x': case 'y': case 'z':     return 9;
            default:                                    return -1;
        }
    }
} // namespace

void Trie::Node::free()
{
    for (auto child : children) {
        if (child != nullptr) {
            child->free();
            delete child;
            child = nullptr;
        }
    }
}

Trie::Trie() : root(std::make_unique<Node>()) {}

Trie::~Trie() noexcept
{
    if (root) {
        root->free();
    }
}

bool Trie::insert(Word word)
{
    if (word.empty()) {
        return false;
    }

    Node *node = root.get();
    for (const auto character : word) {
        const auto index = toIndex(character);
        if (index == -1) {
            return false;
        }

        if (node->children[index] == nullptr) {
            node->children[index] = new Node();
        }
        node = node->children[index];
    }
    node->words.push_back(std::move(word));
    return true;
}

Words Trie::search(const std::vector<int> &numbers) const noexcept
{
    if (numbers.empty()) {
        return {};
    }

    auto node = root.get();
    for (const auto index : numbers) {
        if (node->children[index] == nullptr) {
            return {};
        }
        node = node->children[index];
    }
    return node->words;
}
} // namespace T9
