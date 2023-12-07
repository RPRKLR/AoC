#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
#include <map>

std::map<char, int> card_value_map{{'A', 1}, {'K', 2}, {'Q', 3}, {'J', 4}, {'T', 5}, {'9', 6}, {'8', 7}, {'7', 8}, {'6', 9}, {'5', 10}, {'4', 11}, {'3', 12}, {'2', 13}};
std::vector<char> cards{'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
    std::vector<std::string> hands;
    std::vector<int> bid_amounts;
    std::ifstream file("./input.txt");
    std::string input_string;
    while (std::getline(file, input_string))
    {
        std::stringstream ss(input_string);
        std::string word;
        ss >> word;
        hands.push_back(word);
        std::cout << "hand: " << word << std::endl;
        ss >> word;
        bid_amounts.push_back(std::stoi(word));
        std::cout << "bid: " << word << std::endl;
    }

    return 0;
}
