/**
 * DocQuantum (Daniel Shchur)
 * Advent of Code Day 2
 */

#include "../libs/utils.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main(int argc, char const *argv[])
{
    if(argc != 2) return 1;
    auto lines = docquantum::readFileAsLines(argv[1]);
    if(lines.size() == 0) return 2;

    int valid = 0;
    for (auto &&l : lines)
    {
        auto parts = docquantum::split(l, "(\\s+|-+|:+)");
        auto min = std::stoi(parts[0]);
        auto max = std::stoi(parts[1]);
        auto letter = parts[2].at(0);
        auto pass = parts[3];
        int count = 0;
        for (size_t i = 0; i < pass.size(); i++)
        {
            if (pass.at(i) == letter)
                count++;
        }
        if(count <= max && count >= min)
            valid++;
    }

    std::cout << "Valid passwords: " << valid << std::endl;

    return 0;
}
