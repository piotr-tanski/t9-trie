#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace T9
{
using Word = std::string;
using Words = std::vector<Word>;

class Trie
{
public:
    Trie();
    Trie(const Trie&) = delete;
    Trie(Trie&&) noexcept = default;
    Trie& operator=(const Trie &) = delete;
    Trie& operator=(Trie &&) noexcept = default;
    ~Trie() noexcept;

    [[nodiscard]] bool insert(Word word);
    [[nodiscard]] Words search(const std::vector<int> &numbers) const noexcept;

private:
    static constexpr inline auto MAX_CHILDREN_COUNT = 10;
    struct Node
    {
        void free();

        Node* children[MAX_CHILDREN_COUNT] = {nullptr};
        Words words;
    };

    std::unique_ptr<Node> root;
};
} // namespace T9
