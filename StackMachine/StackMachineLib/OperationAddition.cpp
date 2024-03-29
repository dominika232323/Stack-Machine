#pragma once
#include "Operation.cpp"


template<typename T>
class OperationAddition : public Operation<T>
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
			s.push(b + a);
		}
	}

	std::string getName()
	{
		return "addition";
	}
};
