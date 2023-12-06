/**
 * @file main.cpp
 * @author Péter Dvorák (pdvorak370@gmail.com)
 * @brief Source file for the main file.
 * @version 0.1
 * @date 2023-12.01
 *
 * @copyright Copyright take it as you wish lol (c) 2022
 *
 */
// #include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int getNumbersFromText(std::string &input_string);

int countOutputVals(std::vector<int> &vec);

std::string replaceWords(std::string &input);

const std::vector<std::string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const std::vector<std::string> changed_words = {"on1ne", "tw2wo", "thre3hree", "fou4our", "fiv5ive", "si6ix", "seve7even", "eigh8ight", "nin9ine"};

int main()
{
    std::ifstream file("./input.txt");
    std::string input_string;
    std::vector<int> int_vec;
    while (std::getline(file, input_string))
    {
        std::string i_str = replaceWords(input_string);
        int_vec.push_back(getNumbersFromText(i_str));
    }
    std::cout << countOutputVals(int_vec) << std::endl;
    return 0;
}

int getNumbersFromText(std::string &input_string)
{
    std::vector<int> numbers;
    std::string output_val = "";
    for (const auto &ch : input_string)
    {
        if (ch >= 48 && ch <= 57)
        {
            std::string s = "";
            s += ch;
            numbers.push_back(std::stoi(s));
        }
    }
    if (numbers.size() == 1)
    {
        output_val += std::to_string(numbers.at(0));
        output_val += std::to_string(numbers.at(0));
        std::cout << output_val << std::endl;
        return std::stoi(output_val);
    }
    else
    {
        output_val += std::to_string(numbers.at(0));
        output_val += std::to_string(numbers.at(numbers.size() - 1));
        std::cout << output_val << std::endl;
        return std::stoi(output_val);
    }
    std::cout << output_val << std::endl;
    return std::stoi(output_val);
}

int countOutputVals(std::vector<int> &vec)
{
    int output_val = 0;
    for (const auto &number : vec)
        output_val += number;
    return output_val;
}

std::string replaceWords(std::string &input)
{
    int position = 0;
    for (int i = 0; i < words.size(); i++)
    {
        while (position != -1)
        {
            position = input.find(words[i]);
            if (position != -1)
            {
                input.replace(position, words[i].size(), changed_words[i]);
            }
        }
        position = 0;
    }
    return input;
}