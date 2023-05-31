#pragma once


template<typename T>
class Operation
{
public:
	virtual void execute(T a, T b) = 0;
};

/*
dodawanie
odejmowanie
mno¿enie
dzielenie
*/