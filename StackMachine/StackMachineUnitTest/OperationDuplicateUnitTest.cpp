#include "CppUnitTest.h"
#include "../StackMachineLib/OperationDuplicate.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationDuplicateUnitTest
{
	TEST_CLASS(OperationDuplicateUnitTest)
	{
	public:
		TEST_METHOD(getName)
		{
			OperationDuplicate<int> x;
			Assert::AreEqual(std::string("duplicate"), x.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationDuplicate<int> x;
			Stack<int> s;
			x.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationDuplicate<int> x;
			Stack<int> s;
			s.push(4);
			x.execute(s);

			std::vector<int> expectedStack = { 4, 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationDuplicate<int> x;
			Stack<int> s;
			s.push(5);
			s.push(4);
			x.execute(s);

			std::vector<int> expectedStack = { 5, 4, 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MDuplicateeThanTwoElementsOnStack)
		{
			OperationDuplicate<int> x;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			x.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 3, 16, 16 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
