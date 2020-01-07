// Encryption V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Ceasar.h"
#include "Vernam.h"
#include "EncryptionPair.h"

int MainMenu();
int OptionList(std::vector<std::string> Options);
bool ValidateOption(int Option, int AmountOfOptions);
int ValidateInt();

int main()
{
	//std::string Text = Ceasar::Encrypt("Hello World!", 5);
    //std::cout << Text << std::endl;
	//std::cout << Ceasar::BruteDecrypt(Text, "Hello").Plaintext << std::endl;
	while (MainMenu() == 1);


	//std::cout << Vernam::GetKeyTable(10);
}


int MainMenu()
{
	std::cout << "Welcome to my encryption program.\nChoose 1 of the options below by entering the number then pressing enter.\n";
	/*std::cout << "1) Ceasar Cipher\n";
	std::cout << "2) Vernam Cipher\n";
	std::cout << "3) Key Paris (WIP)\n";
	std::cout << "4) Exit\n";
	int ChosenOption = 0;
	bool IsValidOption = false;
	while (!IsValidOption)
	{
		std::cout << "> ";
		std::string Temp;
		std::cin >> Temp;
		try
		{
			ChosenOption = std::stoi(Temp);
			IsValidOption = ValidateOption(ChosenOption, 4);
		}
		catch(...)
		{
			std::cout << "Your input was not valid\n";
		}
	}*/

	int Option = OptionList({ "Ceasar Cipher", "Vernam Cipher", "Key Pairs (WIP)", "Exit" });

	int EncryptionType;

	std::string ToEncrypt;
	std::string ToDecrypt;
	std::string BruteLookFor;
	int Key;
	EncryptionPair Result;

	switch (Option)
	{
	case 1:
		std::cout << "Ceasar Cipher\nSelect what to do with the cipher:\n";
		EncryptionType = OptionList({ "Encrypt", "Decrypt", "Brute Crack", "Back" });
		switch (EncryptionType)
		{
		case 1:
			std::cout << "Enter a string to be encrypted:\n> ";
			std::getline(std::cin, ToEncrypt);
			std::cout << "Enter a key to encrypt the string:\n> ";
			Key = ValidateInt();
			std::cout << "Encrypted String:\n" << Ceasar::Encrypt(ToEncrypt, Key) << "\n";
			break;
		case 2:
			std::cout << "Enter a string to be decrypted:\n> ";
			std::getline(std::cin, ToDecrypt);
			std::cout << "Enter a key to decrypt the string:\n> ";
			Key = ValidateInt();
			std::cout << "Decrypted String:\n" << Ceasar::Decrypt(ToDecrypt, Key) << "\n";
			break;
		case 3:
			std::cout << "Enter a string to be decrypted:\n> ";
			std::getline(std::cin, ToDecrypt);
			std::cout << "Enter a word that may appear in the decrypted string:\n> ";
			std::getline(std::cin, BruteLookFor);
			Result = Ceasar::BruteDecrypt(ToDecrypt, BruteLookFor);
			std::cout << "Decrypted String:\n" << Result.Plaintext << "\nKey: " << Result.Key << "\n";
			break;
		case 4:
			return 1;
			break;
		}
		break;
	case 2:
		std::cout << "Vernam Cipher\nSelect what to do with the cipher:\n";
		EncryptionType = OptionList({ "Encrypt", "Decrypt" });
		break;
	case 3:
		std::cout << "Key Pairs (WIP)\n";
		EncryptionType = OptionList({ "Encrypt", "Decrypt" });
		break;
	case 4:
		return 0;
		break;
	}
	return 1;
}

int OptionList(std::vector<std::string> Options)
{
	for (int i = 0; i < Options.size(); ++i)
	{
		std::cout << i + 1 << ") " << Options[i] << "\n";
	}
	int ChosenOption = 0;
	bool IsValidOption = false;
	while (!IsValidOption)
	{
		std::cout << "> ";
		std::string Temp;
		std::getline(std::cin, Temp);
		try
		{
			ChosenOption = std::stoi(Temp);
			IsValidOption = ValidateOption(ChosenOption, 4);
		}
		catch (...)
		{
			std::cout << "Your input was not valid\n";
		}
	}
	return ChosenOption;
}

bool ValidateOption(int Option, int AmountOfOptions)
{
	if (Option > 0 && Option <= AmountOfOptions)
	{
		return true;
	}
	else
	{
		std::cout << "Your input was not between 1 and " << AmountOfOptions << "\n";
		return false;
	}
}

int ValidateInt()
{
	std::string Input;
	int Inputi;
	bool IsValid = false;
	while (!IsValid)
	{
		std::getline(std::cin, Input);
		try
		{
			Inputi = std::stoi(Input);
			IsValid = true;
		}
		catch (...)
		{
			IsValid = false;
		}
	}
	return Inputi;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
