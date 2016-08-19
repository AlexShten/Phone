#include "stdafx.h"

using namespace std;

PhonList::PhonList()
{
	Head = nullptr;
	Tail = nullptr;
	count = 0;
	onceEnter = 0;
}

PhonList::~PhonList()
{
	delete[] Head;
	delete[] Tail;
}

void PhonList::ShowPB()
{
}

void PhonList::FacePaint()
{
	cout << "\n\t\t\t       ¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t  ¶¶¶¶¶¶¶  ¶¶¶¶¶  ¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t ¶¶¶¶¶¶¶    ¶¶¶    ¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t ¶¶¶¶¶¶¶¶  ¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t   ¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶¶¶ ¶¶¶¶";
	cout << "\n\t\t\t    ¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶ ¶¶¶¶";
	cout << "\n\t\t\t     ¶¶¶¶¶        ¶¶¶¶¶";
	cout << "\n\t\t\t      ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t        ¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t      ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t    ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
	cout << "\n\t\t\t¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
}

void PhonList::ShowColorList(int pos, bool isCall)
{
	int i = 1;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (count != 0)
	{
		Node *tmp = Head;
		while (tmp != nullptr)
		{			
			if (i == pos)
				SetConsoleTextAttribute(hStdOut, (WORD)((14) | 14));	
			else
				SetConsoleTextAttribute(hStdOut, (WORD)((7) | 7));
			cout << "\t\t\t" << tmp->_name;
			for (int i = 0; i < (20 - tmp->_name.length()); i++)
				cout << " ";		
			cout << "|";
			if (isCall && i == pos)
			{				
				SetConsoleTextAttribute(hStdOut, (WORD)((10) | 10));
				cout << " CALL ";
				SetConsoleTextAttribute(hStdOut, (WORD)((14) | 14));
			}
			else
				cout << " CALL ";
			cout << "|\n" << endl;
			i++;
			tmp = tmp->next;
		}
	}
}

void PhonList::SetYellowTextColor(string str)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((14) | 14));
	cout << str;
	SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
}

void PhonList::ColorPrint(int pos){

	cout << "\n\n\t\t\tUse \"Tab\", \"Space\", \"Enter\"";
	cout << "\n\t\t\tand Down arrow for nawigation ";
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (pos == -1)
	{
		cout << "\n\t\t\t____________________________\n\n";
		SetYellowTextColor("\t\t\t\t   Find");
		cout << "\n\t\t\t____________________________\n";
		cout << "\t\t\t____________________________\n\n";
		cout << "\t\t\t      Add new contact";
		cout << "\n\t\t\t____________________________\n\n";
	}
	else if (pos == 0)
	{
		cout << "\n\t\t\t____________________________\n\n";
		cout << "\t\t\t\t   Find";
		cout << "\n\t\t\t____________________________\n";
		cout << "\t\t\t____________________________\n\n";
		SetYellowTextColor("\t\t\t      Add new contact");
		cout << "\n\t\t\t____________________________\n\n";
	}
	else if (pos > 0 || pos < -1)
	{
		SetConsoleTextAttribute(hStdOut, (WORD)((8) | 8));
		cout << "\n\t\t\t____________________________\n\n";
		cout << "\t\t\t\t   Find";
		cout << "\n\t\t\t____________________________\n";
		cout << "\t\t\t____________________________\n\n";
		cout << "\t\t\t      Add new contact";
		cout << "\n\t\t\t____________________________\n\n";
	}
}

bool PhonList::Call(int pos)
{
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	system("cls");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
	cout << "\n\n\n\t\t\t " << tmpNode->_name;
	cout << "\n\t\t\t " << tmpNode->_phoneNumber << endl;
	SetConsoleTextAttribute(hStdOut, (WORD)((8) | 8));
	FacePaint();
	SetConsoleTextAttribute(hStdOut, (WORD)((12) | 12));
	cout << "\n\t\t\t____________________________\n\n"; 
	cout << "\t\t\t           Finish";
	cout << "\n\t\t\t____________________________\n";
	SetConsoleTextAttribute(hStdOut, (WORD)((8) | 8));
	int act = _getch();	
	return true;
}

