#pragma once
#include "Operation.cpp"


template<typename T>
class OperationMultiplication : public Operation<T>
{
public:
	void execute(Stack<T>& s);
};
