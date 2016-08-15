#pragma once
#include "stdafx.h"

using namespace std;

class MENU
{
private:
	bool scroll;

public:
	MENU();
	bool GetScroll();
	void SetScroll(bool);

	void ScreenMode(int, int);

	void PatternForPrint(int, int, string, int);

	void PrintMainPage(int);
	void PrintMenu(int);
	void PrintOptions(int);

	void MainMenu();
};