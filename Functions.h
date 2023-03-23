#ifndef PRIME_NUMBERS_FUNCTIONS_H
#define PRIME_NUMBERS_FUNCTIONS_H

#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <vector>

std::optional<int> ParseArgs(int argc, char* argv[]);
std::set<int> GeneratePrimeNumbersSet(int upperBound);

#endif //PRIME_NUMBERS_FUNCTIONS_H
