#pragma once

template<typename T>
class Stack
{
private:
	std::vector<T> stack;

public:
	Stack();
	Stack(T value);
	~Stack();

	void push(T value);
	T pop();
};

