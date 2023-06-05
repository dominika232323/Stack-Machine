#include "CppUnitTest.h"
#include "../StackMachineLib/Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTest
{
	TEST_CLASS(StackUnitTest)
	{
	public:
		TEST_METHOD(constructorDefault)
		{
			Stack<int> s;
			std::vector<int> expected = {};
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(0), s.size());
			Assert::IsTrue(s.isEmpty());
		}
		TEST_METHOD(constructorValue)
		{
			Stack<int> s(6);
			std::vector<int> expected = { 6 };
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(1), s.size());
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(constructorVector)
		{
			std::vector<int> v = { 6, 5, 4, 3, 2, 1 };
			Stack<int> s(v);
			Assert::IsTrue(v == s.getStack());
			Assert::AreEqual(size_t(6), s.size());
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(push_toEmpty)
		{
			Stack<int> s;
			s.push(6);
			std::vector<int> expected = { 6 };
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(1), s.size());
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(push)
		{
			Stack<int> s(6);
			s.push(12);
			s.push(16);
			s.push(14);
			s.push(25);
			std::vector<int> expected = { 6, 12, 16, 14, 25 };
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(5), s.size());
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(pop_fromEmpty)
		{
			Stack<int> s;
			s.pop();
			std::vector<int> expected = { };
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(0), s.size());
			Assert::IsTrue(s.isEmpty());
		}
		TEST_METHOD(pop)
		{
			Stack<int> s(6);
			s.push(12);
			s.push(16);
			s.push(14);
			s.push(25);
			s.pop();
			s.pop();
			std::vector<int> expected = { 6, 12, 16 };
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(3), s.size());
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(top_fromEmpty)
		{
			Assert::ExpectException<std::out_of_range>([]
			{
				Stack<int> s;
				s.top();
			});
		}
		TEST_METHOD(top)
		{
			Stack<int> s(6);
			s.push(12);
			s.push(16);
			s.push(14);
			s.push(25);
			int a = s.top();
			std::vector<int> expected = { 6, 12, 16, 14, 25 };
			Assert::IsTrue(expected == s.getStack());
			Assert::AreEqual(size_t(5), s.size());
			Assert::IsFalse(s.isEmpty());
			Assert::AreEqual(25, a);
		}
		TEST_METHOD(operatorStream)
		{
			Stack<int> s;
			s.push(12);
			s.push(16);
			s.push(14);
			s.push(25);
			std::ostringstream outputStringStream;
			outputStringStream << s;
			std::string expected =
				"25\n"
				"14\n"
				"16\n"
				"12\n";
			Assert::AreEqual(expected, outputStringStream.str());
		}
	};
}
