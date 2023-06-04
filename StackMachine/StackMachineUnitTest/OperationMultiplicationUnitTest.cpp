#include "CppUnitTest.h"
#include "../StackMachineLib/OperationMultiplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OperationMultiplicationUnitTest
{
	TEST_CLASS(OperationMultiplicationUnitTest)
	{
	public:

		TEST_METHOD(getName)
		{
			OperationMultiplication<int> mul;
			Assert::AreEqual(std::string("multiplication"), mul.getName());
		}
	};
}
