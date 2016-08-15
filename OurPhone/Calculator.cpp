#include "stdafx.h"

using namespace std;

Calculator::Calculator()
{
	a_ = b_ = rez_ = 0;
}
Calculator::Calculator(float a, float b, char znak, float rez)
{
	a_ = a;
	b_ = b;
	znak_ = znak;
	rez_ = rez;
}
void Calculator::setA(float a) { a_ = a; }
void Calculator::setB(float b) { b_ = b; }
void Calculator::setZnak(char znak) { znak_ = znak; }
void Calculator::setRez(float rez) { rez_ = rez; }
float Calculator::getA() { return a_; }
float Calculator::getB() { return b_; }
char Calculator::getZnak() { return znak_; }
float Calculator::getRez() { return rez_; }
template <typename T>
void Calculator::Show(T n)
{
	system("cls");
	cout << "\t=================================================================\n";
	cout << "\t\t\t\t\t\t\t" << n << "\r\r\r\r\r\r";
	cout << endl;
	cout << "\t=================================================================\n";
	cout << "\t|\tC\t\t\t|\t%\t|\t/\t|\n";
	cout << "\t-----------------------------------------------------------------\n";
	cout << "\t|\t7\t|\t8\t|\t9\t|\t*\t|\n";
	cout << "\t-----------------------------------------------------------------\n";
	cout << "\t|\t4\t|\t5\t|\t6\t|\t-\t|\n";
	cout << "\t-----------------------------------------------------------------\n";
	cout << "\t|\t1\t|\t2\t|\t3\t|\t+\t|\n";
	cout << "\t-----------------------------------------------------------------\n";
	cout << "\t|\t0\t\t\t|\t,\t|\t=\t|\n";
	cout << "\t-----------------------------------------------------------------\n";
}
float Calculator::stringToFloat(string n)
{
	string temp;
	int count = 0;
	for (int i = 0; i<n.size(); i++)
	{
		if (n[i] == ',' || n[i] == '.')
		{
			if (count<1)
			{
				n[i] = '.';
				count++;
			}
			else
			{
				n[i] = ' ';
			}
		}
	}


	for (int i = 0; i<n.size(); i++)
	{
		if (n[i] >= '0'&&n[i] <= '9' || n[i] == ',' || n[i] == '.' || n[i] == '-')
		{
			temp.push_back(n[i]);
		}

	}
	return stof(temp);
}
char Calculator::stringTiChar(string n)
{
	char tmp;
	for (int i = 0; i<n.size(); i++)
	{
		if (n[i] == '+' || n[i] == '-' || n[i] == '*' || n[i] == '/' || n[i] == '%')
		{
			tmp = n[i];
		}
	}
	return tmp;
}
bool Calculator::numberOfCheks(string n)
{
	for (int i = 0; i<n.size(); i++)
	{
		if (n[i] >= '0'&&n[i] <= '9' || n[i] == ',' || n[i] == '.' || n[i] == '-')
		{
			return true;
		}

	}
	return false;
}
bool Calculator::signCheks(string n)
{
	for (int i = 0; i<n.size(); i++)
	{

		if (n[i] == '+' || n[i] == '-' || n[i] == '*' || n[i] == '/' || n[i] == '%' || n[i] == '=')
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}
void Calculator::calcCLS()
{
	str = '0';
	setA(0);
	setB(0);
	setRez(0);
	setZnak(0);
}
void Calculator::calcC()
{
	str = '0';
	setA(0);
	setB(0);
	setZnak(0);
}
int Calculator::Start()
{
	string str;
begin:
	this->Show(this->getA());
	cin.clear();
	getline(cin, str);

	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == 'c' || str[i] == 'C' || str[i] == '209' || str[i] == '241')
		{
			system("cls");
			this->Show("Start again");
			Sleep(1000);


			this->calcCLS();
			goto begin;
		}

	}
	if (!this->numberOfCheks(str))
	{
		this->Show("Enter the number");
		Sleep(1000);
		goto begin;
	}

	if (!str.empty())
	{
		this->setA(this->stringToFloat(str));
	}
	else
	{
		this->Show("Start again");
		Sleep(1000);
		goto begin;
	}
	this->Show(this->getA());
