#include "CppUnitTest.h"
#include "../StackMachineLib/OperationList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationListUnitTest
{
	TEST_CLASS(OperationListUnitTest)
	{
	public:
		TEST_METHOD(constructor)
		{
			OperationList<int> op;

			std::ostringstream outputStringStream;
			outputStringStream << op;
			std::string expected =
				"1. addition\n"
				"2. subtraction\n"
				"3. multiplication\n"
				"4. division\n"
				"5. bitwise xor\n"
				"6. bitwise not\n"
				"7. swap\n";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(operatorIndex)
		{
			OperationList<int> op;
			Assert::IsTrue(std::string("addition") == op[0]->getName());
			Assert::IsTrue(std::string("subtraction") == op[1]->getName());
			Assert::IsTrue(std::string("multiplication") == op[2]->getName());
			Assert::IsTrue(std::string("division") == op[3]->getName());
			Assert::IsTrue(std::string("bitwise xor") == op[4]->getName());
			Assert::IsTrue(std::string("bitwise not") == op[5]->getName());
			Assert::IsTrue(std::string("swap") == op[6]->getName());
		}
	};
}
