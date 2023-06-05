#include <iostream>
#include <sstream>
#include <string>
#include "../StackMachineLib/StackMachine.cpp"
#include "../StackMachineLib/OperationList.cpp"


inline void chooseStackMachineCreation(int& choice)
{
	std::cout << "Choose 1 to read stack machine from file." << std::endl;
	std::cout << "Choose 2 to start a new stack machine." << std::endl;
	std::cout << "Choose 3 to exit." << std::endl;
	std::cout << "I choose: ";

	while (!(std::cin >> choice))
	{
		std::cout << "Invalid input. Please enter an integer: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}


template<typename T>
inline void chooseOperation(int& choice, OperationList<T>& opList)
{
	std::cout << opList;
	std::cout << opList.size() + 1 << ". " << "push" << std::endl;
	std::cout << opList.size() + 2 << ". " << "pop" << std::endl;
	std::cout << opList.size() + 3 << ". " << "execute operations from file" << std::endl;
	std::cout << opList.size() + 4 << ". " << "save to file" << std::endl;
	std::cout << opList.size() + 5 << ". " << "exit" << std::endl;
	
	std::cout << "I choose: ";
	std::cin >> choice;
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
	OperationList<double> opList;
	int choice = 0;
	std::string filename;


	while (choice != 15)
	{
		chooseOperation(choice, opList);

		switch (choice)
		{
		case 1:
			printStack(stackMachine);
			break;

		case 2:
			printStack(stackMachine);
			break;

		case 3:
			printStack(stackMachine);
			break;

		case 4:
			printStack(stackMachine);
			break;

		case 5:
			printStack(stackMachine);
			break;

		case 6:
			printStack(stackMachine);
			break;

		case 7:
			printStack(stackMachine);
			break;

		case 8:
			printStack(stackMachine);
			break;

		case 9:
			printStack(stackMachine);
			break;

		case 10:
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