#pragma once
#include "Operation.cpp"


template<typename T>
class OperationNot : public Operation<T>
{
public:
	void execute(Stack<T>& s)
	{
		if (!s.isEmpty())
		{
			T a = topAndPopOnStack(s);
			s.push(~a);
		}
	}
};
