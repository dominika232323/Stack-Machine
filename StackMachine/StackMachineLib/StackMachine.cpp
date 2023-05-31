#pragma once
#include "Stack.cpp"
#include "OperationAddition.cpp"
#include "OperationSubtraction.cpp"
#include "OperationMultiplication.cpp"
#include "OperationDivision.cpp"


template<typename T>
class StackMachine
{
private:
	Stack<T> stack;

public:
	StackMachine();
	//StackMachine(/*filename*/);					// czyta zapisany stos z pliku
	~StackMachine();

	void executeOperations(/*filename*/);		// wykonuje operacje z pliku
	void saveToFile(/*filename*/);				// zapisuje stos do pliku

	void addition();					// dzia³ania na stosie jakby ktoœ chcia³ u¿ywaæ StackMachine bez pliku z operacjami
	void subtraction();
	void multiplication();
	void division();

	void push(T value);
	void pop();			// lub T pop();
};

