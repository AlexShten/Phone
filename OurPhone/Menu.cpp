#include "stdafx.h"

using namespace std;

struct tm *LocalTime;
time_t t;

enum Keys
{
	_up = 72,
	_down = 80,
	_left = 75,
	_right = 77,
	enter = 13
};

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
void Set_Color(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int GetHour()
{
	t = time(NULL);
	LocalTime = localtime(&t);
	return LocalTime->tm_hour;
}
int GetMinute()
{
	t = time(NULL);
	LocalTime = localtime(&t);
	return LocalTime->tm_min;
}
int GetSecond()
{
	t = time(NULL);
	LocalTime = localtime(&t);
	return LocalTime->tm_sec;
}

MENU::MENU()
{
	_operator = " ";
	_internet = NULL;
	_scroll = NULL;
	_battery = NULL;
	_batLev = NULL;
	_screen = NULL;
	_blackout = NULL;
	_off = NULL;
	NewList = nullptr;
	newNumber = "";
}

void MENU::ReadSettings()
{
	ifstream Fin;

	Fin.open("Settings.txt");

	if (Fin)
	{
		while (!Fin.eof())
		{
			string temp;
			getline(Fin, temp);
			SetOperator(temp);

			getline(Fin, temp);
			SetInternet(atoi(temp.c_str()));

			getline(Fin, temp);
			SetScroll(atoi(temp.c_str()));

			getline(Fin, temp);
			SetBattery(atoi(temp.c_str()));

			getline(Fin, temp);
			SetScreen(atoi(temp.c_str()));

			getline(Fin, temp);
			SetBlackout(atoi(temp.c_str()));

			getline(Fin, temp);
			SetOff(atoi(temp.c_str()));

			getline(Fin, temp);
			SetBatLev(atoi(temp.c_str()));

			getline(Fin, temp);
		}
		Fin.close();
	}
}
void MENU::WriteSettings()
{
	ofstream Fout;

	Fout.open("Settings.txt");

	if (Fout)
	{
		Fout << this->GetOperator() << endl;
		Fout << this->GetInternet() << endl;
		Fout << this->GetScroll() << endl;
		Fout << this->GetBattery() << endl;
		Fout << this->GetScreen() << endl;
		Fout << this->GetBlackout() << endl;
		Fout << this->GetOff() << endl;
		Fout << this->GetBatLev() << endl;
	}

	Fout.close();
}
int MENU::ReadCallsFromFile()
{
	NewList = new CallList[100];
	int quantity = 0;
	string temp;
	ifstream Fin;

	Fin.open("CallsList.txt");

	if (Fin)
	{
		while (!Fin.eof())
		{
			getline(Fin, temp);
			if (Fin.eof()) continue;
			NewList[quantity].Name = temp;

			getline(Fin, temp);
			NewList[quantity].Number = temp;

			getline(Fin, temp);
			quantity++;
		}
		Fin.close();
	}

	return quantity;

}

string MENU::GetOperator()
{
	return _operator;
}
void MENU::SetOperator(string tmp)
{
	_operator = tmp;
}
int MENU::GetInternet()
{
	return _internet;
}
void MENU::SetInternet(int tmp)
{
	_internet = tmp;
}
int MENU::GetScroll()
{
	return _scroll;
}
void MENU::SetScroll(int tmp)
{
	_scroll = tmp;
}
int MENU::GetBattery()
{
	return _battery;
}
void MENU::SetBattery(int tmp)
{
	_battery = tmp;
}
int MENU::GetBatLev()
{
	return _batLev;
}
void MENU::SetBatLev(int tmp)
{
	_batLev = tmp;
}
int MENU::GetScreen()
{
	return _screen;
}
void MENU::SetScreen(int tmp)
{
	_screen = tmp;
}
int MENU::GetBlackout()
{
	return _blackout;
}
void MENU::SetBlackout(int tmp)
{
	if (tmp < 1) tmp = 1;
	if (tmp > 100) tmp = 100;
	_blackout = tmp;
}
int MENU::GetOff()
{
	return _off;
}
void MENU::SetOff(int tmp)
{
	if (tmp < 1) tmp = 1;
	if (tmp > 100) tmp = 100;
	_off = tmp;
}

void MENU::ScreenMode(int width, int height)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { width, height };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}
void MENU::PatternForPrint(int selection, int param, string _text1, string _text2, int printParam)
{
	if (printParam != 0) cout << "\t";
	if (selection == param) Set_Color(background1, text1);
	else Set_Color(background2, text2);
	if (printParam == 1) cout << param << ". " << _text1 << "  " << _text2 << endl;
	if (printParam == 0) cout << _text1 << "  " << _text2;
	Set_Color(background2, text2);
}
void MENU::PrintStatusBar()
{
	cout << GetHour() << ":" << GetMinute() << ":" << GetSecond() << "  ";
	cout << "\t" << this->GetOperator();
	cout << "\t" << (this->GetInternet() == 1 ? " (int) " : " ");
	cout << "\t" << (this->GetBattery() == 1 ? " " + to_string(this->GetBatLev()) + "%" : " ");
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}
void MENU::PrintMainScreen(int selection)
{
	system("cls");

	this->PrintStatusBar();

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
	cout << "----------------------------------------------------------" << endl;

	cout << "\t";
	PatternForPrint(selection, 1, "  MENU", "", 0);
	cout << "\t";
	PatternForPrint(selection, 2, " OPTIONS", "", 0);
	cout << "\t";
	PatternForPrint(selection, 3, "  BACK", "", 0);

	cout << "" << endl;
}
void MENU::PrintMenu(int selection)
{
	system("cls");

	this->PrintStatusBar();

	cout << "MENU..." << endl;
	cout << "" << endl;

	PatternForPrint(selection, 1, " Telephone book", "", 1);
	PatternForPrint(selection, 2, " SMS", "", 1);
	PatternForPrint(selection, 3, " Calls", "", 1);
	PatternForPrint(selection, 4, " Organizer", "", 1);
	PatternForPrint(selection, 5, " Calculator", "", 1);
	PatternForPrint(selection, 6, " Games", "", 1);
	PatternForPrint(selection, 7, " Book store", "", 1);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	switch (errMes)
	{
	case 0:
		cout << "\n";
		break;

	case 1:
		cout << " !!! For calls and messages set operator (OPTIONS) " << endl;
		break;

	case 2:
		cout << " !!! To access enable internet (OPTIONS) " << endl;
	}
	cout << "----------------------------------------------------------" << endl;

	cout << "\t\t\t\t\t";
	PatternForPrint(selection, 8, "  BACK", "", 0);

	cout << "" << endl;

}
void MENU::PrintOptions(int selection)
{
	system("cls");
	
	this->PrintStatusBar();

	cout << "OPTIONS..." << endl;
	cout << "" << endl;

	PatternForPrint(selection, 1, " Set operator: ", ("\t\t\t " + this->GetOperator()), 1);
	PatternForPrint(selection, 2, " ON/OFF internet: ", this->GetInternet() == 1 ? "\t\t\t   ON " : "\t\t\t   OFF", 1);
	PatternForPrint(selection, 3, " ON/OFF circular scrolling: ", this->GetScroll() == 1 ? "\t   ON " : "\t   OFF", 1);
	PatternForPrint(selection, 4, " ON/OFF current battery charge level: ", this->GetBattery() == 1 ? "ON " : "OFF", 1);
	PatternForPrint(selection, 5, " ON/OFF backlight off: ", this->GetScreen() == 1 ? "\t\t   ON " : "\t\t   OFF", 1);
	PatternForPrint(selection, 6, " Set time before blackout, sec.: ", ("\t   " + to_string(this->GetBlackout())), 1);
	PatternForPrint(selection, 7, " Set time for blackout to off, sec.: ", (" " + to_string(this->GetOff())), 1);
	PatternForPrint(selection, 8, " Set default settings ", "\t\t      ", 1);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "----------------------------------------------------------" << endl;

	cout << "\t\t\t\t\t";
	PatternForPrint(selection, 9, "  BACK", "", 0);
	cout << "" << endl;
}
void MENU::PrintCalls(int selection)
{
	system("cls");

	this->PrintStatusBar();

	cout << "CALLS..." << endl;
	cout << "" << endl;

	for (int i = 1; i <= quant; i++)
	{
		PatternForPrint(selection, i, NewList[i - 1].Date, " " + NewList[i - 1].Name + " " + NewList[i - 1].Number, 1);
	}

	for (int i = quant; i < 18; i++)
	{
		cout << "" << endl;
	}

	cout << "----------------------------------------------------------" << endl;
	cout << "\t"<<"Yor number: "<<newNumber << endl;
	cout << "----------------------------------------------------------" << endl;

	PatternForPrint(selection, quant + 1, "0", "", 0);
	PatternForPrint(selection, quant + 2, "1", "", 0);
	PatternForPrint(selection, quant + 3, "2", "", 0);
	PatternForPrint(selection, quant + 4, "3", "", 0);
	PatternForPrint(selection, quant + 5, "4", "", 0);
	PatternForPrint(selection, quant + 6, "5", "", 0);
	PatternForPrint(selection, quant + 7, "6", "", 0);
	PatternForPrint(selection, quant + 8, "7", "", 0);
	PatternForPrint(selection, quant + 9, "8", "", 0);
	PatternForPrint(selection, quant + 10, "9", "", 0);
	PatternForPrint(selection, quant + 11, "+", "", 0);

	PatternForPrint(selection, quant + 12, " CALL ", "", 0);
	PatternForPrint(selection, quant + 13, "  BACK", "", 0);
	cout << "" << endl;
}

