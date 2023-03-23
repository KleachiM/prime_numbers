#include <catch2/catch_test_macros.hpp>
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