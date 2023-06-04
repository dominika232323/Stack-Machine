#include "CppUnitTest.h"
#include "../StackMachineLib/OperationNot.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationNotUnitTest
{
	TEST_CLASS(OperationNotUnitTest)
	{
	public:
		TEST_METHOD(getName)
		{
			OperationNot<int> n;
			Assert::AreEqual(std::string("bitwise not"), n.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationNot<int> not;
			Stack<int> s;
			not.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationNot<int> not;
			Stack<int> s;
			s.push(4);
			not.execute(s);

			std::vector<int> expectedStack = { -5 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationNot<int> not;
			Stack<int> s;
			s.push(4);
			s.push(-9);
			not.execute(s);

			std::vector<int> expectedStack = { 4, 8 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationNot<int> not;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			not.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 3, -17 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
