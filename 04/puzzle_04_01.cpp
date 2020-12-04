/**
 * DocQuantum (Daniel Shchur)
 * Advent of Code Day 4
 */

#include "../libs/utils.hpp"
#include <iostream>
#include <string>

struct Passport
{
    std::string byr = ""; //(Birth Year)
    std::string iyr = ""; //(Issue Year)
    std::string eyr = ""; //(Expiration Year)
    std::string hgt = ""; //(Height)
    std::string hcl = ""; //(Hair Color)
    std::string ecl = ""; //(Eye Color)
    std::string pid = ""; //(Passport ID)
    std::string cid = ""; //(Country ID)
};


int main(int argc, char const *argv[])
{
    if(argc != 2) return 1;
    auto line = docquantum::readFileIntoLine(argv[1]);
    if(line.length() == 0) return 2;

    int valid = 0;
    std::vector<Passport*> passports;
    auto groups = docquantum::split(line, "(\n|\n\r){2}");
    for (auto &&g : groups)
    {
        auto keyVals = docquantum::split(g, "\\s+");
        auto pass = new Passport();
        bool found[7] = {false};
        for (auto &&kv : keyVals)
        {
            auto vals = docquantum::split(kv, ":");
            if (vals[0] == "byr")
            {
                pass->byr = vals[1];
                found[0] = true;
            }
            else if (vals[0] == "iyr")
            {
                pass->iyr = vals[1];
                found[1] = true;
            }
            else if (vals[0] == "eyr")
            {
                pass->eyr = vals[1];
                found[2] = true;
            }
            else if (vals[0] == "hgt")
            {
                pass->hgt = vals[1];
                found[3] = true;
            }
            else if (vals[0] == "hcl")
            {
                pass->hcl = vals[1];
                found[4] = true;
            }
            else if (vals[0] == "ecl")
            {
                pass->ecl = vals[1];
                found[5] = true;
            }
            else if (vals[0] == "pid")
            {
                pass->pid = vals[1];
                found[6] = true;
            }
            else if (vals[0] == "cid")
            {
                pass->cid = vals[1];
            }
            else
            {
                std::cout << vals[0] << " not found in the struct!" << std::endl;
            }
        }
        if (found[0] && found[1] && found[2] && found[3] && found[4] && found[5] && found[6])
            valid++;

        passports.push_back(pass);
    }

    std::cout << "Valid passports: " << valid << std::endl;

    return 0;
}

