#pragma once
#include <string>

class Ceasar
{
public:

	static std::string Encrypt(std::string Plaintext, int Key);
	static std::string Decrypt(std::string CipherText, int Key);

	static std::string GetKeyTable(int Key);

private:

	std::string Aplhabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

};
