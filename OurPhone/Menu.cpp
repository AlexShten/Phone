#include "stdafx.h"

using namespace std;

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

MENU::MENU()
{
	scroll = false;
}
bool MENU::GetScroll()
{
	return scroll;
}
void MENU::SetScroll(bool tmp)
{
	scroll = tmp;
}

void MENU::ScreenMode(int width, int height)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { width, height };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

void MENU::PatternForPrint(int flag, int param, string text, int printParam)
{
	cout << "\t";
	if (flag == param) SetColor(Black, White);
	else SetColor(White, Black);
	if (printParam == 1) cout << param << ". " << text << endl;
	if (printParam == 0) cout << text;
	SetColor(White, Black);
}
void MENU::PrintMainPage(int flag)
{
	system("cls");
	cout << "" << endl;
	cout << "" << endl;
	cout << " ____                                       __           " << endl;
	cout << "/\\  _`\\                __                  /\\ \\__        " << endl;
	cout << "\\ \\ \\L\\ \\ _ __   ___  /\\_\\      __     ___ \\ \\ ,_\\  __   " << endl;
	cout << " \\ \\ ,__//\\`'__\\/ __`\\\\/\\ \\   /'__`\\  /'___\\\\ \\ \\/ /\\_\\  " << endl;
	cout << "  \\ \\ \\/ \\ \\ \\//\\ \\L\\ \\\\ \\ \\ /\\  __/ /\\ \\__/ \\ \\ \\_\\/_/_ " << endl;
	cout << "   \\ \\_\\  \\ \\_\\\\ \\____/_\\ \\ \\\\ \\____\\\\ \\____\\ \\ \\__\\ /\\_\\" << endl;
	cout << "    \\/_/   \\/_/ \\/___//\\ \\_\\ \\\\/____/ \\/____/  \\/__/ \\/_/" << endl;
	cout << "                      \\ \\____/                           " << endl;
	cout << "                       \\/___/                            " << endl;
	cout << "                 __                                  " << endl;
	cout << "                /\\ \\                                " << endl;
	cout << "          _____ \\ \\ \\___      ___     ___       __   " << endl;
	cout << "         /\\ '__`\\\\ \\  _ `\\   / __`\\ /' _ `\\   /'__`\\ " << endl;
	cout << "         \\ \\ \\L\\ \\\\ \\ \\ \\ \\ /\\ \\L\\ \\/\\ \\/\\ \\ /\\  __/ " << endl;
	cout << "          \\ \\ ,__/ \\ \\_\\ \\_\\\\ \\____/\\ \\_\\ \\_\\\\ \\____\\" << endl;
	cout << "           \\ \\ \\/   \\/_/\\/_/ \\/___/  \\/_/\\/_/ \\/____/" << endl;
	cout << "            \\ \\_\\                                    " << endl;
	cout << "             \\/_/                                    " << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "----------------------------------------------------------" << endl;

	PatternForPrint(flag, 1, " MENU ", 0);
	cout << "\t";
	PatternForPrint(flag, 2, " OPTIONS ", 0);
	PatternForPrint(flag, 3, " BACK ", 0);

	cout << "" << endl;
}
void MENU::PrintMenu(int flag)
{
	system("cls");
	cout << "" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "MENU..." << endl;
	cout << "" << endl;

	PatternForPrint(flag, 1, " Telephone book ", 1);
	PatternForPrint(flag, 2, " SMS ", 1);
	PatternForPrint(flag, 3, " Calls ", 1);
	PatternForPrint(flag, 4, " Organizer (+)", 1);
	PatternForPrint(flag, 5, " Calculator (+)", 1);
	PatternForPrint(flag, 6, " Games ", 1);
	PatternForPrint(flag, 7, " Book store (+-)", 1);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "----------------------------------------------------------" << endl;

	cout << "\t\t\t\t";
	PatternForPrint(flag, 8, " BACK ", 0);

	cout << "" << endl;

}
void MENU::PrintOptions(int flag)
{
	system("cls");
	cout << "" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "OPTIONS..." << endl;
	cout << "" << endl;

	PatternForPrint(flag, 1, " Set operator ", 1);
	PatternForPrint(flag, 2, " ON/OFF internet ", 1);
	PatternForPrint(flag, 3, " ON/OFF circular scrolling ", 1);
	PatternForPrint(flag, 4, " ON/OFF current battery charge ", 1);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "----------------------------------------------------------" << endl;

	cout << "\t\t\t\t";
	PatternForPrint(flag, 5, " BACK ", 0);
	cout << "" << endl;
}

void MENU::MainMenu()
{
	int key;
	int flag = 1;
	int branch = 1;

	Organizer Org;
	Calculator Calc;
	Store Shop;

	this->ScreenMode(58, 30);

	this->PrintMainPage(flag);

	while (true)
	{
		Sleep(1);

		if (_kbhit())
		{
			key = _getch();

			switch (branch)
			{
			case 1://√лавный экран
				if (key == 77) flag++;
				if (key == 75) flag--;

				if ((flag == 4 && this->GetScroll() == false) || (flag == 0 && this->GetScroll() == true)) flag = 3;
				if ((flag == 4 && this->GetScroll() == true) || (flag == 0 && this->GetScroll() == false)) flag = 1;

				if (key == 13)
				{
					switch (flag)
					{
					case 1:
						branch = 2;
						flag = 1;
						this->PrintMenu(flag);
						break;

					case 2:
						branch = 3;
						flag = 1;
						this->PrintOptions(flag);
						break;

					case 3:
						flag = 1;
						this->PrintMainPage(flag);
					}
					break;
				}

				this->PrintMainPage(flag);
				break;

			case 2://ќсновное меню
				if (key == 80) flag++;
				if (key == 72) flag--;

				if ((flag == 9 && this->GetScroll() == false) || (flag == 0 && this->GetScroll() == true)) flag = 8;
				if ((flag == 9 && this->GetScroll() == true) || (flag == 0 && this->GetScroll() == false)) flag = 1;

				if (key == 13)
				{
					switch (flag)
					{
					case 1:

						break;

					case 2:

						break;

					case 3:

						break;

					case 4:
						system("cls");
						this->ScreenMode(75, 30);

						Org.Start();

						this->ScreenMode(58, 30);
						this->PrintMenu(flag);

						break;

					case 5:
						system("cls");
						this->ScreenMode(75, 30);

						Calc.Start();

						this->ScreenMode(58, 30);
						this->PrintMenu(flag);
						break;

					case 6:

						break;

					case 7:
						system("cls");

						Shop.ReadFile();
						Shop.Start();

						this->PrintMenu(flag);
						break;

					case 8:
						branch = 1;
						flag = 1;
						this->PrintMainPage(flag);
						break;
					}
					break;
				}

				this->PrintMenu(flag);
				break;

			case 3://Ёкран настроек
				if (key == 80) flag++;
				if (key == 72) flag--;

				if ((flag == 6 && this->GetScroll() == false) || (flag == 0 && this->GetScroll() == true)) flag = 5;
				if ((flag == 6 && this->GetScroll() == true) || (flag == 0 && this->GetScroll() == false)) flag = 1;

				if (key == 13)
				{
					switch (flag)
					{
					case 1:

						break;

					case 2:

						break;

					case 3:

						break;

					case 4:

						break;

					case 5:
						branch = 1;
						flag = 1;
						this->PrintMainPage(flag);
						break;
					}
					break;
				}

				this->PrintOptions(flag);
				break;
			}
		}
	}
}
