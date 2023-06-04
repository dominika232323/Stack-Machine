#pragma once
#include "Stack.cpp"


template<typename T>
class Operation
{
protected:
	T topAndPopOnStack(Stack<T>& s)
	{
		T result = s.top();
		s.pop();
		return result;
	}

	bool canTopAndPopTwice(Stack<T>& s)
	{
		if (s.size() >= 2)
			return true;
		return false;
	}

public:
	virtual void execute(Stack<T>& s) = 0;
	virtual std::string getName() = 0;

	friend std::ostream& operator<<(std::ostream& os, const Operation<T>& operation)
	{
		os << operation.getName();
		return os;
	}
};
