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
			Assert::AreEqual(10, op.size());

			std::ostringstream outputStringStream;
			outputStringStream << op;
			std::string expected =
				"1. addition\n"
				"2. subtraction\n"
				"3. multiplication\n"
				"4. division\n"
				"5. bitwise and\n"
				"6. bitwise or\n"
				"7. bitwise xor\n"
				"8. bitwise not\n"
				"9. duplicate\n"
				"10. swap\n";
			Assert::AreEqual(expected, outputStringStream.str());
		}
		TEST_METHOD(operatorIndex)
		{
			OperationList<int> op;
			Assert::IsTrue(std::string("addition") == op[0]->getName());
			Assert::IsTrue(std::string("subtraction") == op[1]->getName());
			Assert::IsTrue(std::string("multiplication") == op[2]->getName());
			Assert::IsTrue(std::string("division") == op[3]->getName());
			Assert::IsTrue(std::string("bitwise and") == op[4]->getName());
			Assert::IsTrue(std::string("bitwise or") == op[5]->getName());
			Assert::IsTrue(std::string("bitwise xor") == op[6]->getName());
			Assert::IsTrue(std::string("bitwise not") == op[7]->getName());
			Assert::IsTrue(std::string("duplicate") == op[8]->getName());
			Assert::IsTrue(std::string("swap") == op[9]->getName());
		}
	};
}
