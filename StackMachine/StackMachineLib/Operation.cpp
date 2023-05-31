#pragma once
#include "Stack.cpp"


template<typename T>
class Operation
{
public:
	virtual void execute(Stack& s) = 0;
};

/*
dodawanie
odejmowanie
mno¿enie
dzielenie
*/