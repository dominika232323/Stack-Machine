#pragma once
#include <vector>
#include <stdexcept>


template<typename T>
class Stack
{
private:
	std::vector<T> stack;

public:
	Stack();
	Stack(T value);
	Stack(std::vector<T> values);
	
	std::vector<T> getStack();
	size_t size();
	
	bool isEmpty();

	void push(T value);
	void pop();

	T top();

	friend std::ostream& operator<<(std::ostream& os, Stack<T>& stack)
	{
		std::vector<T> stackVector = stack.getStack();

		for (int i = stackVector.size() - 1; i >= 0; i--)
			os << stackVector[i] << "\n";

		return os;
	}
};

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
Stack<T>::Stack(T value)
{
	push(value);
}

template<typename T>
Stack<T>::Stack(std::vector<T> values)
{
	stack = values;
}

template<typename T>
std::vector<T> Stack<T>::getStack()
{
	return stack;
}

template<typename T>
size_t Stack<T>::size()
{
	return stack.size();
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return size() == 0;
}

template<typename T>
void Stack<T>::push(T value)
{
	stack.push_back(value);
}

template<typename T>
void Stack<T>::pop()
{
	if (!isEmpty())
		stack.pop_back();
}

template<typename T>
T Stack<T>::top()
{
	if (isEmpty())
		throw std::out_of_range("Empty stack!");

	return stack.back();
}
