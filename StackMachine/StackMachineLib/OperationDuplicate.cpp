#pragma once
#include "Operation.cpp"


template<typename T>
class OperationDuplicate : public Operation<T>
{
public:
	void execute(Stack<T>& s)
	{
		if (!s.isEmpty())
		{
			T a = s.top();
			s.push(a);
		}
	}

	std::string getName()
	{
		return "duplicate";
	}
};
