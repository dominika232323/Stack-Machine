#pragma once
#include "Operation.cpp"


template<typename T>
class OperationMultiplication : public Operation
{
public:
	void execute(Stack& s);
};
