#pragma once
#include "Operation.cpp"


template<typename T>
class OperationOr : public Operation<T>
{
public:
	using Operation<T>::canTopAndPopTwice;
	using Operation<T>::topAndPopOnStack;

	void execute(Stack<T>& s)
	{
		if (s.isEmpty())
			return;

		if constexpr (std::is_integral_v<T>)
		{
			T a = topAndPopOnStack(s);
			T b = 0;

			if (!s.isEmpty())
				b = topAndPopOnStack(s);

			s.push(a | b);
		}
	}

	std::string getName()
	{
		return "bitwise or";
	}
};
