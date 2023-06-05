#include "CppUnitTest.h"
#include "../StackMachineLib/OperationSwap.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationSwapUnitTest
{
	TEST_CLASS(OperationSwapUnitTest)
	{
	public:

		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationSwap<int> swap;
			Stack<int> s;
			swap.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationSwap<int> swap;
			Stack<int> s;
			s.push(4);
			swap.execute(s);

			std::vector<int> expectedStack = { 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationSwap<int> swap;
			Stack<int> s;
			s.push(4);
			s.push(-9);
			swap.execute(s);

			std::vector<int> expectedStack = { -9, 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationSwap<int> swap;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			swap.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 16, 3 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
