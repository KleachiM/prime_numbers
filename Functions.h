#ifndef PRIME_NUMBERS_FUNCTIONS_H
#define PRIME_NUMBERS_FUNCTIONS_H

#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <vector>//TODO убрать лишние инклуды из заголовочного

std::optional<int> ParseArgs(int argc, char* argv[]);
std::set<int> GeneratePrimeNumbersSet(int upperBound);
bool IsPrime(int number);
#endif //PRIME_NUMBERS_FUNCTIONS_H
