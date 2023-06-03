#pragma once
#include "Stack.cpp"
#include "OperationAddition.cpp"
#include "OperationSubtraction.cpp"
#include "OperationMultiplication.cpp"
#include "OperationDivision.cpp"
#include "OperationXor.cpp"
#include "OperationNot.cpp"
#include "OperationSwap.cpp"


template<typename T>
class StackMachine
{
private:
	Stack<T> stack;

public:
	StackMachine();
	StackMachine(std::string filename);					// czyta zapisany stos z pliku
	~StackMachine();

	void executeOperationsFromFile(std::string filename);		// wykonuje operacje z pliku
	void saveToFile(std::string filename);				// zapisuje stos do pliku

	void exectueAddition();					// dzia³ania na stosie jakby ktoœ chcia³ u¿ywaæ StackMachine bez pliku z operacjami
	void exectueSubtraction();
	void exectueMultiplication();
	void exectueDivision();

	void exectueAnd();
	void exectueOr();
	void exectueXor();
	void exectueNot();

	void exectueSwap();
	void exectueDuplicate();

	void push(T value);
	void pop();			// lub T pop();
};

