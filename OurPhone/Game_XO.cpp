#include "stdafx.h"

using namespace std;

CrossZero::CrossZero()
{
	char _player1[30] = {};
	char _player2[30] = { "Computer" };
	int _firstMove = NULL;
	int _plNum = NULL;
	char Field[5][5] = { { 49,'|',50,'|',51 } ,{ 45,43,45,43,45 } ,{ 52,'|',53,'|',54 } ,{ '-','+','-','+','-' } ,{ 55,'|',56,'|',57 } };
}
void CrossZero::GameSettings()
{
	cout << "\t<<Settings>>\n";
	do
	{
		cout << "Players number:\n1 - one player\n2 - two players\n";
		cin >> _plNum;
		if (_plNum == 1)
		{
			cout << "not enough time, have trouble at work (((";
			Sleep(3000);
		}
	} while (_plNum > 2 || _plNum < 1);
	system("cls");
	if (_plNum == 1)
	{
		cout << "Enter your name\n";
		cin >> _player1;
		cout << "Player 2 - Computer\n";
	}
	else
	{
		cout << "Enter Player 1 name\n";
		cin >> _player1;
		cout << "Enter Player 2 name\n";
		cin >> _player2;
	}
	system("cls");
	int _firstMove;
	do
	{
		cout << "First move:\n1 - Player 1\n2 - Player 2\n";
		cin >> _firstMove;
	} while (_firstMove > 2 || _firstMove < 1);
	if (_firstMove == 2)
	{
		swap(_player1, _player2);
	}
	system("cls");
}
void CrossZero::PrintField()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\t";
		for (int j = 0; j < 5; j++)
		{
			cout << Field[i][j];
		}
		cout << endl;
	}
}
void CrossZero::Move(int position, string player)
{
	char sym;
	if (player == _player1)
		sym = 'X';
	else
		sym = 'O';
	switch (position)
	{
	case 1:
		Field[0][0] = sym;
		break;
	case 2:
		Field[0][2] = sym;
		break;
	case 3:
		Field[0][4] = sym;
		break;
	case 4:
		Field[2][0] = sym;
		break;
	case 5:
		Field[2][2] = sym;
		break;
	case 6:
		Field[2][4] = sym;
		break;
	case 7:
		Field[4][0] = sym;
		break;
	case 8:
		Field[4][2] = sym;
		break;
	case 9:
		Field[4][4] = sym;
		break;
	}
}
bool CrossZero::CheckPosition(int position)
{
	switch (position)
	{
	case 1:
		if (Field[0][0] == 'O' || Field[0][0] == 'X')
			return 1;
		else return 0;
		break;
	case 2:
		if (Field[0][2] == 'O' || Field[0][2] == 'X')
			return 1;
		else return 0;
		break;
	case 3:
		if (Field[0][4] == 'O' || Field[0][4] == 'X')
			return 1;
		else return 0;			
		break;
	case 4:
		if (Field[2][0] == 'O' || Field[2][0] == 'X')
			return 1;
		else return 0;
		break;
	case 5:
		if (Field[2][2] == 'O' || Field[2][2] == 'X')
			return 1;
		else return 0;
		break;
	case 6:
		if (Field[2][4] == 'O' || Field[2][4] == 'X')
			return 1;
		else return 0;
		break;
	case 7:
		if (Field[4][0] == 'O' || Field[4][0] == 'X')
			return 1;
		else return 0;
		break;
	case 8:
		if (Field[4][2] == 'O' || Field[4][2] == 'X')
			return 1;
		else return 0;
		break;
	case 9:
		if (Field[4][4] == 'O' || Field[4][4] == 'X')
			return 1;
		else return 0;
		break;
	}
}
bool CrossZero::Check()
{
	bool _line = 0;
	if (Field[0][0] == Field[0][2]&&Field[0][2] == Field[0][4] || Field[2][0] == Field[2][2]&&Field[2][2] == Field[2][4] || Field[4][0] == Field[4][2]&&Field[4][2] == Field[4][4] || Field[0][0] == Field[0][2]&&Field[0][2] == Field[0][4] || Field[0][2] == Field[2][2]&&Field[2][2] == Field[4][2] || Field[0][4] == Field[2][4]&&Field[2][4] == Field[4][4] || Field[0][0] == Field[2][2]&&Field[2][2] == Field[4][4] || Field[0][4] == Field[2][2]&&Field[2][2] == Field[4][0])
		_line = 1;
	return _line;
}
void CrossZero::GamePlay()
{
	int k=0;
	PrintField();
	do
	{
		cout << _player1 << " move\nEnter the number\n";
		int position;
		do
		{
			cin >> position;
			if (CheckPosition(position))
				cout << "Wrong number\n";
		} while (CheckPosition(position));
		Move(position, _player1);
		PrintField();
		k++;
		if (Check())
		{
			cout << _player1 << " win!\n";
			break;
		}
		else if (k < 9)
		{
			cout << _player2 << " move\nEnter the number\n";
			do
			{
				cin >> position;
				if (CheckPosition(position))
					cout << "Wrong number\n";
			} while (CheckPosition(position));
			Move(position, _player2);
			if (Check())
			{
				cout << _player2 << " win!\n";
				break;
			}
		}
		else
		{
			cout << "Draw...\n";
			Sleep(2000);
		}
		system("cls");
		PrintField();
		k++;
	} while (Check()||k<9);
	system("cls");
	PrintField();
}