#include "stdafx.h"

using namespace std;

struct tm *LocalTime;
time_t t;

enum Keys
{
	up = 75,
	down = 80,
	left = 75,
	right = 77,
	enter = 13,
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
	string _operator=" ";
	int _internet=NULL;
	int _scroll=NULL;
	int _battery=NULL;
	int _screen=NULL;
	int _blackout=NULL;
	int _off=NULL;
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
	}

	Fout.close();
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
	_blackout = tmp;
}
int MENU::GetOff()
{
	return _off;
}
void MENU::SetOff(int tmp)
{
	if (tmp < 1) tmp = 1;
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
	//cout << "\t";
	//if (selection == param) SetColor(Black, White);
	//else SetColor(White, Black);
	//if (printParam == 1) cout << param << ". " << text << endl;
	//if (printParam == 0) cout << text;
	//SetColor(White, Black);
	cout << "\t";
	if (selection == param) Set_Color(background1, text1);
	else Set_Color(background2, text2);
	if (printParam == 1) cout << param << ". " << _text1 <<"  "<< _text2 << endl;
	if (printParam == 0) cout << _text1 << "  " << _text2;
	Set_Color(background2, text2);
}
void MENU::PrintMainScreen(int selection)
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

	PatternForPrint(selection, 1, "  MENU", "", 0);
	PatternForPrint(selection, 2, " OPTIONS", "", 0);
	PatternForPrint(selection, 3, "  BACK", "", 0);

	cout << "" << endl;
}
void MENU::PrintMenu(int selection)
{
	system("cls");
	cout << GetHour() << ":" << GetMinute() << ":" << GetSecond()<< endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "MENU..." << endl;
	cout << "" << endl;

	PatternForPrint(selection, 1, " Telephone book ", "", 1);
	PatternForPrint(selection, 2, " SMS ", "", 1);
	PatternForPrint(selection, 3, " Calls ", "", 1);
	PatternForPrint(selection, 4, " Organizer (+)", "", 1);
	PatternForPrint(selection, 5, " Calculator (+)", "", 1);
	PatternForPrint(selection, 6, " Games ", "", 1);
	PatternForPrint(selection, 7, " Book store (+-)", "", 1);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "----------------------------------------------------------" << endl;

	cout << "\t\t\t\t";
	PatternForPrint(selection, 8, "  BACK", "", 0);

	cout << "" << endl;

}
void MENU::PrintOptions(int selection)
{
	system("cls");
	cout << GetHour() << ":" << GetMinute() << ":" << GetSecond()<< endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "OPTIONS..." << endl;
	cout << "" << endl;

	PatternForPrint(selection, 1, " Set operator: ", this->GetOperator(),1);
	PatternForPrint(selection, 2, " ON/OFF internet: ",this->GetInternet()==1? "ON":"OFF", 1);
	PatternForPrint(selection, 3, " ON/OFF circular scrolling: ", this->GetScroll() == 1 ? "ON" : "OFF", 1);
	PatternForPrint(selection, 4, " ON/OFF current battery charge level: ", this->GetBattery() == 1 ? "ON" : "OFF", 1);
	PatternForPrint(selection, 5, " ON/OFF backlight off: ", this->GetScreen() == 1 ? "ON" : "OFF", 1);
	PatternForPrint(selection, 6, " Set time before blackout, sec.: ", to_string(this->GetBlackout()), 1);
	PatternForPrint(selection, 7, " Set time after blackout to off, sec.: ", to_string(this->GetOff()), 1);
	PatternForPrint(selection, 8, " Set default settings ", "", 1);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "----------------------------------------------------------" << endl;

	cout << "\t\t\t\t";
	PatternForPrint(selection, 9, "  BACK", "",0);
	cout << "" << endl;
}
void MENU::MainMenu()
{
	int key;
	int selection = 1;
	int screen = 1;
	int counter = 0;
	int timer = 0;	
	int editFlag = 0;

	Organizer Org;
	Calculator Calc;
	Store Shop;

	this->ReadSettings();

	background1 = Black; text1 = White; background2 = White; text2 = Black;

	this->ScreenMode(58, 30);
	this->PrintMainScreen(selection);

	while (true)
	{
		Sleep(10);
		counter++;
		if(this->GetScreen() == 1) timer++;

		if (_kbhit())
		{
			key = _getch();		

			timer = 0;

			background1 = Black; text1 = White; background2 = White; text2 = Black;

			switch (screen)
			{
			case 1://Главный экран
				if (key == right) selection++;
				if (key == left) selection--;

				if ((selection == 4 && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = 3;
				if ((selection == 4 && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (key == enter)
				{
					switch (selection)
					{
					case 1:
						screen = 2;
						selection = 1;
						this->PrintMenu(selection);
						break;

					case 2:
						screen = 3;
						selection = 1;
						this->PrintOptions(selection);
						break;

					case 3:
						selection = 1;
						this->PrintMainScreen(selection);
					}
					break;
				}

				this->PrintMainScreen(selection);
				break;

			case 2://Основное меню
				if (key == down) selection++;
				if (key == up) selection--;

				if ((selection == 9 && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = 8;
				if ((selection == 9 && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (key == enter)
				{
					switch (selection)
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
						this->PrintMenu(selection);

						break;

					case 5:
						system("cls");
						this->ScreenMode(75, 30);

						Calc.Start();

						this->ScreenMode(58, 30);
						this->PrintMenu(selection);
						break;

					case 6:

						break;

					case 7:
						system("cls");

						Shop.ReadFile();
						Shop.Start();

						this->PrintMenu(selection);
						break;

					case 8:
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
				if (key == down && editFlag == 0) selection++;
				if (key == up && editFlag == 0) selection--;

				if ((selection == 10 && this->GetScroll() == 0) || (selection == 0 && this->GetScroll() == 1)) selection = 9;
				if ((selection == 10 && this->GetScroll() == 1) || (selection == 0 && this->GetScroll() == 0)) selection = 1;

				if (key == enter)
				{
					switch (selection)
					{
					case 1:

						break;

					case 2:
						this->GetInternet() == 0 ? this->SetInternet(1) : this->SetInternet(0);
						this->WriteSettings();
						break;

					case 3:
						this->GetScroll() == 0 ? this->SetScroll(1) : this->SetScroll(0);
						this->WriteSettings();
						break;

					case 4:
						this->GetBattery() == 0 ? this->SetBattery(1) : this->SetBattery(0);
						this->WriteSettings();
						break;

					case 5:
						this->GetScreen() == 0 ? this->SetScreen(1) : this->SetScreen(0);
						this->WriteSettings();
						break;

					case 6:
						editFlag == 0 ? editFlag = 1 : editFlag = 0;
						break;

					case 7:
						editFlag == 0 ? editFlag = 1 : editFlag = 0;
						break;
						
					case 8:
						this->SetInternet(0);
						this->SetScroll(0);
						this->SetBattery(0);
						this->SetScreen(1);
						this->SetBlackout(5);
						this->SetOff(5);
						this->WriteSettings();
						break;

					case 9:
						screen = 1;
						selection = 1;
						this->PrintMainScreen(selection);
						break;
					}
					
					if (editFlag == 1)
					{
						switch (selection)
						{
						case 1:
							
							break;
							
						case 6:
							if (key == down) SetOff(GetOff()-1);
							if (key == up) SetOff(GetOff()+1);
							break
							
						case 7:
							if (key == down) SetOff(GetOff()-1);
							if (key == up) SetOff(GetOff()+1);
							break;
					}
					break;
				}
				
				this->PrintOptions(selection);
				break;
			}
		}


		if (timer >= (this->GetBlackout() * 100 + this->GetOff() * 100) && this->GetScreen()==1) system("cls");//условие для отключения экрана при бездействвии
		else if (counter >= 100)
		{
			if (timer >= (this->GetBlackout() * 100) && timer < (this->GetBlackout() * 100 + this->GetOff()*100) && this->GetScreen() == 1)//Условие для затемнения шрифта при бездействии в течение времени
			{
				background1 = Black; text1 = LightGray; background2 = DarkGray; text2 = Black;
				Set_Color(background2, text2);
			}

			if (timer < (this->GetBlackout()*100))//Обновление экрана каждую секунду для функционирования часов
			{
				background1 = Black; text1 = White; background2 = White; text2 = Black;
				Set_Color(background2, text2);				
			}

			if (screen == 1) this->PrintMainScreen(selection);
			if (screen == 2) this->PrintMenu(selection);
			if (screen == 3) this->PrintOptions(selection);
			counter = 0;
		}


	}
}
