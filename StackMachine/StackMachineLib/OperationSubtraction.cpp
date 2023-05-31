#pragma once
#include "Operation.cpp"


template<typename T>
class OperationSubtraction : public Operation
{
public:
	void execute(Stack& s);
};
