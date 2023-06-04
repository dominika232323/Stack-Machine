#pragma once
#include "Operation.cpp"


template<typename T>
class OperationDivision : public Operation<T>
{
public:
	void execute(Stack<T>& s)
	{
		if (canTopAndPopTwice(s))
		{
			T a = topAndPopOnStack(s);
			
			if (a == 0)
				throw std::invalid_argument("Cannot devide by zero.");

			T b = topAndPopOnStack(s);
			s.push(b / a);
		}
		else if (!s.isEmpty())
		{
			topAndPopOnStack(s);
			s.push(0);
		}
	}

	std::string getName()
	{
		return "division";
	}
};