int PhonList::Message(int pos, string &sms)
{
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((2) | 2));
	cout << "\n\n\n\t\t\t " << tmpNode->_name;
	SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
	cout << "\n\n\t\t\t Message:\n";
	cout << "\n\t\t\t ";
	getline(cin, sms);
	cout << "\n\n\t\t\t ________    _________\n\n";
	cout << "\t\t\t|";
	SetYellowTextColor("  Done  ");
	cout << "|  | Cancel |";
	cout << "\n\t\t\t ________    _________\n";
	int act = _getch();
	return act;
}

void PhonList::PB_Start()
{
	int pos = -2;
	int action=0;
	if (onceEnter == 0)
	{
		ReadFromFile("phonList.txt");
		onceEnter = 1;
	}

	SortByName();
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);	
	bool isCall = false;
	do 
	{
		system("cls");
		ColorPrint(pos);
		ShowColorList(pos, isCall); 
		BackButton(pos);
		_getch();
		action = _getch();
		switch (action)
		{
		case 80: pos++;
			system("cls");
			ColorPrint(pos);
			if (pos >= count+2)
			{
				pos = -2;
			}
			isCall = false;
			ShowColorList(pos, isCall);	
			BackButton(pos);
			//isCall = false;
		break;
		case 72:pos--;
			system("cls");
			ColorPrint(pos);
			if (pos < -2)
			{
				pos = count+1;
			}
			isCall = false;
			ShowColorList(pos, isCall);
			BackButton(pos);
			break;
		case 32:
			if (pos >= 1 && pos <= count)
			{
				isCall = true;
				ShowColorList(pos, isCall);
			}
			break;
		case 13:
			if (pos == count + 1)
			{
				action = 27;
				break;
			}
			if (pos==-1)
			{
				bool isOk = true;
				system("cls");
				cout << "\n\n\t\t\t Enter name: ";
				string name;
				getline(cin, name); 

				cout << "\n\n\t\t\t ________  _________\n\n";
				cout << "\t\t\t|";
				SetYellowTextColor("  Find  ");
				cout << "| | Cancel |";
				cout << "\n\t\t\t ________  _________\n";
				int act = 0;
				act = _getch();
				while (act != 13)
				{		
					switch (act)
					{
					case 77: system("cls");
						cout << "\n\n\t\t\t Enter name: " << name;
						cout << "\n\n\t\t\t ________  _________\n\n";
						cout << "\t\t\t|  Find  | |";
						SetYellowTextColor(" Cancel ");
						cout << "|";
						cout << "\n\t\t\t ________  _________\n";
						isOk = false;
						act = _getch();
						break;
					case 75: system("cls");
						cout << "\n\n\t\t\t Enter name: " << name;
						cout << "\n\n\t\t\t ________  _________\n\n";
						cout << "\t\t\t|";
						SetYellowTextColor("  Find  ");
						cout << "| | Cancel |";
						cout << "\n\t\t\t ________  _________\n";
						isOk = true;
						act = _getch();
						break;	
					default:
						act = _getch();
						break;
					}
				} 
				if (act == 13 && isOk == true)
				{
					pos = FindByName(name);
					if (pos == -3)
					{
						system("cls");
						cout << "\n\n\t\t\tContact not found." << endl;
						cout << "\n\n\t\t\t   ____________\n\n";
						cout << "\t\t\t   |";
						SetYellowTextColor("   Back   ");
						cout << "|";
						cout << "\n\t\t\t   ____________\n";
						int act = 0;
						act = _getch();
						if (act == 13)
						{
							pos = -1;
							break;
						}
					}
					else
					{
						ColorPrint(pos);
						isCall = false;
						ShowColorList(pos, isCall);
					}
					break;
				}
				else if (act == 13 && isOk == false)
				{				
					pos = -1;
					break;
				}							
			}
			if (pos == 0)
			{
				int act = 0;
				bool isOk = true;
				string tmpName, tmpPhon;
				int ID;
				system("cls");
				cout << "\n\n\t\t\t Name: ";
				getline(cin, tmpName); 
				cout << "\n\n\t\t\t Phon Number: ";
				getline(cin, tmpPhon); 
				cout << "\n\n\t\t\t ________  _________\n\n";
				cout << "\t\t\t|";
				SetYellowTextColor("  Done  ");
				cout << "| | Cancel |";
				cout << "\n\t\t\t ________  _________\n";
				act = _getch();
				while (act != 13)
				{
					switch (act)
					{
					case 77: system("cls");
						cout << "\n\n\t\t\t Name: " << tmpName; 
						cout << "\n\n\t\t\t Phon Number: " << tmpPhon;
						cout << "\n\n\t\t\t ________  _________\n\n";
						cout << "\t\t\t|   Done | |";
						SetYellowTextColor(" Cancel ");
						cout << "|";
						cout << "\n\t\t\t ________  _________\n";
						isOk = false;
						act = _getch();
						break;
					case 75: system("cls");
						cout << "\n\n\t\t\t Name: " << tmpName;
						cout << "\n\n\t\t\t Phon Number: " << tmpPhon;
						cout << "\n\n\t\t\t ________  _________\n\n";
						cout << "\t\t\t|";
						SetYellowTextColor("   Done ");
						cout << "| | Cancel |";
						cout << "\n\t\t\t ________  _________\n";
						isOk = true;
						act = _getch();
						break;
					default:
						act = _getch();
						break;
					}
				}
				if (act == 13 && isOk == true)
				{
					ID = GetMaxID();
					++ID;
					string fileName = "file" + std::to_string(ID) + ".txt";
					AddInTail(tmpName, tmpPhon, ID, fileName);
					SortByName();
					WriteToFile("phonList.txt");
					pos = FindByName(tmpName);
				}
				else if (act == 13 && isOk == false)
				{
					pos = 0;
					break;
				}
			}
			else if (pos >= 1 && pos <= count)
			{
				if (isCall)
				{
					bool act = Call(pos);
					if (act)
					{
						isCall = false;
						WriteToFileOutcomingCall("CallsList.txt", pos);
						break;
					}
				}
				else
				{				
					int act = 8;
					string tmpName, tmpPhon;
					Node *tmp = Head;
					int j = 1;
					while (j < pos)
					{
						tmp = tmp->next;
						j++;
					}
					system("cls");
					cout << "\n\n\t\t\t Name: " << tmp->_name;
					cout << "\n\n\t\t\t Phon Number: " << tmp->_phoneNumber;
					cout << "\n\n\t\t\t _____  ______  _____  ______\n\n";
					cout << "\t\t\t| SMS || Edit || Del || Back |";
					cout << "\n\t\t\t _____  ______  _____  ______\n";
					int spPres = 0;
					int tabPres = 0;
					bool isSMS = false;
					bool isEdit = false;
					bool isDel = false;
					bool isBack = false;
					act = _getch();
					while (act != 13)
					{
						switch (act)
						{
						case 77: system("cls");
							spPres++;
							cout << "\n\n\t\t\t Name: " << tmp->_name;
							cout << "\n\n\t\t\t Phon Number: " << tmp->_phoneNumber;
							cout << "\n\n\t\t\t _____  ______  _____  ______\n\n";
							if (spPres == 1)
							{
								cout << "\t\t\t|";
								SetYellowTextColor(" SMS ");
								cout << "|| Edit || Del || Back |";
								isSMS = true;
							}
							if (spPres == 2)
							{
								cout << "\t\t\t| SMS ||";
								SetYellowTextColor(" Edit ");
								cout << "|| Del || Back |";
								isSMS = false;
								isEdit = true;
							}
							if (spPres == 3)
							{
								cout << "\t\t\t| SMS || Edit ||";
								SetYellowTextColor(" Del ");
								cout << "|| Back |";
								isEdit = false;
								isDel = true;
							}
							if (spPres >= 4)
							{
								cout << "\t\t\t| SMS || Edit || Del ||";
								SetYellowTextColor(" Back ");
								cout << "|";
								isDel = false;
								isBack = true;
							}
							cout << "\n\t\t\t _____  ______  _____  ______\n";
							act = _getch();
							break;
						case 75: system("cls");
							cout << "\n\n\t\t\t Name: " << tmp->_name;
							cout << "\n\n\t\t\t Phon Number: " << tmp->_phoneNumber;
							cout << "\n\n\t\t\t _____  ______  _____  ______\n\n";
							if (spPres <= 1)
								spPres = 2;
							if (spPres == 2)
							{
								cout << "\t\t\t|";
								SetYellowTextColor(" SMS ");
								cout << "|| Edit || Del || Back |";
								isEdit = false;
								isSMS = true;
							}
							if (spPres == 3)
							{
								cout << "\t\t\t| SMS ||";
								SetYellowTextColor(" Edit ");
								cout << "|| Del || Back |";
								isDel = false;
								isEdit = true;
							}
							if (spPres >= 4)
							{
								cout << "\t\t\t| SMS || Edit ||";
								SetYellowTextColor(" Del ");
								cout << "|| Back |";
								isBack = false;
								isDel = true;
								spPres = 4;
							}
							cout << "\n\t\t\t _____  ______  _____  ______\n";
							spPres--;
							act = _getch();
							break;
						default:
							act = _getch();
							break;
						}
						if (act == 13 && isSMS == true)
						{							
							string message;
							bool isOk = true;
							int act = Message(pos, message);
							int i = 1;
							Node *tmpNode = Head;
							while (i < pos)
							{
								tmpNode = tmpNode->next;
								i++;
							}
							while (act != 13)
							{
								switch (act)
								{
								case 77: system("cls");
									SetConsoleTextAttribute(hStdOut, (WORD)((2) | 2));
									cout << "\n\n\n\t\t\t " << tmpNode->_name;
									SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
									cout << "\n\n\t\t\t Message:\n";
									cout << "\n\t\t\t " << message;
									cout << "\n\n\t\t\t ________   _________\n\n";
									cout << "\t\t\t|   Done | |";
									SetYellowTextColor(" Cancel  ");
									cout << "|";
									cout << "\n\t\t\t ________   _________\n";
									isOk = false;
									act = _getch();
									break;
								case 75: system("cls");
									SetConsoleTextAttribute(hStdOut, (WORD)((2) | 2));
									cout << "\n\n\n\t\t\t " << tmpNode->_name;
									SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
									cout << "\n\n\t\t\t Message:\n";
									cout << "\n\t\t\t " << message;
									cout << "\n\n\t\t\t ________   _________\n\n";
									cout << "\t\t\t|";
									SetYellowTextColor("   Done ");
									cout << "| | Cancel  |";
									cout << "\n\t\t\t ________   _________\n";
									isOk = true;
									act = _getch();
									break;
								default:
									act = _getch();
									break;
								}
							}
							if (act == 13 && isOk == true)
							{
								//cout << "\n\n\n\n\t\t\tPlease, whait some time";
								string fileName = CreateFileName(pos);
								WriteToFileSMS(fileName, pos, message);
								WriteToFileOutcomingCall("SMS_file.txt", pos);
							}
							else if (act == 13 && isOk == false)
							{
								break;
							}
						}
						else if (act == 13 && isEdit == true)
						{
							system("cls");
							cout << "\n\n\t\t\t Name: " << tmp->_name;
							act = _getch();
							if (act == 8)
							{
								system("cls");
								cout << "\n\n\t\t\t Name: ";
								getline(cin, tmpName); 
							}
							else
								tmpName = tmp->_name;
							cout << "\n\n\t\t\t Phon Number: " << tmp->_phoneNumber;
							act = _getch();
							if (act == 8)
							{
								system("cls");
								cout << "\n\n\t\t\t Name: " << tmpName;
								cout << "\n\n\t\t\t Phon Number: ";
								getline(cin, tmpPhon); 
							}
							else
								tmpPhon = tmp->_phoneNumber;
							cout << "\n\n\t\t\t ________  _________\n\n";
							cout << "\t\t\t|";
							SetYellowTextColor("  Done  ");
							cout << "| | Cancel |";
							cout << "\n\t\t\t ________  _________\n";
							act = _getch();
							bool isOk = true;
							while (act != 13)
							{
								switch (act)
								{
								case 77: system("cls");
									cout << "\n\n\t\t\t Name: " << tmpName;
									cout << "\n\n\t\t\t Phon Number: " << tmpPhon;
									cout << "\n\n\t\t\t ________  _________\n\n";
									cout << "\t\t\t|   Done | |";
									SetYellowTextColor(" Cancel ");
									cout << "|";
									cout << "\n\t\t\t ________  _________\n";
									isOk = false;
									act = _getch();
									break;
								case 75: system("cls");
									cout << "\n\n\t\t\t Name: " << tmpName;
									cout << "\n\n\t\t\t Phon Number: " << tmpPhon;
									cout << "\n\n\t\t\t ________  _________\n\n";
									cout << "\t\t\t|";
									SetYellowTextColor("   Done ");
									cout << "| | Cancel |";
									cout << "\n\t\t\t ________  _________\n";
									isOk = true;
									act = _getch();
									break;
								default:
									act = _getch();
									break;
								}
							}
							if (act == 13 && isOk == true)
							{
								tmp->_name = tmpName;
								tmp->_phoneNumber = tmpPhon;
								SortByName();
								WriteToFile("phonList.txt");
								pos = FindByName(tmpName);
								break;
							}
							else if (act == 13 && isOk == false)
							{
								break;
							}
						}
						else if (act == 13 && isDel == true)
						{
							system("cls");
							cout << "\n\n\t\t\t Are you realy want dell " << tmp->_name << "'s contact?";
							cout << "\n\n\t\t\t _________  __________\n\n";
							cout << "\t\t\t|";
							SetYellowTextColor("   YES   ");
							cout << "||    NO    |";
							cout << "\n\t\t\t _________  __________\n";
							act = _getch();
							bool isOk = true;
							while (act != 13)
							{
								switch (act)
								{
								case 77: system("cls");
									cout << "\n\n\t\t\t Are you realy want dell " << tmp->_name << "'s contact?";
									cout << "\n\n\t\t\t _________  __________\n\n";
									cout << "\t\t\t|   YES   ||";
									SetYellowTextColor("    NO    ");
									cout << "|";
									cout << "\n\t\t\t _________  __________\n";
									isOk = false;
									act = _getch();
									break;
								case 75: system("cls");
									cout << "\n\n\t\t\t Are you realy want dell " << tmp->_name << "'s contact?";
									cout << "\n\n\t\t\t _________  __________\n\n";
									cout << "\t\t\t|";
									SetYellowTextColor("   YES   ");
									cout << "||    NO    |";
									cout << "\n\t\t\t _________  __________\n";
									isOk = true;
									act = _getch();
									break;
								default:
									act = _getch();
									break;
								}
							}
							if (act == 13 && isOk == true)
							{
								DelByPos(pos);
								SortByName();
								WriteToFile("phonList.txt");
								pos--;
								break;
							}
							if (act == 13 && isOk == false)
							{
								break;
							}
						}
						else if (act == 13 && isBack == true)
						{
							break;
						}
					}
				}
			}
			break;
			default:
				continue;
		}
	} while (action != 27);
}

