#pragma once
#include "Operation.cpp"


template<typename T>
class OperationMultiplication : public Operation<T>
{
public:
	using Operation<T>::canTopAndPopTwice;
	using Operation<T>::topAndPopOnStack;

	void execute(Stack<T>& s)
	{
		if (canTopAndPopTwice(s))
		{
			T a = topAndPopOnStack(s);
			T b = topAndPopOnStack(s);

			s.push(b * a);
		}
		else if (!s.isEmpty())
		{
			topAndPopOnStack(s);
			s.push(0);
		}
	}

	std::string getName()
	{
		return "multiplication";
	}
};
