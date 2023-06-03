#pragma once
#include "Stack.cpp"


template<typename T>
class Operation
{
protected:
	T topAndPopOnStack(Stack<T>& s);

public:
	virtual void execute(Stack<T>& s) = 0;
};

/*
dodawanie
odejmowanie
mno¿enie
dzielenie
*/

template<typename T>
T Operation<T>::topAndPopOnStack(Stack<T>& s)
{
	T result = s.top();
	s.pop();
	return result;
}