void PhonList::AddInTail(string name, string phonNumber, int ID, string Mfile)
{	
	Node *newNode = new Node();
	newNode->_name = name;
	newNode->_phoneNumber = phonNumber;
	newNode->id = ID;
	newNode->messageFile = Mfile;
	newNode->prev = Tail;
	newNode->next = nullptr;
	if (Tail != nullptr)
		Tail->next = newNode;
	if (count == 0)
		Head = Tail = newNode;
	else
		Tail = newNode;
	count++;
}

int PhonList::GetMaxID()
{
	int i = 1;
	Node *tmpNode = Head;
	int max = tmpNode->id;
	while (tmpNode->next != nullptr)
	{
		tmpNode = tmpNode->next;
		if (tmpNode->id > max)
		{
			max = tmpNode->id;
		}
	}
	return max;
}

void PhonList::DelByPos(int pos)
{
	if (pos <= 0 || pos >= count + 1)
	{
		cout << "Error! Incorrect position.\n";
		return;
	}
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	Node *prevNode = tmpNode->prev;
	Node *nextNode = tmpNode->next;
	if (prevNode != nullptr && count != 1)
		prevNode->next = nextNode;
	if (nextNode != nullptr && count != 1)
		nextNode->prev = prevNode;
	if (pos == 1)
		Head = nextNode;
	if (pos == count)
		Tail = prevNode;
	tmpNode->next = nullptr;
	delete tmpNode;
	count--;
}

