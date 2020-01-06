#include "Ceasar.h"
#include <sstream>


std::string Ceasar::Encrypt(std::string Plaintext, int Key)
{
	std::ostringstream EncryptedString;
	for (unsigned int i = 0; i < Plaintext.length(); ++i)
	{
		EncryptedString << (char)(Plaintext[i] + Key);
	}
	return EncryptedString.str();
}

std::string Ceasar::Decrypt(std::string CipherText, int Key)
{
	std::ostringstream DecryptedString;
	for (unsigned int i = 0; i < CipherText.length(); ++i)
	{
		DecryptedString << (char)(CipherText[i] - Key);
	}
	return DecryptedString.str();
}

std::string Ceasar::GetKeyTable(int Key)
{
	std::string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::ostringstream Table;
	Table << Alphabet << "\n";
	Table << Alphabet.substr(Alphabet.length() - Key, Key);
	Table << Alphabet.substr(0, Alphabet.length() - Key);
	return Table.str();
}

EncryptionPair Ceasar::BruteDecrypt(std::string EncryptedString, std::string LookingFor, int MaxAttempts)
{
	EncryptionPair Output;
	if (LookingFor.length() <= 3)
	{
		Output.Type = EncryptionType::UNKNOWN;
		Output.Key = -2;
		return Output;
	}

	Output.Type = EncryptionType::Ceasar;

	std::string DecryptedString;
	for (int i = 0; i < MaxAttempts; i++)
	{
		DecryptedString = Ceasar::Decrypt(EncryptedString, i);
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
