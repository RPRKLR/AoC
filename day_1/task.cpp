/**
 * @file main.cpp
 * @author Péter Dvorák (pdvorak370@gmail.com)
 * @brief Source file for the main file.
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright take it as you wish lol (c) 2022
 *
 */
// #include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>


int getNumbersFromText(std::string &input_string);

int countOutputVals(std::vector<int> &vec);

const std::vector<std::string> words = {"one", "two","three","four","five","six","seven","eight","nine"};

int getNumberFromTextWithWords(std::string &input);



int main()
{
    std::ifstream file("./input.txt");
    std::string input_string;   
    std::vector<int> int_vec;
    while (std::getline(file, input_string))
    {
        // std::cout << input_string << std::endl;
        int_vec.push_back(getNumbersFromText(input_string));
        getNumberFromTextWithWords(input_string);
    }
    std::cout << countOutputVals(int_vec) << std::endl;
    return 0;
}

int getNumbersFromText(std::string &input_string)
{
    std::vector<int> numbers;
    std::string output_val = "";
    for(const auto &ch : input_string)
    {
        if(ch >= 48 && ch <= 57)
        {
            std::string s = "";
            s += ch;
            numbers.push_back(std::stoi(s));
        }
    }
    if(numbers.size() == 1)
    {
        output_val += std::to_string(numbers.at(0));
        output_val += std::to_string(numbers.at(0));
        return std::stoi(output_val);
    }
    else
    {
        output_val += std::to_string(numbers.at(0));
        output_val += std::to_string(numbers.at(numbers.size() - 1));
        return std::stoi(output_val);
    }
    return std::stoi(output_val);
}

int countOutputVals(std::vector<int> &vec)
{
    int output_val = 0;
    for(const auto &number : vec)
        output_val += number;
    return output_val;
}


int getNumberFromTextWithWords(std::string &input)
{
    int last_num_pos = 0, first_num_pos = INFINITY;
    int last_word_pos = 0, first_word_pos = INFINITY;
    int num_of_words = 0, num_of_nums = 0;
    std::vector<int> numbers;
    for(const auto &word : words)
    {
        int found = input.find(word);
        if (found != -1)
        {
            std::cout << word << " found in " << found << std::endl;
            num_of_words++;
        }

        if (last_word_pos < found)
        {
            last_word_pos = found + word.size() - 1;
            std::cout << input << " word found: " << word << " " << "in pos " << last_word_pos << " word size " << word.size() << std::endl;
        }
        if(first_word_pos > found)
        {
            first_word_pos = found + word.size() - 1;
        }
    }
    for(size_t i = 0; i < input.size(); i++)
    {
        if(input[i] >= 48 && input[i] <= 57)
        {
            num_of_nums++;
            if (last_num_pos < i)
            {
                last_num_pos = i;
            }
            if(first_num_pos > i)
            {
                first_num_pos = i;
            }
        }
    }
    std::string final_num = "";
    if(num_of_nums == 1 && num_of_words == 0)
    {   
        final_num += input[last_num_pos] + input[last_num_pos];
        return std::stoi(final_num);
    }
    else if(num_of_words == 1 && num_of_nums == 0)
    {
        final_num += input[last_word_pos] + input[last_word_pos];
        return std::stoi(final_num);     
    }
    if(first_num_pos > first_word_pos)
    {
        final_num
    }
    else
    {}
    if(last_num_pos > last_word_pos)
    {
        final_num += 
    }
    else
    {}
}