int PhonList::FindByName(string name)
{
	int i = 1;
	bool isFind = 0;
	Node *tmpNode = Head;
	while (tmpNode != nullptr)
	{
		if (tmpNode->_name == name)
		{
			//isFind = 1;
			return i;
		}
		tmpNode = tmpNode->next;
		i++;
	}
	if (isFind == 0)
	{
		return -3;
	}
}

void PhonList::WriteToFile(string fName)
{
	ofstream ofFile;
	ofFile.open(fName);
	Node *tmpNode = Head;
	if (ofFile)
	{
		while (tmpNode != nullptr)
		{
			ofFile << tmpNode->_name << "***";
			ofFile << tmpNode->_phoneNumber << "id:";
			ofFile << tmpNode->id << "file:";
			ofFile << tmpNode->messageFile <<endl;
			tmpNode = tmpNode->next;
		}
	}
	ofFile.close();
}

void PhonList::WriteToFileOutcomingCall(string fName, int pos)
{
	ofstream ofFile;	
	ofFile.open(fName, std::fstream::app);
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	if (ofFile)
	{
			ofFile << tmpNode->_name << "***";
			ofFile << tmpNode->_phoneNumber << "id:";
			ofFile << tmpNode->id << "file:";
			ofFile << tmpNode->messageFile << endl;
	}
	ofFile.close();
}

