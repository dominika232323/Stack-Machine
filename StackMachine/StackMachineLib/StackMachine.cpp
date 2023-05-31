#pragma once
#include "Stack.cpp"


template<typename T>
class StackMachine
{
private:
	Stack<T> stack;

public:
	StackMachine();
	StackMachine(/*filename*/);					// czyta zapisany stos z pliku
	~StackMachine();

	void executeOperations(/*filename*/);		// wykonuje operacje z pliku
	void saveToFile(/*filename*/);

	void addition();
	void subtraction();
	void multiplication();
	void division();

	void push(T value);
	void pop();
};

