#pragma once
#include "stdafx.h"

using namespace std;


struct CallList
{
	string Name = " ";
	string Number = " ";
	string Date = " ";
};

class MENU
{
private:
	string _operator;
	int _internet;
	int _scroll;
	int _battery;
	int _batLev;
	int _screen;
	int _blackout;
	int _off;

public:
	CallList *NewList;
	string newNumber;
	int background1, background2, text1, text2;
	int errMes;
	int quant;

	MENU();
	void ReadSettings();

	void WriteSettings();

	int ReadCallsFromFile();

	string GetOperator();
	void SetOperator(string);
	int GetInternet();
	void SetInternet(int);
	int GetScroll();
	void SetScroll(int);
	int GetBattery();
	void SetBattery(int);
	int GetBatLev();
	void SetBatLev(int);
	int GetScreen();
	void SetScreen(int);
	int GetBlackout();
	void SetBlackout(int);
	int GetOff();
	void SetOff(int);

	void ScreenMode(int, int);

	void PatternForPrint(int, int, string, string, int);

	void PrintStatusBar();

	void PrintMainScreen(int);
	void PrintMenu(int);
	void PrintOptions(int);

	void PrintCalls(int selection);

	int MainMenu();
};


int GetHour();
int GetMinute();
int GetSecond();