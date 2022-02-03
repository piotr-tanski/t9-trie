#pragma once

#include <t9trie/Dictionary.hpp>

#include <memory>

namespace T9
{
class Trie : public Dictionary
{
   public:
    Trie()                = default;
    Trie(const Trie&)     = delete;
    Trie(Trie&&) noexcept = default;
    Trie& operator=(const Trie&) = delete;
    Trie& operator=(Trie&&) noexcept = default;
    ~Trie() noexcept override;

    [[nodiscard]] bool insert(Word word) override;
    [[nodiscard]] Words search(const NumberSequence& numbers) const noexcept override;

   private:
    static constexpr inline auto MAX_CHILDREN_COUNT = 8;
    struct Node
    {
        void free();

        Node* children[MAX_CHILDREN_COUNT] = {nullptr};
        Words words;
    };

    std::unique_ptr<Node> root = std::make_unique<Node>();
};
}  // namespace T9
