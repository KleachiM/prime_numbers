#include "Functions.h"
#include <cmath>

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
	if (upperBound < 2)
	{
		return primeNumbers;
	}
	std::vector<bool> sieve(upperBound + 1, true);
	int screeningLimit = static_cast<int>(std::sqrt(upperBound));
	for (int i = 2; i <= screeningLimit; i++)
	{
		if (sieve[i])
		{
			for (int k = 0, j = i * i; j <= upperBound; j += i)
			{
				if (sieve[j])
				{
					sieve[j] = !sieve[i];
				}
				k++;
			}
		}
	}
	for (int i = 2; i <= upperBound; i++)
	{
		if (sieve[i])
		{
			primeNumbers.insert(primeNumbers.end(), i);
		}
	}
	return primeNumbers;
}
