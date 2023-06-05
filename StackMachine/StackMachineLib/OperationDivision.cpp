#pragma once
#include "Operation.cpp"


template<typename T>
class OperationDivison : public Operation<T>
{
public:
	void execute(Stack<T>& s);
};
