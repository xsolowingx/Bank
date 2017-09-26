/**
 *@since 09/17/2017
 *@file main.cpp
 *@brief this file contain the main program.
 *@author Matheus de Jesus Leandro de Medeiros
 *@sa bank.cpp for the implementation of each function.
 *@date 09/22/2017
 */
#include "../include/account.h"
#include "../include/operation.h"
#include "../include/bank.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

int main()
{
	std::vector<Account*> accounts;
	beginMessage();
	menu();
	std::string UserOption;
	int NumberOption;

	while(std::getline(std::cin , UserOption) )
	{
		std::stringstream ss(UserOption);
		ss >> NumberOption;
		
		switch (NumberOption)
		{
			case 0:
			{	/*=====Leave the program=======*/
				std::cout << "Quiting..." << std::endl;
				return -1;
			}

			case 1:
			{	/*======Create a account=======*/
				createAccount(accounts);	
				
				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 2:
			{	 /*=======Make a deposit=======*/
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				deposit(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 3:
			{	/*=======Make a  Withdraw=======*/
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				withdraw(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 4:
			{	/*====Delete a account=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				deleteAccount(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 5:
			{	/*=====List all accounts of the bank=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				listAccounts(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 6:
			{	/*======Make a transference========*/
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				transfer(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 7:
			{	
				/*======See the balance of your account=========*/
				
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				seeBalance(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 8:
			{	
				/*=====See the bank statement of your account======*/
				
				if(accounts.empty())
				{
					std::cout << "You haven't created a account yet" << std::endl;
					break;
				}

				BankStatement(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			default:
			{	
				/*=====Default Option=====*/

				std::cout << "Invalid option" << std::endl;
				break;
			}
		}
	}
	return 0;
}