void PhonList::WriteToFileSMS(string fName, int pos, string str)
{
	ofstream ofFile;
	ofFile.open(fName, std::fstream::app);
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	if (ofFile)
	{
		ofFile << "me:";
		ofFile << str << "&&" << endl;
	}
	ofFile.close();
}

void PhonList::ReadFromSMSFile(int pos)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream ifFile;
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	string fName = tmpNode->messageFile;
	try
	{
		ifFile.open(fName);
		if (!ifFile)
		{
			throw (string)"Cannot open the file";
		}
		while (!ifFile.eof())
		{
			string message, me;
			string tmp;
			int index, index1, ID;
			while (getline(ifFile, tmp))
			{
				string character = "me:";
				index = tmp.find(character);
				string character1 = "&&";
				index1 = tmp.find(character1);
				if (index != -1)
				{
					message = tmp.substr(index + 3, index1-3);
					SetConsoleTextAttribute(hStdOut, (WORD)((10) | 10));
					cout << "\n\t\t\tMe:" << message;
					SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
					character = "to me:";
					index = tmp.find(character);
					if (index != -1)
					{
						message = tmp.substr(index + 6, index1-3);
						cout << "\n\t\t\t" << tmpNode->_name << ": " << message;
					}
				}
			}
		}
	}
	catch (string error)
	{
	}
}

