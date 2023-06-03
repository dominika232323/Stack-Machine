#include <iostream>
#include "../StackMachineLib/StackMachine.cpp"


int main()
{
	std::cout << "Welcome to stack machine!" << std::endl;
	std::cout << "Choose 1 to read stack machine from file." << std::endl;
	std::cout << "Choose 2 to start a new stack machine." << std::endl;
	std::cout << "Choose 3 to exit." << std::endl;
	std::cout << "I choose: ";

	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << "Give path to file with your stack: ";

		std::string filename;
		std::cin >> filename;

		StackMachine<int> stackMachine(filename);
		break;

	case 2:
		std::cout << "Choose 1 to operate on ints." << std::endl;
		std::cout << "Choose 2 to operate on doubles." << std::endl;

		int choice2;
		std::cin >> choice2;

		switch (choice2)
		{
		case 1:
			StackMachine<int> stackMachine;
			break;

		case 2:
			StackMachine<double> stackMachine;
			break;

		default:

		}
	}

}
