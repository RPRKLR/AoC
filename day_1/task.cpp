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

int main()
{
    std::ifstream file("./input.txt");
    std::string input_string;   
    std::vector<int> int_vec;
    while (std::getline(file, input_string))
    {
        // std::cout << input_string << std::endl;
        int_vec.push_back(getNumbersFromText(input_string));
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
