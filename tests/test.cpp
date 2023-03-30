#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../Functions.h"

TEST_CASE("parse args")
{
	std::string param1 = "progName";

	{
		std::string param2 = "123";
		char* tstArgv[] = {param1.data(), param2.data(), NULL};
		REQUIRE(ParseArgs(2, tstArgv) == 123);
		REQUIRE(ParseArgs(1, tstArgv) == std::nullopt);
	}

	{
		std::string param2 = "";
		char* tstArgv[] = {param1.data(), param2.data(), NULL};
		REQUIRE(ParseArgs(1, tstArgv) == std::nullopt);
	}

	{
		std::string param2 = "123text";
		char* tstArgv[] = {param1.data(), param2.data(), NULL};
		REQUIRE(ParseArgs(1, tstArgv) == std::nullopt);
	}

	{
		std::string param2 = "text";
		char* tstArgv[] = {param1.data(), param2.data(), NULL};
		REQUIRE(ParseArgs(1, tstArgv) == std::nullopt);
	}

	{
		std::string param2 = "123456789012345678901234567890";
		char* tstArgv[] = {param1.data(), param2.data(), NULL};
		REQUIRE(ParseArgs(1, tstArgv) == std::nullopt);
	}
}

TEST_CASE("no prime numbers less 2")
{
	std::set<int> emptySet;
	std::set<int> tstSet = GeneratePrimeNumbersSet(1);
	REQUIRE(tstSet == emptySet);
	REQUIRE(tstSet.size() == 0);
}

TEST_CASE("upperBound == 2 => set.size == 1")
{
	{
		std::set<int> tstSet = GeneratePrimeNumbersSet(2);
		REQUIRE(tstSet.size() == 1);
	}
}

TEST_CASE("upperBound == 10 => set.size == 4")
{
	std::set<int> tstSet = GeneratePrimeNumbersSet(10);
	REQUIRE(tstSet.size() == 4);
	std::set<int> expectedSet = {2, 3, 5, 7};
	REQUIRE(expectedSet == tstSet);
}

TEST_CASE("upperBound == 100 => set.size == 25")
{
	std::set<int> tstSet = GeneratePrimeNumbersSet(100);
	REQUIRE(tstSet.size() == 25);
}

#ifdef NDEBUG
TEST_CASE("GeneratePrimeNumbersSet up to 100000000")
{
	std::set<int> tstSet = GeneratePrimeNumbersSet(100000000);
	REQUIRE(tstSet.size() == 5761455);
/*	BENCHMARK("big number")
	{
		return GeneratePrimeNumbersSet(100000000);
	};*/
}
#endif