string PhonList::CreateFileName(int pos)
{
	int i = 1;
	Node *tmpNode = Head;
	while (i < pos)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	string FileName = "file";
	int ID = tmpNode->id;
	FileName += std::to_string(ID);
	FileName += ".txt";
	return FileName;
}

void PhonList::ReadFromFile(string fName)
{
	ifstream ifFile;
	try
	{
		ifFile.open(fName);
		if (!ifFile)
		{
			throw (string)"Cannot open the file";
		}
		while (!ifFile.eof())
		{
			string tmpName;
			string tmpPhon;
			string tmp;
			string Mfile;
			int index, ID;
			while (getline(ifFile, tmp))
			{
				string character = "***";
				index = tmp.find(character);
				if (index != -1)
				{				
					int index2 = tmp.find("id:");
					tmpPhon = tmp.substr(index + 3, index2 - (index + 3));
					tmpName = tmp.substr(0, index);
					index2 = tmp.find("file:");										
					character = "id:";
					index = tmp.find(character);
					ID = atoi((tmp.substr(index + 3, index2 - (index + 3))).c_str());
					Mfile = tmp.substr(index2 + 5);
					AddInTail(tmpName, tmpPhon, ID, Mfile);
				}
			}
		}
	}
	catch (string error)
	{
	}
}

void PhonList::SortByName()
{	
	for (int i = 0; i < count-1; i++)
	{
		Node *tmpNode = Head;
		while (tmpNode->next != nullptr)
		{
			if (tmpNode->_name > tmpNode->next->_name)
			{
				string tmpName = tmpNode->_name;
				string tmpNumber = tmpNode->_phoneNumber;
				int ID = tmpNode->id;
				string tmpFile = tmpNode->messageFile;
				tmpNode->_name = tmpNode->next->_name;
				tmpNode->_phoneNumber = tmpNode->next->_phoneNumber;
				tmpNode->id = tmpNode->next->id;
				tmpNode->messageFile = tmpNode->next->messageFile;
				tmpNode->next->_name = tmpName;
				tmpNode->next->_phoneNumber = tmpNumber;
				tmpNode->next->id = ID;
				tmpNode->next->messageFile = tmpFile;
			}
			tmpNode = tmpNode->next;
		}
	}
}

