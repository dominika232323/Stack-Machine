#pragma once
#include "Operation.cpp"


template<typename T>
class OperationNot : public Operation<T>
{
public:
	using Operation<T>::canTopAndPopTwice;
	using Operation<T>::topAndPopOnStack;

	void execute(Stack<T>& s)
	{
		if (!s.isEmpty())
		{
			T a = topAndPopOnStack(s);
			//s.push(~a);
		}
	}

	std::string getName()
	{
		return "bitwise not";
	}
};
