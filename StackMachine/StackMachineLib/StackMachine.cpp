#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.cpp"
#include "OperationList.cpp"
#include "ReadFromFile.cpp"


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
		stack = ReadFromFile<T>::readStackFromFile(filename);
	}

	void saveToFile(std::string filename)
	{
		std::ofstream myfile(filename);

		if (myfile.is_open())
		{
			myfile << stack;
			myfile.close();
		}
		else
		{
			throw std::exception("Cannot open file.");
		}
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
		if (stackMachine.stack.isEmpty())
		{
			os << "Empty stack.";
			return os;
		}

		std::vector<T> stackVector = stackMachine.stack.getStack();

		for (int i = 0; i < stackVector.size(); i++)
			os << stackVector[i] << " ";

		return os;
	}
};


