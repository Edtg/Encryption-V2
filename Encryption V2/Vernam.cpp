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

EncryptionPair Vernam::BruteDecrypt(std::string EncryptedString, std::string LookingFor, int MaxAttempts)
{
	EncryptionPair Output;
	if (LookingFor.length() <= 3)
	{
		Output.Type = EncryptionType::UNKNOWN;
		Output.Key = -2;
		return Output;
	}

	Output.Type = EncryptionType::Vernam;

	std::string DecryptedString;
	for (int i = 0; i < MaxAttempts; i++)
	{
		DecryptedString = Vernam::ProcessString(EncryptedString, i);
		std::size_t Found = DecryptedString.find(LookingFor);
		if (Found != std::string::npos)
		{
			Output.Ciphertext = EncryptedString;
			Output.Plaintext = DecryptedString;
			Output.Key = i;
			return Output;
		}
	}
	Output.Type = EncryptionType::UNKNOWN;
	Output.Key = -1;
	return Output;
}
