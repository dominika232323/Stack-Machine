#include "CppUnitTest.h"
#include "../StackMachineLib/OperationXor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationXorUnitTest
{
	TEST_CLASS(OperationXorUnitTest)
	{
	public:

		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationXor<int> xor;
			Stack<int> s;
			xor.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationXor<int> xor;
			Stack<int> s;
			s.push(4);
			xor.execute(s);

			std::vector<int> expectedStack = { 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationXor<int> xor;
			Stack<int> s;
			s.push(5);
			s.push(4);
			xor.execute(s);

			std::vector<int> expectedStack = { 1 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationXor<int> xor;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			xor.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 19 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
