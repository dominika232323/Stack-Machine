#include "CppUnitTest.h"
#include "../StackMachineLib/OperationDivision.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationDivisionUnitTest
{
	TEST_CLASS(OperationDivisionUnitTest)
	{
	public:

		TEST_METHOD(getName)
		{
			OperationDivision<int> div;
			Assert::AreEqual(std::string("division"), div.getName());
		}
		TEST_METHOD(execute_ZeroElementsOnStack)
		{
			OperationDivision<int> div;
			Stack<int> s;
			div.execute(s);

			std::vector<int> expectedStack = { };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_OneElementOnStack)
		{
			OperationDivision<int> div;
			Stack<int> s;
			s.push(4);
			div.execute(s);

			std::vector<int> expectedStack = { 0 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_TwoElementsOnStack)
		{
			OperationDivision<int> div;
			Stack<int> s;
			s.push(8);
			s.push(4);
			div.execute(s);

			std::vector<int> expectedStack = { 2 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(execute_MoreThanTwoElementsOnStack)
		{
			OperationDivision<int> div;
			Stack<int> s;
			s.push(5);
			s.push(4);
			s.push(12);
			s.push(56);
			s.push(16);
			s.push(2);
			div.execute(s);

			std::vector<int> expectedStack = { 5, 4, 12, 56, 8 };
			Assert::IsTrue(expectedStack == s.getStack());
		}
		TEST_METHOD(divisionByZero)
		{
			Assert::ExpectException<std::invalid_argument>([]
			{
				OperationDivision<int> div;
				Stack<int> s;
				s.push(5);
				s.push(4);
				s.push(12);
				s.push(56);
				s.push(16);
				s.push(2);
				s.push(0);
				div.execute(s);
			});
		}
		TEST_METHOD(execute_TwoElementsOnStack_string)
		{
			OperationDivision<std::string> x;
			Stack<std::string> s;
			s.push("ala");
			s.push("kot");
			x.execute(s);

			std::vector<std::string> expectedStack = { "ala", "kot" };
			Assert::IsTrue(expectedStack == s.getStack());
		}
	};
}
