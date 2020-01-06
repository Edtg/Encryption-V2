#pragma once
#include <string>
#include "EncryptionPair.h"

class Vernam
{
public:

	static std::string ProcessString(std::string Plaintext, int Key);

	static std::string GetKeyTable(int Key);

	static EncryptionPair BruteDecrypt(std::string EncryptedString, std::string LookingFor, int MaxAttempts);

private:

};
