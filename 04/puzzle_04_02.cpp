/**
 * DocQuantum (Daniel Shchur)
 * Advent of Code Day 4
 */

#include "../libs/utils.hpp"
#include <iostream>
#include <string>
#include <regex>

int main(int argc, char const *argv[])
{
    if(argc != 2) return 1;
    auto line = docquantum::readFileIntoLine(argv[1]);
    if(line.length() == 0) return 2;
    std::regex hclReg = std::regex("#((?:[0-9a-f]){6})");
    std::regex eclReg = std::regex("(amb|blu|brn|gry|grn|hzl|oth)");
    std::regex pidReg = std::regex("((?:[0-9]){9})");

    int valid = 0;
    auto groups = docquantum::split(line, "(\n|\n\r){2}");
    for (auto &&g : groups)
    {
        auto keyVals = docquantum::split(g, "\\s+");
        bool found[7] = {false};
        for (auto &&kv : keyVals)
        {
            auto vals = docquantum::split(kv, ":");
            if (vals[0] == "byr")
            {
                int yr = std::stoi(vals[1]);
                if (yr >= 1920 && yr <= 2002)
                    found[0] = true;
            }
            else if (vals[0] == "iyr")
            {
                int yr = std::stoi(vals[1]);
                if (yr >= 2010 && yr <= 2020)
                    found[1] = true;
            }
            else if (vals[0] == "eyr")
            {
                int yr = std::stoi(vals[1]);
                if (yr >= 2020 && yr <= 2030)
                    found[2] = true;
            }
            else if (vals[0] == "hgt")
            {
                if (vals[1].find("in") != std::string::npos)
                {
                    int h = std::stoi(vals[1]);
                    if (h >= 59 && h <= 76)
                        found[3] = true;
                }
                else if (vals[1].find("cm") != std::string::npos)
                {
                    int h = std::stoi(vals[1]);
                    if (h >= 150 && h <= 193)
                        found[3] = true;   
                }
            }
            else if (vals[0] == "hcl")
            {
                if (vals[1].length() == 7 && std::regex_match(vals[1], hclReg))
                    found[4] = true;
            }
            else if (vals[0] == "ecl")
            {
                if (vals[1].length() == 3 && std::regex_match(vals[1], eclReg))
                    found[5] = true; 
            }
            else if (vals[0] == "pid")
            {
                if (vals[1].length() == 9 && std::regex_match(vals[1], pidReg))
                    found[6] = true;
            }
            else if (vals[0] == "cid")
            {
                continue;
            }
            else
            {
                std::cout << vals[0] << " not found in the struct!" << std::endl;
            }
        }
        if (found[0] && found[1] && found[2] && found[3] && found[4] && found[5] && found[6])
            valid++;

    }

    std::cout << "Valid passports: " << valid << std::endl;

    return 0;
}

