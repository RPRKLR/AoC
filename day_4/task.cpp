#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Card
{
    // Might need it in the future.
    // int card_number;
    std::vector<int> winning_numbers{};
    std::vector<int> your_numbers{};
    int match{};
};

int matchCards(std::vector<Card> &cards);

int main()
{
    std::vector<Card> cards;
    std::ifstream file("./input.txt");
    std::string input_string;
    std::vector<int> int_vec;
    while (std::getline(file, input_string))
    {
        Card card;
        bool after_winning = false;
        int pos = input_string.find(":");
        std::string new_str = input_string.substr(pos + 1);
        std::stringstream ss(new_str);
        std::string word;
        while (ss >> word)
        {
            if (word == "|")
            {
                after_winning = true;
                continue;
            }
            if (!after_winning)
            {
                int temp_n = std::stoi(word);
                card.winning_numbers.push_back(temp_n);
            }
            else
            {
                int temp_n = std::stoi(word);
                card.your_numbers.push_back(temp_n);
            }
        }
        cards.push_back(card);
    }
    std::cout << matchCards(cards) << std::endl;
    return 0;
}

int matchCards(std::vector<Card> &cards)
{
    int output = 0;
    for (auto &card : cards)
    {
        for (const auto winning_num : card.winning_numbers)
        {
            for (const auto your_num : card.your_numbers)
            {
                if (winning_num == your_num)
                {
                    card.match++;
                    std::cout << "match added " << card.match << std::endl;
                }
            }
        }
        if (card.match < 2 && card.match != 0)
            output += 1;
        else
            output += std::pow(2, card.match - 1);
        std::cout << output << std::endl;
    }

    return output;
}