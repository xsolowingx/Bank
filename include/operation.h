/**
 *@since 09/17/2017
 *@file operation.h
 *@brief this file contain the declaration of the class Operation.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 09/22/2017
 */
#ifndef operation_h
#define operation_h

#include <string>
#include <ostream>

typedef enum strType
{
	Debit,
	Credit
}TypeOperation;

class Operation
{

private:
	std::string description;
	TypeOperation type_operation;
	float value;

public:
	Operation(std::string _description,TypeOperation _type_operation,float _value);
	float getValue();
	std::string getDescription();
	TypeOperation getType_operation();
	friend std::ostream& operator <<(std::ostream& o,Operation operation);
	
};

#endif