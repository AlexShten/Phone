#pragma once
#include "stdafx.h"

using namespace std; 

struct Node
{
	string _name;
	string _phoneNumber;
	int id = 0;
	string messageFile;
	Node *next;
	Node *prev;
};

class PhonList
{
private:

public:
	Node *Head;
	Node *Tail;
	int count;
	int onceEnter;
	string myOperator;

	PhonList();
	~PhonList();
	void ShowPB();
	void ShowColorList(int, bool);
	void ColorPrint(int);
	void SetYellowTextColor(string);
	void AddInTail(string, string, int, string);
	void DelByPos(int);
	int FindByName(string);
	bool Call(int);
	bool CallNewNumber(string);
	void FacePaint();
	int Message(int, string&);
	void ReadFromFile(string);
	void WriteToFile(string);
	void WriteToFileOutcomingCall(string, int);
	void WriteToFileOutcomingSMS(string, int);
	void WriteToFileSMS(string, int, string);
	void SortByName();
	int GetMaxID();
	string CreateFileName(int);
	void PB_Start(string);
	void SMS_Start(string);
	void ShowSMSlist(int);
	void MessageListCorrect();
	void SelectContactText();
	void BackButton(int);
	void ReadFromSMSFile(int);
};

