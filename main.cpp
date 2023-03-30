#include "Functions.h"

int main(int argc, char* argv[]) {

	auto upperBound = ParseArgs(argc, argv);
	if (!upperBound)
	{
		std::cout << "Invalid argument! Usage: ./prime_nubmers <positive integer>" << std::endl;
		return EXIT_FAILURE;
	}

	std::set<int> primeNumbers = GeneratePrimeNumbersSet(*upperBound);
	std::copy(primeNumbers.begin(), primeNumbers.end(),
		std::ostream_iterator<int>(std::cout, "\n"));

	return EXIT_SUCCESS;
}
