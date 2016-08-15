#pragma once
#include "stdafx.h"

using namespace std;

class Date
{
private:
	int month;
	int year;
	int day;

public:
	int getMonth();
	int getDay();
	int getYear();
	void init();
	void init(int, int, int);
	void print();
	void print(int);
	void ShowDate();
	bool operator==(Date);
};

struct Task
{
	Date tmp;
	string task;
};

void ShowTask(Task *);

void GetTask(Task *);

class Organizer
{
private:
	Task *arr;
	int count;
	int sizeOf;

public:
	Task getArr();
	Organizer();
	void addTask();
	void Show();
	void FindTask(Date);
	void FindTask(string);
	void Start();
}; 