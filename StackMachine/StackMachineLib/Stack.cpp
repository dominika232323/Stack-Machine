#pragma once
#include <vector>


template<typename T>
class Stack
{
private:
	std::vector<T> stack;

public:
	Stack();
	Stack(T value);
	~Stack();

	std::vector<T> getStack();
	size_t size();
	
	bool isEmpty();

	void push(T value);
	T pop();

	T top();
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
Stack<T>::~Stack()
{
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
T Stack<T>::pop()
{
	return stack.pop_back();
}

template<typename T>
T Stack<T>::top()
{
	return stack.end();
}
