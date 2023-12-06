#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>

int countPossibilitiesInRace(long long int time_interval, long long int maximum_distance);

std::tuple<std::string, std::string> convertToFull(std::vector<int> time, std::vector<int> distance);

int main()
{
    std::ifstream file("./input.txt");
    std::string input_string;
    std::vector<int> interval_vector, distance_vector;
    int counter = 0;
    while (std::getline(file, input_string))
    {
        int pos = input_string.find(":");
        std::string new_str = input_string.substr(pos + 1);
        std::stringstream ss(new_str);
        std::string word;
        while (ss >> word)
        {
            std::cout << word << std::endl;
            if (counter == 0)
            {
                interval_vector.push_back(std::stoi(word));
            }
            else
            {
                distance_vector.push_back(std::stoi(word));
            }
        }
        counter++;
    }
    int part_one_result = 1;
    for (int i = 0; i < interval_vector.size(); i++)
    {
        part_one_result *= countPossibilitiesInRace(interval_vector[i], distance_vector[i]);
    }
    std::cout << "Part one result is: " << part_one_result << std::endl;
    auto [full_time, full_distance] = convertToFull(interval_vector, distance_vector);
    int part_two_result = countPossibilitiesInRace(std::stoll(full_time), std::stoll(full_distance));
    std::cout << "Part two result is: " << part_two_result << std::endl;

    return 0;
}

int countPossibilitiesInRace(long long int time_interval, long long int maximum_distance)
{
    long long int possibilities = 0;
    for (long long int i = 1; i < time_interval; i++)
    {
        long long int remaining_time = time_interval - i;
        long long int distance = i * remaining_time;
        if (distance > maximum_distance)
        {
            possibilities++;
        }
    }
    return possibilities;
}

std::tuple<std::string, std::string> convertToFull(std::vector<int> time, std::vector<int> distance)
{
    std::string t = "", d = "";
    for (int i = 0; i < time.size(); i++)
    {
        t += std::to_string(time[i]);
        d += std::to_string(distance[i]);
    }
    std::cout << "time: " << t << " distance: " << d << std::endl;
    return {t, d};
}