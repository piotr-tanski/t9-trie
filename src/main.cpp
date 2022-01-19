#include "DictionaryLoader.hpp"

#include <chrono>
#include <iostream>

class Timer
{
public:
    Timer() noexcept {
        start();
    }

    void start() noexcept
    {
        m_beg = clock::now();
    }

    [[nodiscard]] std::int64_t stop() noexcept
    {
        m_end = clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_beg).count();
    }

private:
    using clock = std::chrono::high_resolution_clock;

    std::chrono::time_point<clock> m_beg;
    std::chrono::time_point<clock> m_end;
};

int main()
{
    Timer t1;
    auto trie = DictionaryLoader::loadFromFile("english.txt");
    std::cout << t1.stop() << std::endl;

    Timer t2;
    auto words = trie.search({2, 6, 4, 6, 6, 2, 2, 3, 8, 6, 7, 4, 3, 6, 3, 8, 4, 3, 4, 6, 3});
    std::cout << t2.stop() << std::endl;

    for (auto& w : words) {
        std::cout << w << std::endl;
    }
    return 0;
}


