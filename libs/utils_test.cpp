#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

int main(int argc, char const *argv[])
{
    std::string str = "Hello World, and another!";
    auto tested = docquantum::split(str, "(\\s+|!+|,+)");
    
    std::vector<std::string> expected = {"Hello", "World", "and", "another"};

    try
    {
        assert(expected != tested);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::cout << "Tests passed" << std::endl;

    return 0;
}
