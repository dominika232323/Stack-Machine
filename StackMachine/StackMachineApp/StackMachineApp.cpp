#include <iostream>
#include <sstream>
#include <string>
#include "../StackMachineLib/StackMachine.cpp"


void createStackMachineChoice(int& choice)
{
	std::cout << "Choose 1 to read stack machine from file." << std::endl;
	std::cout << "Choose 2 to start a new stack machine." << std::endl;
	std::cout << "Choose 3 to exit." << std::endl;
	std::cout << "I choose: ";
	std::cin >> choice;
}


template<typename T>
void operateOnStackMachine(StackMachine<T>& stackMachine)
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
	std::cout << "Choose 12 to exit." << std::endl;
}


int main()
{
	std::cout << "Welcome to stack machine!" << std::endl;
	
	int choice;
	createStackMachineChoice(choice);

	StackMachine<double> stackMachine;
	std::string filename;
	bool correctChoice = false;

	if (!isdigit(choice))
		choice = 10;

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
