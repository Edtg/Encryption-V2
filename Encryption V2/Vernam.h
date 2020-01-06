#pragma once
#include <string>

class Vernam
{
public:

	static std::string ProcessString(std::string Plaintext, int Key);

	static std::string GetKeyTable(int Key);

private:

};
