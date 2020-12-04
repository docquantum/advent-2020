/**
 * DocQuantum (Daniel Shchur)
 * Advent of Code Day 4
 */

#include "../libs/utils.hpp"
#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
    if(argc != 2) return 1;
    auto line = docquantum::readFileIntoLine(argv[1]);
    if(line.length() == 0) return 2;

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
                found[0] = true;
            }
            else if (vals[0] == "iyr")
            {
                found[1] = true;
            }
            else if (vals[0] == "eyr")
            {
                found[2] = true;
            }
            else if (vals[0] == "hgt")
            {
                found[3] = true;
            }
            else if (vals[0] == "hcl")
            {
                found[4] = true;
            }
            else if (vals[0] == "ecl")
            {
                found[5] = true;
            }
            else if (vals[0] == "pid")
            {
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

