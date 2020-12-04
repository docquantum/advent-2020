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

    size_t slopes = 5;
    int right[] = {1, 3, 5, 7, 1};
    int down[] = {1, 1, 1, 1, 2};
    int tree[slopes], open[slopes];
    // While size_t works fine for this example,
    // it could overflow as was the case with a plain int.
    size_t total = 1;
    for (size_t p = 0; p < slopes; p++)
    {
        tree[p] = 0;
        open[p] = 0;
        for (size_t i = 0; i < lines.size(); i+=down[p])
        {
            size_t pos = (i/down[p])*right[p] % lines[i].length();
            if(lines[i].at(pos) == '#')
                tree[p]++;
            else if(lines[i].at(pos) == '.')
                open[p]++;
            else
                std::cerr << lines[i].at(pos) << " is not a tree or open! x,y: ("
                    << pos << ", " << i << ")" << std::endl;
        }
        std::cout << "tree, open: (" << tree[p] << ", " << open[p] << ")\tr:d: "
            << right[p] << ":" << down[p] << std::endl;
        total *= tree[p];
    }
    
    std::cout << "Total Multiplied: " << total << std::endl;

    return 0;
}
