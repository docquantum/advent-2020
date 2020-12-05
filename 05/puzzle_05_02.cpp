/**
 * DocQuantum (Daniel Shchur)
 * Advent of Code Day 5
 */

#include "../libs/utils.hpp"
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
    if(argc != 2) return 1;
    auto lines = docquantum::readFileAsLines(argv[1]);
    if(lines.size() == 0) return 2;

    std::vector<int> ids;
    for (auto &&l : lines)
    {
        float rowh = 127;
        float rowl = 0;
        float colh = 7;
        float coll = 0;
        for (size_t i = 0; i < l.length(); i++)
        {
            switch (l.at(i))
            {
            case 'F':
                rowh /= 2;
                rowh += rowl / 2;
                break;
            case 'B':
                rowl = (rowh + rowl) / 2;
                break;
            case 'L':
                colh /= 2;
                colh += coll / 2;
                break;
            case 'R':
                coll = (colh + coll) / 2;
                break;
            default:
                std::cerr << "Unrecognized char! " << l.at(i) << std::endl;
                break;
            }
        }
        int row = std::round((rowh + rowl) / 2);
        int col = std::round((colh + coll) / 2);
        ids.push_back(row * 8 + col);
    }

    std::sort(ids.begin(), ids.end());
    int myID = -1;
    for (size_t i = 0; i < ids.size()-1; i++) {
        if (ids[i + 1] - ids[i] != 1)
        {
            myID = ids[i + 1] - 1; 
            break;
        }
    }   
    std::cout << "Your seat ID: " << myID << std::endl;

    return 0;
}

