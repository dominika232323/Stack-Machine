#include "userInput.cpp"


int main()
{
	std::cout << "Welcome to stack machine!" << std::endl;
	
	StackMachine<int> stackMachine = createStackMachine();
	

	std::cout << std::endl;
	operateOnStackMachine(stackMachine);

	return 0;
}
