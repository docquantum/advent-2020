#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char** argv)
{
	if(argc != 2) return 1;
	
	std::ifstream file(argv[1]);
	
	if(!file.is_open()) return 2;
	
	std::vector<int> nums = std::vector<int>();
	nums.reserve(1000);
	
	int count;
	std::string line;
	while(std::getline(file, line))
	{
		if(line.empty()) continue;
		nums.push_back(std::stoi(line));
		count++;
	}
	file.close();
	nums.resize(count);
	
	for(int i=0; i < nums.size(); i++)
	{
		for(int j=i+1; j < nums.size(); j++)
		{
			if(nums[i] + nums[j] == 2020)
			{
				std::cout << nums[i] << " x " << nums[j] << std::endl;
				std::cout << nums[i] * nums[j] << std::endl;
				break;
			}
		}
	}
	return 0;
}
