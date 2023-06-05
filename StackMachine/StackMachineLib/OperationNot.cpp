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
			if constexpr (std::is_integral_v<T>)
			{
				T a = topAndPopOnStack(s);
				s.push(~a);
			}
		}
	}

	std::string getName()
	{
		return "bitwise not";
	}
};
