#pragma once
#include "Operation.cpp"


template<typename T>
class OperationDivision : public Operation<T>
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

				if (a == 0)
				{
					s.push(a);
					throw std::invalid_argument("Cannot devide by zero.");
				}

				T b = topAndPopOnStack(s);
				s.push(b / a);
			}
			else if (!s.isEmpty())
			{
				topAndPopOnStack(s);
				s.push(0);
			}
		}
	}

	std::string getName()
	{
		return "division";
	}
};
