#include "CppUnitTest.h"
#include "../StackMachineLib/OperationOr.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationOrUnitTest
{
	TEST_CLASS(OperationOrUnitTest)
	{
	public:
		TEST_METHOD(getName)
		{
			OperationOr<int> x;
			Assert::AreEqual(std::string("bitwise or"), x.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationOr<int> x;
			Stack<int> s;
			x.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationOr<int> x;
			Stack<int> s;
			s.push(4);
			x.execute(s);

			std::vector<int> expectedStack = { 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationOr<int> x;
			Stack<int> s;
			s.push(5);
			s.push(4);
			x.execute(s);

			std::vector<int> expectedStack = { 5 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationOr<int> x;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			x.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 19 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
