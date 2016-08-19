#pragma once
#include "stdafx.h"

using namespace std;

class CrossZero
{
	char _player1[30];
	char _player2[30];
	int _firstMove;
	int _plNum;
	char Field[5][5];

public:
	CrossZero();
	void GameSettings();
	void PrintField();
	void Move(int, string);	
	bool CheckPosition(int);	
	bool Check();	
	void GamePlay();	
};