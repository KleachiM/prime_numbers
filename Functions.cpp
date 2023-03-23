#include "Functions.h"


std::optional<int> ParseArgs(int argc, char** argv)
{
	if (argc != 2)
	{
		return std::nullopt;
	}
	std::size_t pos;
	try
	{
		std::string s = argv[1];
		int parsedArg = std::stoi(s, &pos);
		if (pos == s.size())
		{
			return parsedArg;
		}
		return std::nullopt;
	}
	catch (const std::invalid_argument& ex)
	{
		return std::nullopt;
	}
	catch (const std::out_of_range& ex)
	{
		return std::nullopt;
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> primeNumbers;
	std::vector<bool> isPrimeNums;
}
