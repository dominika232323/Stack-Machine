#pragma once
#include "Stack.cpp"
#include "StackMachine.cpp"


template<typename T>
class ReadFromFile
{
public:
	static Stack<T> readStackFromFile(std::string filename)
	{
		std::ifstream inputFile(filename);

		if (inputFile.is_open())
		{
			std::vector<T> numbers;
			T number;

			while (inputFile >> number)
			{
				numbers.push_back(number);
			}

			Stack<T> stack(numbers);

			inputFile.close();
			return stack;
		}
		else
		{
			throw std::exception("Cannot open file.");
		}
	}

	static typeid stackTypeid(Stack<T>& stack)
	{
		return typeid(T);
	}
};
