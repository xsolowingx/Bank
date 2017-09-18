#include "../include/account.h"
#include <iostream>

int Account::TotalAccounts = 0;

int Account::getTotalAccounts()
{
	return TotalAccounts;
}

Account::Account(std::string _agency,std::string _number,TypeAccount _type_account,float _balance)
{
	this->agency = _agency;
	this->number = _number;
	this->type_account = _type_account;
	this->balance = _balance;
	TotalAccounts++;
}

void Account::setLimit(std::string _limit)
{
	this->limit = _limit;
}


void Account::addOperation(Operation* _operations)
{
	this->operations.push_back(_operations);
}

std::string Account::getAgency()
{
	return agency;
}
	
std::string Account::getNumber()
{
	return number;
}

std::string Account::getLimit()
{
	return limit;
}

TypeAccount Account::getType_account()
{
	return type_account;
}

float Account::getBalance()
{
	return balance;
}

void Account::extract()
{
	for(std::vector<Operation*>::iterator it = operations.begin(); it != operations.end() ; it++)
	{
		std::cout << (**it);
	}
}

Account::~Account()
{
	delete[] operations[0];
	TotalAccounts--;
}
/*========functions outside the class=====*/

void beginMessage()
{
	std::cout << "==================================" << std::endl;
	std::cout << ">>Welcome to the Bank simulator! " << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "would you like to create a account?" << std::endl;
}

void createAccount(std::vector<Account*>& accounts)
{
	std::cout << "lul" << std::endl;
}