#include "stdafx.h"

using namespace std;

enum ConsoleColor
{
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGreen = 10,
	Yellow = 14,
	White = 15
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

char* months[] = { "January","February", "March","April", "May","June", "July", "August","September","October", "November","December" };
char* weekday[] = { "Monday","Tuesday", "Wednesday","Thursday", "Friday","Saturday","Sunday" };

int Date::getMonth() { return month; }
int Date::getDay() { return day; }
int Date::getYear() { return year; }
void Date::init()
{
	struct tm *timetmp;
	time_t t;
	t = time(NULL);
	timetmp = gmtime(&t);

	year = timetmp->tm_year + 1900;
	month = timetmp->tm_mon + 1;
	day = timetmp->tm_mday;
}

void Date::init(int d, int m, int y)
{
	month = m;
	year = y;
	day = d;
}

void Date::print()
{
	time_t tt;
	tt = time(NULL);
	struct tm *timeinfo;
	timeinfo = gmtime(&tt);
	int x = timeinfo->tm_mday;
	SetColor(15, 0);
	cout << " " << weekday[timeinfo->tm_wday - 1] << "\t" << timeinfo->tm_mday << " " << months[timeinfo->tm_mon] << " " << year << endl;

	timeinfo->tm_mday = 1;
	mktime(timeinfo);
	SetColor(14, 0);
	printf("_______________________________\n");
	printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");
	printf("_______________________________\n");
	for (int j = 0; j<(timeinfo->tm_wday); j++)
		printf("    ");

	for (int i = 1; i<33; i++)
	{
		timeinfo->tm_mday = i;
		mktime(timeinfo);
		if (i == timeinfo->tm_mday)
		{
			if (i == x)
			{
				SetColor(10, 0);
				printf("%4d", timeinfo->tm_mday);
				SetColor(14, 0);
			}
			else
			{
				printf("%4d", timeinfo->tm_mday);
			}
		}
		if (timeinfo->tm_wday == 6) printf("\n");
	}
	printf("\n");
	SetColor(15, 0);
}

void Date::print(int m)
{
	time_t tt;
	tt = time(NULL);
	struct tm *timeinfo;
	timeinfo = gmtime(&tt);
	int x = timeinfo->tm_mday;

	timeinfo->tm_mon = m - 1;

	mktime(timeinfo);

	SetColor(15, 0);
	cout << " \t\t\t " << months[timeinfo->tm_mon] << " " << year << endl;
	timeinfo->tm_mday = 1;
	mktime(timeinfo);
	SetColor(14, 0);
	printf("_______________________________\n");
	printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");
	printf("_______________________________\n");
	for (int j = 0; j<(timeinfo->tm_wday); j++)
		printf("    ");

	for (int i = 1; i<33; i++)
	{
		timeinfo->tm_mday = i;
		mktime(timeinfo);
		if (i == timeinfo->tm_mday)
		{
			printf("%4d", timeinfo->tm_mday);
		}

		if (timeinfo->tm_wday == 6) printf("\n");
	}

	printf("\n");
	SetColor(15, 0);
}

void Date::ShowDate()
{
	cout << " Day: " << day << "\tMonth: " << month << "\tYear: " << year;
}

bool Date::operator==(Date obj)
{
	if (month == obj.getMonth() && day == obj.getDay() && year == obj.getYear()) return true;
	return false;
}


void ShowTask(Task *obj)
{
	obj->tmp.ShowDate();
	cout << "\t";
	cout << obj->task << endl;
}

void GetTask(Task *obj)
{
	int d, m, y;
	string str;
begin:
	cout << "Data: ";
	cin >> d;
	if (d>31)
	{
		goto begin;
	}
	cin.ignore();
	cin >> m;
	if (m>12)
	{
		goto begin;
	}
	cin.ignore();
	cin >> y;
	cin.ignore();


	obj->tmp.init(d, m, y);
	cout << "Task: ";
	getline(cin, obj->task);
}

Task Organizer::getArr() { return *arr; }

Organizer::Organizer()
{
	sizeOf = 50;
	arr = new Task[sizeOf];
	arr->tmp.init();
	count = 0;
}

void Organizer::addTask()
{
	Task tmp;
	GetTask(&tmp);
	if (count<sizeOf)
	{
		arr[count] = tmp;
		count++;
		cout << "successful operation\n";
	}
	else
	{
		cout << "The memory is full\n";
		exit(1);
	}
}

void Organizer::Show()
{
	for (int i = 0; i<count; i++)
	{
		ShowTask(&arr[i]);
	}
}

void Organizer::FindTask(Date obj)
{
	for (int i = 0; i<count; i++)
	{
		if (arr[i].tmp == obj)
		{
			ShowTask(&arr[i]);
		}
	}
}

void Organizer::FindTask(string obj)
{
	for (int i = 0; i<count; i++)
	{
		if (arr[i].task == obj)
		{
			ShowTask(&arr[i]);
		}
	}
}

void Organizer::Start()
{
	char ch;
	string str;
	do
	{
		system("cls");
		getArr().tmp.print();
		cout << "1-Add task\t    || 2-Find Task\n";
		cout << "-----------------------------------\n";
		cout << "3-Show task in data || 4-Show all\n";
		cout << "-----------------------------------\n";
		cout << "5-Show the desired month\n";
		cout << "Esc-exit\n";
		ch = _getch();
		switch (ch)
		{
		case '1':
			addTask();
			Sleep(2000);
			break;
		case '2':
			cout << "Enter task for find\n";
			cin >> str;
			FindTask(str);
			Sleep(2000);
			break;
		case '3':
			cout << "Enter Data\n";
			Date tmp;
			int d, m, y;
		begin1:
			cin >> d;
			if (d>31)
			{
				goto begin1;
			}
			cin.ignore();
			cin >> m;
			if (m>12)
			{
				goto begin1;
			}
			cin.ignore();
			cin >> y;
			cin.ignore();
			tmp.init(d, m, y);
			FindTask(tmp);
			Sleep(2000);
			break;
		case '4':
			Show();
			Sleep(2000);
			break;

		case '5':
			system("cls");
			int temp;
			cout << "enter nunber month: ";
			cin >> temp;
			getArr().tmp.print(temp);


			system("pause");
			break;
		}
	} while (ch != 27);
}