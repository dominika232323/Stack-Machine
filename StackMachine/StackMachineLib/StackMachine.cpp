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

	void executeAddition();
	void executeSubtraction();
	void executeMultiplication();
	void executeDivision();
	void executeModulo();
};

