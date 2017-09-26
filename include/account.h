/**
 *@since 09/17/2017
 *@file account.h
 *@brief this file contain the declaration of the class Account.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 09/22/2017
 */
#ifndef account_h
#define account_h

#include "operation.h"
#include <vector>
#include <ostream>

typedef enum str_especial
{
	Special,
	Normal
}TypeAccount;

typedef enum str_type
{
	Correct,
	Wrong
}TypeHelper;

class Account
{
private:
std::string agency;
std::string number;
std::string password;

TypeAccount type_account;

float limit;
std::vector<Operation*> operations;
float balance;

public:
	static int TotalAccounts;
	static int getTotalAccounts();
	
	Account(std::string _agency,std::string _number,TypeAccount _type_account,std::string _password);
	void setLimit(float _limit);
	void setBalance(float _balance);
	void addOperation(Operation* _operations);
	std::vector<Operation*>::iterator operationsBEGIN();
	std::vector<Operation*>::iterator operationsEND();

	std::string getAgency();
	std::string getNumber();
	std::string getPassword();
	float getLimit();
	TypeAccount getType_account();
	
	float getBalance();
	~Account();
	bool operator==(Account& acc);
	friend std::ostream& operator <<(std::ostream& o,Account& acc);
};

#endif