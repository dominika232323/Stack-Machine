#pragma once
#include "Operation.cpp"


template<typename T>
class OperationAddition : public Operation
{
public:
	void execute(Stack& s);
};
