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

		if (choice == 1)
		{
			std::cout << "Give path to file with your stack: ";
			std::cin >> filename;
		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{
			std::cout << "Goodbye!" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Incorrect choice! Choose again." << std::endl;
			std::cout << std::endl;
			chooseStackMachineCreation(choice);
		}
	}

	std::cout << std::endl;
	operateOnStackMachine(stackMachine);

	return 0;
}
