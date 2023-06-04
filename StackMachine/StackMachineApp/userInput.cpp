#include <iostream>
#include <sstream>
#include <string>
#include "../StackMachineLib/StackMachine.cpp"


void invalidInput(int& choice)
{
	while (!(std::cin >> choice))
	{
		std::cout << "Invalid input. Please enter an integer: ";
		std::cin.unget();
	}
}


inline void chooseStackMachineCreation(int& choice)
{
	std::cout << "Choose 1 to read stack machine from file." << std::endl;
	std::cout << "Choose 2 to start a new stack machine." << std::endl;
	std::cout << "Choose 3 to exit." << std::endl;
	std::cout << "I choose: ";

	invalidInput(choice);
}


inline void chooseOperation(int& choice)
{
	std::cout << "Choose 1 to execute addition." << std::endl;
	std::cout << "Choose 2 to execute subtraction." << std::endl;
	std::cout << "Choose 3 to execute multiplication." << std::endl;
	std::cout << "Choose 4 to execute divison." << std::endl;
	std::cout << "Choose 5 to execute bitwise and." << std::endl;
	std::cout << "Choose 6 to execute bitwise or." << std::endl;
	std::cout << "Choose 7 to execute bitwise xor." << std::endl;
	std::cout << "Choose 8 to execute bitwise not." << std::endl;
	std::cout << "Choose 9 to execute swap." << std::endl;
	std::cout << "Choose 10 to execute duplicate." << std::endl;
	std::cout << "Choose 11 to execute operation from txt file." << std::endl;
	std::cout << "Choose 12 to push value to stack." << std::endl;
	std::cout << "Choose 13 to pop value from stack." << std::endl;
	std::cout << "Choose 14 to save stack machine to txt file." << std::endl;
	std::cout << "Choose 15 to exit." << std::endl;
	std::cout << "I choose: ";	
}


template<typename T>
void printStack(StackMachine<T>& stackMachine)
{
	std::cout << "Your stack: " << std::endl;
	std::cout << stackMachine << std::endl;
}


template<typename T>
inline void operateOnStackMachine(StackMachine<T>& stackMachine)
{
	int choice = 0;
	std::string filename;


	while (choice != 15)
	{
		chooseOperation(choice);
		//invalidInput(choice);

		switch (choice)
		{
		case 1:
			stackMachine.exectueAddition();
			printStack(stackMachine);
			break;

		case 2:
			stackMachine.exectueSubtraction();
			printStack(stackMachine);
			break;

		case 3:
			stackMachine.exectueMultiplication();
			printStack(stackMachine);
			break;

		case 4:
			stackMachine.exectueDivision();
			printStack(stackMachine);
			break;

		case 5:
			stackMachine.exectueAnd();
			printStack(stackMachine);
			break;

		case 6:
			stackMachine.exectueOr();
			printStack(stackMachine);
			break;

		case 7:
			stackMachine.exectueXor();
			printStack(stackMachine);
			break;

		case 8:
			stackMachine.exectueNot();
			printStack(stackMachine);
			break;

		case 9:
			stackMachine.exectueDuplicate();
			printStack(stackMachine);
			break;

		case 10:
			stackMachine.exectueDuplicate();
			printStack(stackMachine);
			break;

		case 11:
			std::cout << "Give path to file with your operations: ";
			std::cin >> filename;

			stackMachine.executeOperationsFromFile(filename);
			printStack(stackMachine);
			break;

		case 12:
			std::cout << "Give value to push to stack: ";

			T value;
			std::cin >> value;

			stackMachine.push(value);
			printStack(stackMachine);
			break;

		case 13:
			stackMachine.pop();
			printStack(stackMachine);
			break;

		case 14:
			std::cout << "Give path to file where you want to save your stack: ";
			std::cin >> filename;

			stackMachine.saveToFile(filename);
			break;

		case 15:
			std::cout << "Goodbye!" << std::endl;
			break;

		default:
			std::cout << "Incorrect operation!" << std::endl;
		}
	}
}