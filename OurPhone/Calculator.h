#pragma once
#include "stdafx.h"

using namespace std;

class Calculator
{
private:
	string str;
	float a_;
	float b_;
	char znak_;
	float rez_;

public:
	Calculator();
	Calculator(float a, float b, char znak, float rez);
	void setA(float a);
	void setB(float b);
	void setZnak(char znak);
	void setRez(float rez);
	float getA();
	float getB();
	char getZnak();
	float getRez();
	template <typename T>
	void Show(T n);
	float stringToFloat(string n);
	char stringTiChar(string n);
	bool numberOfCheks(string n);
	bool signCheks(string n);
	void calcCLS();
	void calcC();
	int Start();
};