int MENU::MainMenu()
{
	int key;
	int selection = 1;
	int screen = 1;
	int counter = 0;
	int counterBat = 0;
	int timer = 0;
	int editFlag = 0;
	int setOperator = 1;

	errMes = 0;

	PhonList PB;
	Organizer Org;
	Calculator Calc;
	CrossZero Game;
	Store Shop;

	this->ReadSettings();

	background1 = Black; text1 = White; background2 = White; text2 = Black;

	this->ScreenMode(58, 30);
	this->PrintMainScreen(selection);

	while (true)
	{
		Sleep(10);
		counter++;
		if (this->GetScreen() == 1) timer++;

		if (_kbhit())
		{
			key = _getch();

			timer = 0;

			background1 = Black; text1 = White; background2 = White; text2 = Black;

			switch (screen)
			{
			case 1://Главный экран
				if (key == _right) selection++;
				if (key == _left) selection--;

				if ((selection == 4 && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = 3;
				if ((selection == 4 && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (key == enter)
				{
					switch (selection)
					{
					case 1://MENU
						screen = 2;
						selection = 1;
						this->PrintMenu(selection);
						break;

					case 2://OPTIONS
						screen = 3;
						selection = 1;
						this->PrintOptions(selection);
						break;

					case 3://BACK
						selection = 1;
						this->PrintMainScreen(selection);
					}
					break;
				}

				this->PrintMainScreen(selection);
				break;

			case 2://Основное меню
				if (key == _down) selection++;
				if (key == _up) selection--;

				//errMes = 0;

				if ((selection == 9 && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = 8;
				if ((selection == 9 && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (key == enter)
				{
					switch (selection)
					{
					case 1://Telephone book
						system("cls");
						this->ScreenMode(58, 45);

						PB.PB_Start(this->GetOperator());

						this->ScreenMode(58, 30);
						this->PrintMenu(selection);
						break;

					case 2://SMS

						system("cls");
						this->ScreenMode(58, 37);

						PB.SMS_Start(this->GetOperator());

						this->ScreenMode(58, 30);
						this->PrintMenu(selection);
						break;

					case 3://Calls						

						quant = this->ReadCallsFromFile();

						screen = 4;
						selection = 1;
						this->PrintCalls(selection);
						break;

					case 4://Organizer
						system("cls");
						this->ScreenMode(75, 30);

						Org.Start();

						this->ScreenMode(58, 30);
						this->PrintMenu(selection);

						break;

					case 5://Calculator
						system("cls");
						this->ScreenMode(75, 30);

						Calc.Start();

						this->ScreenMode(58, 30);
						this->PrintMenu(selection);
						break;

					case 6://Games
						system("cls");

						Game.GameSettings();
						Game.GamePlay();

						this->PrintMenu(selection);
						break;

					case 7://Book store
						if (this->GetInternet() == 1)
						{
							system("cls");

							Shop.ReadFile();
							Shop.Start();
						}
						else errMes = 2;


						this->PrintMenu(selection);
						break;

					case 8://BACK
						screen = 1;
						selection = 1;
						this->PrintMainScreen(selection);
						break;
					}
					break;
				}

				this->PrintMenu(selection);
				break;

			case 3://Экран настроек
				if (key == _down && editFlag == 0)
				{
					selection++;
					if (this->GetScreen() == 0 && selection == 6) selection += 2;//Пропуск настроек времени при неактивном пункте "Экран"
				}
				if (key == _up && editFlag == 0)
				{
					selection--;
					if (this->GetScreen() == 0 && selection == 7) selection -= 2;//Пропуск настроек времени при неактивном пункте "Экран"
				}

				if ((selection == 10 && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = 9;//Реализация круговой прокрутки
				if ((selection == 10 && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (editFlag == 1)//Установка времени перед гашением и отключением экрана, в случае активации пункта "Экран"
				{
					switch (selection)
					{
					case 1:
						if (key == _down)
						{
							setOperator++;
							if (setOperator == 5) setOperator = 1;
						}
						if (key == _up)
						{
							setOperator--;
							if (setOperator == 0) setOperator = 4;
						}

						if (setOperator == 1) SetOperator("no sim");
						if (setOperator == 2) SetOperator("K-star");
						if (setOperator == 3) SetOperator("  UMS");
						if (setOperator == 4) SetOperator(" Life");

						this->WriteSettings();
						break;

					case 6:
						if (key == _down) SetBlackout(GetBlackout() - 1);
						if (key == _up) SetBlackout(GetBlackout() + 1);
						this->WriteSettings();
						break;

					case 7:
						if (key == _down) SetOff(GetOff() - 1);
						if (key == _up) SetOff(GetOff() + 1);
						this->WriteSettings();
						break;
					}
				}

				if (key == enter)
				{
					switch (selection)
					{
					case 1://Set operator
						editFlag == 0 ? editFlag = 1 : editFlag = 0;
						break;

					case 2://ON/OFF internet
						this->GetInternet() == 0 ? this->SetInternet(1) : this->SetInternet(0);
						this->WriteSettings();
						break;

					case 3://ON/OFF circular scrolling
						this->GetScroll() == 0 ? this->SetScroll(1) : this->SetScroll(0);
						this->WriteSettings();
						break;

					case 4://ON/OFF current battery charge level
						this->GetBattery() == 0 ? this->SetBattery(1) : this->SetBattery(0);
						this->WriteSettings();
						break;

					case 5://ON/OFF backlight off
						this->GetScreen() == 0 ? this->SetScreen(1) : this->SetScreen(0);
						this->WriteSettings();
						break;

					case 6://Set time before blackout
						editFlag == 0 ? editFlag = 1 : editFlag = 0;
						break;

					case 7://Set time after blackout to off
						editFlag == 0 ? editFlag = 1 : editFlag = 0;
						break;

					case 8://Set default settings
						this->SetInternet(0);
						this->SetScroll(0);
						this->SetBattery(0);
						this->SetScreen(1);
						this->SetBlackout(5);
						this->SetOff(5);
						this->WriteSettings();
						break;

					case 9://BACK
						screen = 1;
						selection = 1;
						this->PrintMainScreen(selection);
						break;
					}
					break;
				}	

				this->PrintOptions(selection);
				break;		

			case 4://Экран вызовов
				if (key == _down) selection++;
				if (key == _up) selection--;

				if ((selection == (quant + 14) && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = (quant + 13);
				if ((selection == (quant + 14) && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (key == enter)
				{
					if (selection == quant + 1) newNumber += "0";
					if (selection == quant + 2) newNumber += "1";
					if (selection == quant + 3) newNumber += "2";
					if (selection == quant + 4) newNumber += "3";
					if (selection == quant + 5) newNumber += "4";
					if (selection == quant + 6) newNumber += "5";
					if (selection == quant + 7) newNumber += "6";
					if (selection == quant + 8) newNumber += "7";
					if (selection == quant + 9) newNumber += "8";
					if (selection == quant + 10) newNumber += "9";
					if (selection == quant + 11) newNumber += "+";
					if (selection == quant + 12)
					{
						if (this->GetOperator() != "no sim")
						{
							PB.CallNewNumber(newNumber);
							PB.WriteToFileOutcomingCall(newNumber, -1);
							newNumber = "";
							delete[] NewList;
							quant = this->ReadCallsFromFile();
						}
					}

					if (selection == quant + 13)
					{
						screen = 2;
						selection = 1;
						delete[] NewList;
						newNumber = "";
						this->PrintMenu(selection);
						break;
					}
				}

				this->PrintCalls(selection);
				break;
			}
		}

		if (timer >= (this->GetBlackout() * 100 + this->GetOff() * 100) && this->GetScreen() == 1) system("cls");//условие для отключения экрана при бездействвии
		else if (counter >= 100)
		{
			if (timer >= (this->GetBlackout() * 100) && timer < (this->GetBlackout() * 100 + this->GetOff() * 100) && this->GetScreen() == 1)//Условие для затемнения шрифта при бездействии в течение времени
			{
				background1 = Black; text1 = LightGray; background2 = DarkGray; text2 = Black;
				Set_Color(background2, text2);
			}

			if (timer < (this->GetBlackout() * 100))//Обновление экрана каждую секунду для функционирования часов
			{
				background1 = Black; text1 = White; background2 = White; text2 = Black;
				Set_Color(background2, text2);
			}

			counterBat++;
			//cout << counterBat;
			if (counterBat == 30)
			{
				this->SetBatLev(this->GetBatLev() - 1);

				if (this->GetBatLev() == 0) return 0;

				counterBat = 0;
				this->WriteSettings();
			}

			if (screen == 1) this->PrintMainScreen(selection);
			if (screen == 2) this->PrintMenu(selection);
			if (screen == 3) this->PrintOptions(selection);
			if (screen == 4) this->PrintCalls(selection);
			counter = 0;
		}				
	}
}
