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
	};
}