void PhonList::ShowSMSlist(int pos)
{
	int i = 1;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n\t\tUse \"Left\", \"Right\", \"Up\", \"Down\"";
	cout << "\n\t\tand \"Enter\" keys arrow for nawigation ";
	SetConsoleTextAttribute(hStdOut, (WORD)((10) | 10));
	cout << "\n\n\n\t\t\t Select contact:\n";
	if (count != 0)
	{
		Node *tmp = Head;
		while (tmp != nullptr)
		{
			if (i == pos)
			{
				SetConsoleTextAttribute(hStdOut, (WORD)((14) | 14));
				cout << "\n\t\t\t " << tmp->_name << "\n";
			}
				
			else
			{
				SetConsoleTextAttribute(hStdOut, (WORD)((7) | 7));
				cout << "\n\t\t\t " << tmp->_name << "\n";
			}
			i++;
			tmp = tmp->next;
		}
	}
	SetConsoleTextAttribute(hStdOut, (WORD)((7) | 7));
}

void PhonList::MessageSort()
{
}

void PhonList::MessageListCorrect()
{
}

void PhonList::SelectContactText()
{
}

void PhonList::BackButton(int pos)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (pos == count+1)
	{
		SetYellowTextColor("\n\t\t\t\t\tBack");
	}
	else
	{
		SetConsoleTextAttribute(hStdOut, (WORD)((12) | 12));
		cout << "\n\t\t\t\t\tBack";
		SetConsoleTextAttribute(hStdOut, (WORD)((8) | 8));
	}	
}

void PhonList::SMS_Start()
{
	int pos = 0;
	int action = 0;
	if (onceEnter == 0)
	{
		ReadFromFile("phonList.txt");
		onceEnter = 1;
	}

	SortByName();

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	bool isCall = false;
	//_getch();
	do
	{
		system("cls");
		ShowSMSlist(pos);
		BackButton(pos);
		
		action = _getch();
		switch (action)
		{
		case 80: pos++;
			system("cls");			
			if (pos >= count + 2)
			{
				pos = -1;
			}
			ShowSMSlist(pos);
			BackButton(pos);
			break;
		case 72:pos--;
			system("cls");
			if (pos < -1)
			{
				pos = count+1;
			}
			ShowSMSlist(pos);
			BackButton(pos);
			break;
		case 13:
			if (pos == count+1)
			{
				action = 27;
				break;
			}
			if (pos >= 1 && pos <= count)
			{
				string tmpName, tmpPhon;
				Node *tmp = Head;
				int j = 1;
				while (j < pos)
				{
					tmp = tmp->next;
					j++;
				}
				system("cls");
				string message;
				bool isOk = true;
				int i = 1;
				Node *tmpNode = Head;
				while (i < pos)
				{
					tmpNode = tmpNode->next;
					i++;
				}
				ReadFromSMSFile(pos);
				int act = Message(pos, message);				
				while (act != 13)
				{
					switch (act)
					{
					case 77: system("cls");
						SetConsoleTextAttribute(hStdOut, (WORD)((2) | 2));
						cout << "\n\n\n\t\t\t " << tmpNode->_name;
						SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
						cout << "\n\n\t\t\t Message:\n";
						cout << "\n\t\t\t " << message;
						cout << "\n\n\t\t\t ________   _________\n\n";
						cout << "\t\t\t|   Done | |";
						SetYellowTextColor(" Cancel  ");
						cout << "|";
						cout << "\n\t\t\t ________   _________\n";
						isOk = false;
						act = _getch();
						break;
					case 75: system("cls");
						SetConsoleTextAttribute(hStdOut, (WORD)((2) | 2));
						cout << "\n\n\n\t\t\t " << tmpNode->_name;
						SetConsoleTextAttribute(hStdOut, (WORD)((15) | 15));
						cout << "\n\n\t\t\t Message:\n";
						cout << "\n\t\t\t " << message;
						cout << "\n\n\t\t\t ________   _________\n\n";
						cout << "\t\t\t|";
						SetYellowTextColor("   Done ");
						cout << "| | Cancel  |";
						cout << "\n\t\t\t ________   _________\n";
						isOk = true;
						act = _getch();
						break;
					default:
						act = _getch();
						break;
					}
				}
				if (act == 13 && isOk == true)
				{
					string fileName = CreateFileName(pos);
					WriteToFileSMS(fileName, pos, message);
					WriteToFileOutcomingCall("SMS_file.txt", pos);
				}
				else if (act == 13 && isOk == false)
				{
					break;
				}
			}			
			break;
		default:
			continue;
		}
	} while (action != 27);
}

void PhonList::WriteToSMSFile(string, int)
{
}
