#pragma once
#include "stdafx.h"

using namespace std;

class Book
{
	string _name;
	string _author;
	string _genre;
	float _price;
	int _rating;
	int _id;

public:
	Book();
	string getName();
	string getAuthor();
	string getGenre();
	float getPrice();
	int getRating();
	int getID();
	void setName(string);
	void setAuthor(string);
	void setGenre(string);
	void setPrice(float);
	void setRating(int);
	void setID(int);
	void ShowBook();
	void PrintBook();
};

class Store
{
	vector<Book> arr;
	int _screen;
	int _page;
	float _cart;

public:
	Store();
	bool ReadFile();
	void ShowFiction(int);
	void ShowFantasy(int);
	void ShowDetective(int);
	void ShowHistory(int);
	void ShowNovel(int);
	void SearchAuthor(string);
	void SearchName(string);
	void SortRaiting();
	void ShowList(int);
	void OpenBook(int);
	void AddToCart(float);
	void Start();
	void BookMenu(int);
	void GenreMenu();
	void GenreBooks(int);
	void Finish();
};
