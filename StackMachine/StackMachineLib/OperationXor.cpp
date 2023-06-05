#pragma once
#include "Operation.cpp"


template<typename T>
class OperationXor : public Operation<T>
{
public:
	using Operation<T>::canTopAndPopTwice;
	using Operation<T>::topAndPopOnStack;

	void execute(Stack<T>& s)
	{
		T a, b = 0;
		if (!s.isEmpty())
			a = topAndPopOnStack(s);

		if (canTopAndPopTwice(s))
			b = topAndPopOnStack(s);
		
		if (std::is_integral<T>::value)
			s.push(a ^ b);
		else
			throw std::invalid_argument("Cannot perform bitwise xor.");
	}

	std::string getName()
	{
		return "bitwise xor";
	}
};
