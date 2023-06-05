#include "userInput.cpp"


int main()
{
	std::cout << "Welcome to stack machine!" << std::endl;
	
	int choice = 5;
	StackMachine<int> stackMachine;
	std::string filename;

	while (choice > 3)
	{
		chooseStackMachineCreation(choice);

		switch (choice)
		{
		case 1:
			std::cout << "Give path to file with your stack: ";
			std::cin >> filename;
			break;

		case 2:
			break;

		case 3:
			std::cout << "Goodbye!" << std::endl;
			return 0;

		default:
			std::cout << "Incorrect choice! Choose again." << std::endl;
			chooseStackMachineCreation(choice);
			break;
		}
	}

	operateOnStackMachine(stackMachine);

	return 0;
}
