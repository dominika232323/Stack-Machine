#include "CppUnitTest.h"
#include "../StackMachineLib/OperationAddition.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationAdditionUnitTest
{
	TEST_CLASS(OperationAdditionUnitTest)
	{
	public:
		TEST_METHOD(getName)
		{
			OperationAddition<int> add;
			Assert::AreEqual(std::string("addition"), add.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationAddition<int> add;
			Stack<int> s;
			add.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationAddition<int> add;
			Stack<int> s;
			s.push(4);
			add.execute(s);

			std::vector<int> expectedStack = { 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationAddition<int> add;
			Stack<int> s;
			s.push(5);
			s.push(4);
			add.execute(s);

			std::vector<int> expectedStack = { 9 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationAddition<int> add;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			add.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 19 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
