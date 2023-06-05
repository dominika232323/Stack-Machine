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
			if (std::is_integral_v<T>)
			{
				T a = topAndPopOnStack(s);
				unsigned char* data = reinterpret_cast<unsigned char*>(&a);
				for (char c = *data; c; c = *++data) 
				{
					c = ~c;
				}
				a = *reinterpret_cast<T*>(data);
				s.push(a);
			}
		}
	}

	std::string getName()
	{
		return "bitwise not";
	}
};
