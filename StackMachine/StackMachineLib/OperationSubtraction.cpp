#pragma once
#include "Operation.cpp"


template<typename T>
class OperationSubtraction : public Operation<T>
{
public:
	using Operation<T>::canTopAndPopTwice;
	using Operation<T>::topAndPopOnStack;

	void execute(Stack<T>& s)
	{
		if constexpr (std::is_arithmetic_v<T>)
		{
			if (canTopAndPopTwice(s))
			{
				T a = topAndPopOnStack(s);
				T b = topAndPopOnStack(s);
				s.push(b - a);
			}
			else if (!s.isEmpty())
			{
				T a = topAndPopOnStack(s);
				s.push(-1 * a);
			}
		}
	}

	std::string getName()
	{
		return "subtraction";
	}
};
