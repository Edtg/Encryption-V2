#include "Vernam.h"
#include <sstream>


std::string Vernam::ProcessString(std::string Input, int Key)
{
	std::ostringstream Output;
	for (unsigned int i = 0; i < Input.length(); ++i)
	{
		Output << (char)(Input[i] ^ Key);
	}
	return Output.str();
}

std::string Vernam::GetKeyTable(int Key)
{
	std::string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::ostringstream Table;
	Table << Alphabet << "\n";
	for (int i = 0; i < Alphabet.length(); ++i)
	{
		Table << (char)(Alphabet[i] ^ Key);
	}
	return Table.str();
}
