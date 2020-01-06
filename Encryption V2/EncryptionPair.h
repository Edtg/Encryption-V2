#pragma once
#include <string>
#include "EncryptionTypes.h"


struct EncryptionPair
{
	EncryptionType Type;
	std::string Plaintext;
	std::string Ciphertext;
	int Key;
};