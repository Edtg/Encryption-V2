#pragma once
#include <string>

class Ceasar
{
public:

	static std::string Encrypt(std::string Plaintext, int Key);
	static std::string Decrypt(std::string CipherText, int Key);

	static std::string GetKeyTable(int Key);

	static std::string BruteDecrypt(std::string EncryptedText, std::string LookingFor, int MaxAttempts);

private:

};
