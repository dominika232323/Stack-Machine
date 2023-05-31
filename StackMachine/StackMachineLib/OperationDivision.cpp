#pragma once
#include "Operation.cpp"


template<typename T>
class OperationDivison : public Operation
{
public:
	void execute(Stack& s);
};
