#pragma once
#include "Operation.cpp"


template<typename T>
class OperationSubtraction : public Operation<T>
{
public:
	void execute(Stack<T>& s)
	{
		if (canTopAndPopTwice(s))
		{
			T a = topAndPopOnStack(s);
			T b = topAndPopOnStack(s);
			s.push(b - a);
		}
	}
};
