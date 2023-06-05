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
	StackMachine()
	{

	}

	StackMachine(std::string filename)
	{

	}

	~StackMachine()
	{

	}

	void executeOperationsFromFile(std::string filename)
	{

	}

	void saveToFile(std::string filename)
	{

	}

	void exectueOperation(Operation<T>* operation)
	{
		operation->execute(stack);
	}

	void push(T value)
	{
		stack.push(value);
	}

	void pop()
	{
		stack.pop();
	}

	friend std::ostream& operator<<(std::ostream& os, StackMachine<T>& stackMachine)
	{
		std::vector<T> stackVector = stackMachine.stack.getStack();

		for (int i = 0; i < stackVector.size(); i++)
			os << stackVector[i] << " ";

		return os;
	}
};


