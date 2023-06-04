#include "CppUnitTest.h"
#include "../StackMachineLib/OperationMultiplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationMultiplicationUnitTest
{
	TEST_CLASS(OperationMultiplicationUnitTest)
	{
	public:

		TEST_METHOD(getName)
		{
			OperationMultiplication<int> mul;
			Assert::AreEqual(std::string("multiplication"), mul.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationMultiplication<int> mul;
			Stack<int> s;
			mul.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationMultiplication<int> mul;
			Stack<int> s;
			s.push(4);
			mul.execute(s);

			std::vector<int> expectedStack = { 0 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationMultiplication<int> mul;
			Stack<int> s;
			s.push(8);
			s.push(4);
			mul.execute(s);

			std::vector<int> expectedStack = { 32 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationMultiplication<int> mul;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(16);
			s.push(2);
			mul.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 32 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
