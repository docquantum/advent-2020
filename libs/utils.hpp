/** 
 * DocQuantum (Daniel Shchur)
 * Header only? Maybe. But this can open files, and stuff...
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

namespace docquantum
{
    std::vector<std::string> readFileAsLines(const std::string &filename)
    {
        std::ifstream file(filename);
        std::vector<std::string> lines = std::vector<std::string>();
        
        if(!file.is_open())
            throw "File not found!";
        
        lines.reserve(1000);
        
        int count = 0;
        std::string line;
        while(std::getline(file, line))
        {
            if(line.empty())
                continue;
            lines.push_back(line);
            count++;
        }
        file.close();
        lines.resize(count);
        return lines;
    }

    std::string readFileIntoLine(const std::string &filename)
    {
        std::ifstream file(filename);
        std::stringstream strStream;
        
        if(!file.is_open())
            throw "File not found!";
        
        strStream << file.rdbuf();
    
        return strStream.str();
    }

    /**
     * @brief Splits a string by the regex into a vector of tokens
     * 
     * @param s string to split
     * @param regex uncompiled regex to split by
     * @return std::vector<std::string> return vector of strings
     * 
     * https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
     */
    std::vector<std::string> split(const std::string &s, const std::string &regex)
    {
        std::regex reg(regex);
        std::sregex_token_iterator it{s.begin(), s.end(), reg, -1};
        std::vector<std::string> tokenized{it, {}};
        tokenized.erase(
            std::remove_if
            (
                tokenized.begin(),
                tokenized.end(),
                [](std::string const &s)
                {
                    return s.size() == 0;
                }
            ),
            tokenized.end()
        );

        return tokenized;
    }
}