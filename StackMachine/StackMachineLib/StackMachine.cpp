#pragma once
#include <iostream>
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

	friend std::ostream& operator<<(std::ostream& os, const StackMachine<T>& stackMachine)
	{
		os << "aaa";
		return os;
	}
};

template<typename T>
StackMachine<T>::StackMachine()
{
}

template<typename T>
StackMachine<T>::StackMachine(std::string filename)
{
}

template<typename T>
StackMachine<T>::~StackMachine()
{
}

template<typename T>
void StackMachine<T>::executeOperationsFromFile(std::string filename)
{
}

template<typename T>
void StackMachine<T>::saveToFile(std::string filename)
{
}

template<typename T>
void StackMachine<T>::exectueAddition()
{
}

template<typename T>
void StackMachine<T>::exectueSubtraction()
{
}

template<typename T>
void StackMachine<T>::exectueMultiplication()
{
}

template<typename T>
void StackMachine<T>::exectueDivision()
{
}

template<typename T>
void StackMachine<T>::exectueAnd()
{
}

template<typename T>
void StackMachine<T>::exectueOr()
{
}

template<typename T>
void StackMachine<T>::exectueXor()
{
}

template<typename T>
void StackMachine<T>::exectueNot()
{
}

template<typename T>
void StackMachine<T>::exectueSwap()
{
}

template<typename T>
void StackMachine<T>::exectueDuplicate()
{
}

template<typename T>
void StackMachine<T>::push(T value)
{
}

template<typename T>
void StackMachine<T>::pop()
{
}
