#include "CppUnitTest.h"
#include "../StackMachineLib/OperationAnd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationAndUnitTest
{
	TEST_CLASS(OperationAndUnitTest)
	{
	public:
		TEST_METHOD(getName)
		{
			OperationAnd<int> x;
			Assert::AreEqual(std::string("bitwise and"), x.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationAnd<int> x;
			Stack<int> s;
			x.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationAnd<int> x;
			Stack<int> s;
			s.push(4);
			x.execute(s);

			std::vector<int> expectedStack = { 0 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationAnd<int> x;
			Stack<int> s;
			s.push(5);
			s.push(4);
			x.execute(s);

			std::vector<int> expectedStack = { 4 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationAnd<int> x;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(3);
			s.push(16);
			x.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 0 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack_string)
		{
			OperationAnd<std::string> x;
			Stack<std::string> s;
			s.push("ala");
			s.push("kot");
			x.execute(s);

			std::vector<std::string> expectedStack = { "ala", "kot" };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
