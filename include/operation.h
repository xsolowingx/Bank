#ifndef operation_h
#define operation_h

#include <string>
#include <ostream>

typedef enum strType
{
	debit,
	credit
}TypeOperation;

class Operation
{

private:
	std::string description;
	TypeOperation type_operation;
	float value;

public:
	static int quantityOperations;
	static int getQuantityOperations();
	Operation(std::string _description,TypeOperation _type_operation,float _value);
	float getValue();
	std::string getDescription();
	TypeOperation getType_operation();
	friend std::ostream& operator <<(std::ostream& o,Operation operation);
	
};

#endif