#include "CppUnitTest.h"
#include "../StackMachineLib/StackMachine.cpp"
#include "../StackMachineLib/OperationList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackMachineUnitTest
{
	TEST_CLASS(StackMachineUnitTest)
	{
	public:
		
		TEST_METHOD(constructorDefault)
		{
			StackMachine<int> sm;

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "Empty stack.";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(constructorReadFile)
		{
			StackMachine<int> sm("/Users/domin/Desktop/studia/sem2_23L/PROI/23L-PROI-PROJ-1-Boguszewska-Dominika-Grabska-Joanna/saveExample.txt");

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "2 21 23 20 22 24 77 81 27 4 10 31 18 16 55 63 44 14 11 1 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(push)
		{
			StackMachine<int> sm;
			sm.push(1);
			sm.push(11);
			sm.push(14);
			sm.push(44);
			sm.push(63);
			sm.push(55);
			sm.push(16);

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "1 11 14 44 63 55 16 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(pop)
		{
			StackMachine<int> sm("/Users/domin/Desktop/studia/sem2_23L/PROI/23L-PROI-PROJ-1-Boguszewska-Dominika-Grabska-Joanna/saveExample.txt");
			sm.pop();
			sm.pop();
			sm.pop();
			sm.pop();
			sm.pop();

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "2 21 23 20 22 24 77 81 27 4 10 31 18 16 55 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(executeOperation_addition)
		{
			StackMachine<int> sm("/Users/domin/Desktop/studia/sem2_23L/PROI/23L-PROI-PROJ-1-Boguszewska-Dominika-Grabska-Joanna/saveExample.txt");
			OperationList<int> op;
			sm.exectueOperation(op[0]);

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "2 21 23 20 22 24 77 81 27 4 10 31 18 16 55 63 44 14 12 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(executeOperation_subtraction)
		{
			StackMachine<int> sm("/Users/domin/Desktop/studia/sem2_23L/PROI/23L-PROI-PROJ-1-Boguszewska-Dominika-Grabska-Joanna/saveExample.txt");
			OperationList<int> op;
			sm.exectueOperation(op[1]);

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "2 21 23 20 22 24 77 81 27 4 10 31 18 16 55 63 44 14 10 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(executeOperation_or)
		{
			StackMachine<int> sm("/Users/domin/Desktop/studia/sem2_23L/PROI/23L-PROI-PROJ-1-Boguszewska-Dominika-Grabska-Joanna/saveExample.txt");
			OperationList<int> op;
			sm.exectueOperation(op[5]);

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "2 21 23 20 22 24 77 81 27 4 10 31 18 16 55 63 44 14 11 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(executeOperation_duplicate)
		{
			StackMachine<int> sm("/Users/domin/Desktop/studia/sem2_23L/PROI/23L-PROI-PROJ-1-Boguszewska-Dominika-Grabska-Joanna/saveExample.txt");
			OperationList<int> op;
			sm.exectueOperation(op[8]);

			std::ostringstream outputStringStream;
			outputStringStream << sm;
			std::string expected = "2 21 23 20 22 24 77 81 27 4 10 31 18 16 55 63 44 14 11 1 1 ";
			Assert::AreEqual(expected, outputStringStream.str());
		}
	};
}
