#include "CppUnitTest.h"
#include "../StackMachineLib/OperationSubtraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationSubtractionUnitTest
{
	TEST_CLASS(OperationSubtractionTests)
	{
	public:

		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationSubtraction<int> sub;
			Stack<int> s;
			sub.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationSubtraction<int> sub;
			Stack<int> s;
			s.push(4);
			sub.execute(s);

			std::vector<int> expectedStack = { -4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationSubtraction<int> sub;
			Stack<int> s;
			s.push(5);
			s.push(4);
			sub.execute(s);

			std::vector<int> expectedStack = { 1 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationSubtraction<int> sub;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			sub.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, -13 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
