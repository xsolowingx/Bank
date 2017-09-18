#include "../include/operation.h"

int Operation::quantityOperations = 0;

Operation::Operation(std::string _description,TypeOperation _type_operation,float _value)
{
	this->description = _description;
	this->type_operation = _type_operation;
	this->value = _value;
	quantityOperations++;
}

int Operation::getQuantityOperations()
{
	return quantityOperations;
}

float Operation::getValue()
{
	return value;
}

std::string Operation::getDescription()
{
	return description;
}

TypeOperation Operation::getType_operation()
{
	return type_operation;
}

std::ostream& operator <<(std::ostream& o,Operation operation)
{
	o << "Description: " << operation.getDescription() << std::endl
	<< "Operation: " << operation.getType_operation() << std::endl
	<< "Value: " << operation.getValue() << std::endl;
	return o;
}
