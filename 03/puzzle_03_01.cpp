/**
 * DocQuantum (Daniel Shchur)
 * Advent of Code Day 3
 */

#include "../libs/utils.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    if(argc != 2) return 1;
    auto lines = docquantum::readFileAsLines(argv[1]);
    if(lines.size() == 0) return 2;

    size_t tree = 0;
    size_t open = 0;
    for (size_t i = 0; i < lines.size(); i++)
    {
        size_t pos = i*3 % lines[i].length();
        if(lines[i].at(pos) == '#')
            tree++;
        else if(lines[i].at(pos) == '.')
            open++;
        else
            std::cerr << lines[i].at(pos) << " is not a tree or open!" << std::endl;
    }
    std::cout << "tree, open: (" << tree << ", " << open << ")" << std::endl;

    return 0;
}
