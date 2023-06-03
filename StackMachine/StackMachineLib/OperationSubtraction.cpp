#pragma once
#include "Operation.cpp"


template<typename T>
class OperationSubtraction : public Operation<T>
{
public:
	void execute(Stack<T>& s);
};

template<typename T>
void OperationSubtraction<T>::execute(Stack<T>& s)
{
	T a = topAndPopOnStack(s);
	T b = topAndPopOnStack(s);
	s.push(b - a);
}
