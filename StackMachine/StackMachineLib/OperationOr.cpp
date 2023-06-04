#pragma once
#include "Operation.cpp"


template<typename T>
class OperationOr : public Operation<T>
{
public:
	void execute(Stack<T>& s)
	{
		if (canTopAndPopTwice(s))
		{
			T a = topAndPopOnStack(s);
			T b = topAndPopOnStack(s);
			s.push(a | b);
		}
		else if (!s.isEmpty())
		{
			T a = topAndPopOnStack(s);
			s.push(0 | a);
		}
	}

	std::string getName()
	{
		return "bitwise or";
	}
};
