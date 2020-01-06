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

std::string Ceasar::BruteDecrypt(std::string EncryptedText, std::string LookingFor, int MaxAttempts)
{
	if (LookingFor.length() <= 3)
		return "String To Look For is Too Short";

	std::string DecryptedString;
	for (int i = 0; i < MaxAttempts; i++)
	{
		DecryptedString = Ceasar::Decrypt(EncryptedText, i);
		std::size_t Found = DecryptedString.find(LookingFor);
		if (Found != std::string::npos)
			return DecryptedString;
	}
	return "Unable To Decrypt";
}
