#pragma once
#include "stdafx.h"

using namespace std;

class MENU
{
private:
	string _operator;
	int _internet;
	int _scroll;
	int _battery;
	int _screen;
	int _blackout;
	int _off;

public:
	int background1, background2, text1, text2;

	MENU();
	void ReadSettings();

	void WriteSettings();

	string GetOperator();
	void SetOperator(string);
	int GetInternet();
	void SetInternet(int);
	int GetScroll();
	void SetScroll(int);
	int GetBattery();
	void SetBattery(int);
	int GetScreen();
	void SetScreen(int);
	int GetBlackout();
	void SetBlackout(int);
	int GetOff();
	void SetOff(int);

	void ScreenMode(int, int);

	void PatternForPrint(int, int, string, string, int);

	void PrintMainScreen(int);
	void PrintMenu(int);
	void PrintOptions(int);

	void MainMenu();
};

int GetHour();
int GetMinute();
int GetSecond();