#include <iostream>
#include "../StackMachineLib/StackMachine.cpp"


void createStackMachineChoice(int& choice)
{
	std::cout << "Choose 1 to read stack machine from file." << std::endl;
	std::cout << "Choose 2 to start a new stack machine." << std::endl;
	std::cout << "Choose 3 to exit." << std::endl;
	std::cout << "I choose: ";

	std::cin >> choice;
}


int main()
{
	std::cout << "Welcome to stack machine!" << std::endl;
	
	int choice;
	createStackMachineChoice(choice);

	StackMachine<double> stackMachine;
	std::string filename;
	bool correctChoice = false;

	while (correctChoice == false)
	{
		switch (choice)
		{
		case 1:
		{
			std::cout << "Give path to file with your stack: ";
			std::cin >> filename;
			correctChoice = true;
			break;
		}

		case 2:
		{
			correctChoice = true;
			break;
		}

		case 3:
		{
			std::cout << "Goodbye!" << std::endl;
			correctChoice = true;
			return 0;
		}

		default:
		{
			std::cout << "Incorrect choice! Choose again." << std::endl;
			createStackMachineChoice(choice);
			break;
		}
		}
	}

	return 0;
}
