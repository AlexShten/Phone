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
	void FacePaint();
	int Message(int, string&);
	void ReadFromFile(string);
	void WriteToFile(string);
	void WriteToFileOutcomingCall(string, int);
	void WriteToFileSMS(string, int, string);
	void SortByName();
	int GetMaxID();
	string CreateFileName(int);
	void PB_Start();
	void SMS_Start();
	void WriteToSMSFile(string, int);
	void ShowSMSlist(int);
	void MessageSort();
	void MessageListCorrect();
	void SelectContactText();
	void BackButton(int);
	void ReadFromSMSFile(int);
};

