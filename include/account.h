#ifndef account_h
#define account_h

#include "operation.h"
#include <vector>

typedef enum str_especial
{
	Special,
	Normal
}TypeAccount;

class Account
{
private:
std::string agency;
std::string number;
TypeAccount type_account;
std::string limit;
std::vector<Operation*> operations;
float balance;

public:
	static int TotalAccounts;
	static int getTotalAccounts();
	Account(std::string _agency,std::string _number,TypeAccount _type_account,float _balance);
	void setLimit(std::string _limit);
	void addOperation(Operation* _operations);
	std::string getAgency();
	std::string getNumber();
	std::string getLimit();
	TypeAccount getType_account();
	float getBalance();
	void extract();
	~Account();
};

void createAccount(std::vector<Account*>& accounts);

void beginMessage();

#endif