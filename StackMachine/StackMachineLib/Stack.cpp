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

