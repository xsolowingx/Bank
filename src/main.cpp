#include "../include/account.h"
#include "../include/operation.h"
#include <iostream>

int main()
{
	std::vector<Account*> accounts;
	beginMessage();
	std::string optionCreateAccount;
	while(std::getline(std::cin , optionCreateAccount) )
	{
		if(optionCreateAccount == "n")
		{
			std::cout << "Quiting..." << std::endl;
			return -1;
		}

		if(optionCreateAccount == "s")
		{
			createAccount(accounts);
			break;
		}

	}



	return 0;
}