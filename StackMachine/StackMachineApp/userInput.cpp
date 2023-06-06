#include <iostream>
#include <sstream>
#include <string>
#include "../StackMachineLib/StackMachine.cpp"


inline void chooseStackMachineCreation(int& choice)
{
	std::cout << "Choose 1 to read stack machine from file." << std::endl;
	std::cout << "Choose 2 to start a new stack machine." << std::endl;
	std::cout << "Choose 3 to exit." << std::endl;
	std::cout << "I choose: ";
	std::cin >> choice;
}


inline StackMachine<int> createStackMachine()
{
	int choice = 0;
	std::string filename;

	while (choice != 3)
	{
		chooseStackMachineCreation(choice);

		if (choice == 1)
		{
			std::cout << "Give path to file with your stack: ";
			std::cin >> filename;

			StackMachine<int> sm(filename);
			return sm;
		}
		else if (choice == 2)
		{
			StackMachine<int> sm;
			return sm;
		}
		else if (choice == 3)
		{
			std::cout << "Goodbye!" << std::endl;
			exit(0);
		}
		else
		{
			std::cout << "Incorrect choice! Choose again." << std::endl;
			std::cout << std::endl;
			chooseStackMachineCreation(choice);
		}
	}
}


inline void chooseOperation(int& choice, OperationList<int>& opList)
{
	std::cout << opList;
	std::cout << opList.size() + 1 << ". " << "push" << std::endl;
	std::cout << opList.size() + 2 << ". " << "pop" << std::endl;
	std::cout << opList.size() + 3 << ". " << "clear" << std::endl;
	std::cout << opList.size() + 4 << ". " << "save to file" << std::endl;
	std::cout << opList.size() + 5 << ". " << "exit" << std::endl;
	
	std::cout << "I choose: ";
	std::cin >> choice;
}


inline void printStack(StackMachine<int>& stackMachine)
{
	std::cout << std::endl;
	std::cout << "Your stack: " << std::endl;
	std::cout << stackMachine << std::endl;
	std::cout << std::endl;
}


inline void operateOnStackMachine(StackMachine<int>& stackMachine)
{
	OperationList<int> opList;
	int choice = 0;
	std::string filename;


	while (choice != opList.size() + 5)
	{
		chooseOperation(choice, opList);

		if (choice >= 1 && choice <= opList.size())
		{
			stackMachine.exectueOperation(opList[choice - 1]);
			printStack(stackMachine);
		}
		else if (choice == opList.size() + 1)
		{
			std::cout << "Give value to push to stack: ";

			int value;
			std::cin >> value;

			stackMachine.push(value);
			printStack(stackMachine);
		}
		else if (choice == opList.size() + 2)
		{
			stackMachine.pop();
			printStack(stackMachine);
		}
		else if (choice == opList.size() + 3)
		{
			stackMachine.clear();
			printStack(stackMachine);
		}
		else if (choice == opList.size() + 4)
		{
			std::cout << "Give path to file where you want to save your stack: ";
			std::cin >> filename;

			stackMachine.saveToFile(filename);
		}
		else if (choice == opList.size() + 5)
		{
			std::cout << "Goodbye!" << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Incorrect operation!" << std::endl;
			std::cout << std::endl;
		}
	}
}