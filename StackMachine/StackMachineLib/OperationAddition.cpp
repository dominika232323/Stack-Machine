#pragma once
#include "Operation.cpp"


template<typename T>
class OperationAddition : public Operation<T>
{
public:
	void execute(Stack<T>& s);
};