begin3:


	str = '0';
	this->setZnak(0);
	cin.clear();
	getline(cin, str);

	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == 'c' || str[i] == 'C' || str[i] == '209' || str[i] == '241')
		{
			system("cls");
			this->calcCLS();
			this->Show("Start again");
			Sleep(1000);

			goto begin;
		}

	}

	if (this->signCheks(str))
	{

		for (int i = 0; i<str.size(); i++)
		{

			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
			{
			begin4:
				this->setZnak(this->stringTiChar(str));
			}
		}
	}
	else
	{
		this->Show("Enter the sign");
		Sleep(1000);
		goto begin3;
	}

begin2:

	this->Show(this->getZnak());
	if (this->getZnak() == '%')
	{
		this->setA(this->getA() / 100);
		this->Show(this->getA());
		goto begin3;
	}

	str = '0';
	cin.clear();
	cin >> str;

	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == 'c' || str[i] == 'C' || str[i] == '209' || str[i] == '241')
		{
			this->calcCLS();
			this->Show("Start again");
			Sleep(1000);
			goto begin;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '=')
		{
			goto begin4;
		}
	}
	if (!this->numberOfCheks(str))
	{
		this->Show("Enter the number ");
		Sleep(1000);
		goto begin2;
	}


	this->setB(this->stringToFloat(str));

	this->Show(this->getB());

	switch (this->getZnak())
	{
	case '+':

		this->setRez(this->getA() + this->getB());
		this->calcC();
		break;


	case '-':

		this->setRez(this->getA() - this->getB());
		this->calcC();

		break;
	case '*':

		this->setRez(this->getA()*this->getB());

		this->calcC();

		break;
	case '/':

		if (this->getB() != 0)
		{

			this->setRez(this->getA() / this->getB());
			this->calcC();

			break;
		}
		else
		{
			cout << "division by zero" << endl;
			this->Show("Enter the number ");
			Sleep(1000);
			goto begin2;
		}

	case '=':

		this->setRez(this->getB());
		this->Show(this->getRez());
		system("pause");

		this->calcCLS();

		goto begin;
	case '%':

		this->setRez(this->getA() / 100);
		this->Show(this->getRez());
		system("pause");
		this->calcC();
		goto begin3;


	}

	str = '0';
	cin.clear();
	cin >> str;

	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == 'c')
		{
			this->calcCLS();
			goto begin;
		}
		if (this->signCheks(str))
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '=')
			{
				switch (str[i])
				{
				case '+':

					this->setA(this->getRez());
					this->setZnak('+');
					this->setB(0);
					this->setRez(0);
					goto begin2;


				case '-':

					this->setA(this->getRez());
					this->setZnak('-');
					this->setB(0);
					this->setRez(0);
					goto begin2;

				case '*':

					this->setA(this->getRez());
					this->setZnak('*');
					this->setB(0);
					this->setRez(0);
					goto begin2;
				case '/':

					this->setA(this->getRez());
					this->setZnak('/');
					this->setB(0);
					this->setRez(0);
					goto begin2;


				case '=':
					char ch;
					this->Show(this->getRez());
					cout << "\t\t\tfor beginind enter eny key. Esc- exit\n";
					ch = _getch();
					if (ch == 27)
					{
						goto end;
					}
					this->calcCLS();
					goto begin;
				case '%':


					this->setA(this->getRez() / 100);
					this->setB(0);
					this->setRez(0);
					goto begin2;


				}
			}
			else
			{
				this->calcCLS();
				goto begin;
			}

		}
	}


	this->calcCLS();
	goto begin;
end:
	return 0;
}