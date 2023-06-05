#pragma once
#include "Operation.cpp"


template<typename T>
class OperationSubtraction : public Operation<T>
{
public:
	void execute(Stack<T>& s);
};
