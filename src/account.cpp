/**
 *@since 09/17/2017
 *@file account.cpp
 *@brief this file contain the implementation of the class Account.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 09/22/2017
 */
#include "../include/account.h"
#include <iostream>
#include <sstream>

/*static member of account to have a idea of how many accounts the bank have.*/

int Account::TotalAccounts = 0;

/*===Static Function of Account===*/

int Account::getTotalAccounts()
{
	return TotalAccounts;
}

/*====Constructor of the class Account=====*/

Account::Account(std::string _agency,std::string _number,TypeAccount _type_account,std::string _password)
{
	this->agency = _agency;
	this->number = _number;
	this->type_account = _type_account;
	this->password = _password;

	if(this->type_account == Special)
	{
		this->limit = 500.00;
	}
	TotalAccounts++;
}

/*==========Set methods============*/

void Account::setLimit(float _limit)
{
	this->limit = _limit;
}

void Account::setBalance(float _balance)
{
	this->balance = _balance;
}

/*===Add operations to the account, to can show the Bank Statement===*/

void Account::addOperation(Operation* _operations)
{
	this->operations.push_back(_operations);
}

/*=========Get Methods============*/

std::string Account::getAgency()
{
	return agency;
}
	
std::string Account::getNumber()
{
	return number;
}

std::string Account::getPassword()
{
	return password;
}

float Account::getLimit()
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

/*======Destructor of the class=======*/

Account::~Account()
{
	delete[] operations[0];
}

/*=======Overload of the operator "=="==========*/

bool Account::operator==(Account& acc)
{
	if(this->number == acc.getNumber())
	{
		return true;
	}

	else 
		return false;
}

/*===========Overload of the operator "<<"===========*/

std::ostream& operator <<(std::ostream& o,Account& acc)
{
	o << "Agency: " << acc.getAgency() << std::endl
	<< "Number: " << acc.getNumber() << std::endl;
	
	if(acc.getType_account() == Special)
	{
		o << "Type: Special" << std::endl << std::endl;
	}
	
	else if(acc.getType_account() == Normal)
	{
		o << "Type: Normal" << std::endl << std::endl;
	}

	return o;
}

/*=======Functions that return a iterator pointing to the vector operations===========*/

std::vector<Operation*>::iterator Account::operationsBEGIN()
{
	return this->operations.begin();
}

std::vector<Operation*>::iterator Account::operationsEND()
{
	return this->operations.end();
}