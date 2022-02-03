#include <t9trie/DictionaryLoader.hpp>

#include <iostream>

static void runCLI(const T9::Dictionary *dictionary);

int main(int, char**)
{
    auto dictionary = T9::DictionaryLoader::loadFromFile("./10k_english.txt", T9::DictionaryImplementation::HashMap);
    runCLI(dictionary.get());
    return 0;
}

void runCLI(const T9::Dictionary *dictionary)
{
    std::cout << "Press either:\n\t1) 2-9 button to type or \n\t2) # to start writing a word from the beginning or \n\t3) q to quit.\n...and confirm with enter\n";

    std::vector<int> buttons;
    while (true) {
        char button;
        std::cin >> button;
        switch (button) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                buttons.push_back(button - '0');
                const auto suggestions = dictionary->search(buttons);
                for (const auto &word : suggestions)
                {
                    std::cout << word << " ";
                }
                std::cout << std::endl;
                break;
            }
            case '#':
                buttons.clear();
                break;
            case 'q':
                return;
        }
    }
}
