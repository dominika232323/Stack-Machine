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
			
			if (std::is_integral<T>::value)
				s.push(~a);
			else
				s.push(a.bitwiseNot());
		}
	}

	std::string getName()
	{
		return "bitwise not";
	}
};
