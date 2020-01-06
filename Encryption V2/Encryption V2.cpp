// Encryption V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Ceasar.h"
#include "Vernam.h"
#include "EncryptionPair.h"

int OptionMenu();
int OptionList(std::vector<std::string> Options);
bool ValidateOption(int Option, int AmountOfOptions);

int main()
{
	//std::string Text = Ceasar::Encrypt("Hello World!", 5);
    //std::cout << Text << std::endl;
	//std::cout << Ceasar::BruteDecrypt(Text, "Hello", 100).Plaintext << std::endl;
	while (OptionMenu() == 1)
	{
		
	}
	//std::cout << Vernam::GetKeyTable(10);
}


int OptionMenu()
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

	switch (Option)
	{
	case 1:
		std::cout << "Ceasar Cipher\n";
		break;
	case 2:
		std::cout << "Vernam Cipher\n";
		break;
	case 3:
		std::cout << "Key Pairs (WIP)\n";
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
		std::cin >> Temp;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
