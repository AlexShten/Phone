#include "stdafx.h"

using namespace std;

Book::Book()
{
}
string Book::getName()
{
	return _name;
}
string Book::getAuthor()
{
	return _author;
}
string Book::getGenre()
{
	return _genre;
}
float Book::getPrice()
{
	return _price;
}
int Book::getRating()
{
	return _rating;
}
int Book::getID()
{
	return _id;
}
void Book::setName(string name)
{
	_name = name;
}
void Book::setAuthor(string author)
{
	_author = author;
}
void Book::setGenre(string genre)
{
	_genre = genre;
}
void Book::setPrice(float price)
{
	_price = price;
}
void Book::setRating(int rating)
{
	_rating = rating;
}
void Book::setID(int id)
{
	_id = id;
}
void Book::ShowBook()
{
	cout << "_______________________________\n";
	cout << _id << "  " << _name << endl;
	cout << "\tby  " << _author << endl;
	cout << "\tPrice: " << _price << endl;
	cout << "_______________________________\n";
}
void Book::PrintBook()
{
	cout << endl;
	cout << " ______\n";
	cout << "|      |" << "  " << _name << endl;
	cout << "|      |" << endl;
	cout << "|      |" << "  " << _author << endl;
	cout << "|      |" << endl;
	cout << "|      |" << endl;
	cout << " ______" << endl;
	cout << endl;
	cout << "\t Price:  " << _price << "USD";
	cout << endl;
	cout << "\t Rating: ";
	for (int i = 0; i < _rating; i++)
	{
		cout << "*";
	}
	cout << endl;
}


Store::Store()
{
	_page = 0;
	_screen = 0;
	_cart = 0.0;
}
bool Store::ReadFile()
{
	enum { delimiter = ';' };
	string path = "catalog.txt";
	ifstream Fin;
	try
	{
		Fin.open(path);
		if (!Fin)
		{
			throw (string)"Cannot open catalog\n";
		}
		while (!Fin.eof())
		{
			string temp;
			Book *tempBook = new Book;
			int index;
			while (getline(Fin, temp))
			{
				int colomn = 0;
				for (int i = 0; i < 6; i++)
				{
					index = temp.find(delimiter);
					switch (colomn)
					{
					case 0:
						tempBook->setGenre(temp.substr(0, index));
						temp = temp.substr(index + 1);
						colomn++;
						break;
					case 1:
						tempBook->setName(temp.substr(0, index));
						temp = temp.substr(index + 1);
						colomn++;
						break;
					case 2:
						tempBook->setAuthor(temp.substr(0, index));
						temp = temp.substr(index + 1);
						colomn++;
						break;
					case 3:
						tempBook->setPrice(stof(temp.substr(0, index)));
						temp = temp.substr(index + 1);
						colomn++;
						break;
					case 4:
						tempBook->setRating(stoi(temp.substr(0, index)));
						temp = temp.substr(index + 1);
						colomn++;
						break;
					case 5:
						tempBook->setID(stoi(temp.substr(index + 1)));
						break;
					default:
						break;
					}
				}
				arr.push_back(*tempBook);
			}
		}
	}
	catch (string error)
	{
	}
}
void Store::ShowFiction(int page)
{
	int bookLimit = 0;
	int bookCounter = page * 5;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getGenre() == "fiction")
		{
			if (bookCounter <= 0)
			{
				arr[i].ShowBook();
				bookLimit++;
			}
			if (bookLimit >= 5)
				break;
			else
				bookCounter--;
		}
	}
}
void Store::ShowFantasy(int page)
{
	int bookLimit = 0;
	int bookCounter = page * 5;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getGenre() == "fantasy")
		{
			if (bookCounter <= 0)
			{
				arr[i].ShowBook();
				bookLimit++;
			}
			if (bookLimit >= 5)
				break;
			else
				bookCounter--;
		}
	}
}
void Store::ShowDetective(int page)
{
	int bookLimit = 0;
	int bookCounter = page * 5;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getGenre() == "detective")
		{
			if (bookCounter <= 0)
			{
				arr[i].ShowBook();
				bookLimit++;
			}
			if (bookLimit >= 5)
				break;
			else
				bookCounter--;
		}
	}
}
void Store::ShowHistory(int page)
{
	int bookLimit = 0;
	int bookCounter = page * 5;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getGenre() == "history")
		{
			if (bookCounter <= 0)
			{
				arr[i].ShowBook();
				bookLimit++;
			}
			if (bookLimit >= 5)
				break;
			else
				bookCounter--;
		}
	}
}
void Store::ShowNovel(int page)
{
	int bookLimit = 0;
	int bookCounter = page * 5;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getGenre() == "novel")
		{
			if (bookCounter <= 0)
			{
				arr[i].ShowBook();
				bookLimit++;
			}
			if (bookLimit >= 5)
				break;
			else
				bookCounter--;
		}
	}
}
void Store::SearchAuthor(string author)
{
	bool find = false;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getAuthor().compare(author) == 0)
		{
			find = true;
			arr[i].ShowBook();
		}
	}
	if (find)
	{
		cout << "_______________________________\n";

		char choise[3];
		cout << "# book:   (b - back)";
		cin >> choise;
		cin.ignore();
		if (choise[0] == 'b' || choise[0] == 'B')
		{
			system("cls");
			Start();
		}
		else if (atoi(choise) < arr.size())
		{
			system("cls");
			BookMenu(atoi(choise));
		}
	}
	else
	{
		cout << "No such author\n";
		Sleep(2000);
		system("cls");
		Start();
	}

}
void Store::SearchName(string name)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getName().compare(name) == 0)
		{
			BookMenu(arr[i].getID());
		}
	}
}
void Store::SortRaiting()
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size() - 1; j++)
		{
			if (arr[j].getRating() < arr[j + 1].getRating())
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		arr[i].ShowBook();
	}
	cout << "_______________________________\n";

	char choise[3];
	cout << "# book:   (b - back)";
	cin >> choise;
	cin.ignore();
	if (choise[0] == 'b' || choise[0] == 'B')
	{
		system("cls");
		Start();
	}
	else if (atoi(choise) < arr.size())
	{
		system("cls");
		BookMenu(atoi(choise));
	}
}
void Store::ShowList(int page)
{
	int bookLimit = 0;
	int bookCounter = page * 5;
	for (int i = 0; i < arr.size(); i++)
	{
		if (bookCounter <= 0)
		{
			arr[i].ShowBook();
			bookLimit++;
		}
		if (bookLimit >= 5)
			break;
		else
			bookCounter--;
	}
	char choose[3];
	cout << "# book:\n(B - back  H - home  N - next)";
	cin >> choose;
	if (choose[0] == 'n' || choose[0] == 'N')
	{
		system("cls");
		++_page;
		ShowList(_page);
	}
	if ((choose[0] == 'b' || choose[0] == 'B') && _page == 0)
	{
		system("cls");
		Start();
	}
	if ((choose[0] == 'b' || choose[0] == 'B') && _page > 0)
	{
		system("cls");
		--_page;
		ShowList(_page);
	}
	if (choose[0] == 'h' || choose[0] == 'H')
	{
		system("cls");
		_page = 0;
		Start();
	}
	else if (atoi(choose) < arr.size())
	{
		system("cls");
		BookMenu(atoi(choose));
	}
	else
	{
		cout << "Error: Wrong choise!";
		Sleep(2000);
		system("cls");
		ShowList(_page);
	}
}
void Store::OpenBook(int id)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].getID() == id)
		{
			arr[i].PrintBook();
			break;
		}
	}
}
void Store::AddToCart(float price)
{
	_cart += price;
}
void Store::Start()
{
	int menuSelect;
	cout << "\t\tCART: " << _cart << '$' << endl;
	cout << "_______________________________\n";
	cout << "_______________________________\n";
	cout << endl;
	cout << "1 - Show by Genre" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "2 - Search by author" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "3 - Search book title" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "4 - Show popular" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "5 - Show all" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cin >> menuSelect;
	char str[100];
	switch (menuSelect)
	{
	case 1:
		system("cls");
		GenreMenu();
		break;
	case 2:
		cout << "Input author name: ";
		cin.ignore();
		gets_s(str, 100);
		system("cls");
		SearchAuthor(str);
		break;
	case 3:
		cout << "Input book title: ";
		cin.ignore();
		gets_s(str, 100);
		system("cls");
		SearchName(str);
		break;
	case 4:
		system("cls");
		SortRaiting();
		break;
	case 5:
		system("cls");
		ShowList(0);
		break;
	default:
		system("cls");
		Start();
		break;
	}
}
void Store::BookMenu(int id)
{
	int i = 0;
	for (; i < arr.size(); i++)
	{
		if (arr[i].getID() == id)
		{
			arr[i].PrintBook();
			break;
		}
	}
	char choise;
	cout << "B - back   $ - buy this book";
	cin >> choise;
	if (choise == 'b' || choise == 'B')
	{
		system("cls");
		Start();
	}
	if (choise == '$')
	{
		AddToCart(arr[i].getPrice());
		system("cls");
		Start();
	}

}
void Store::GenreMenu()
{
	int selectGenre;
	cout << "\t\tCART: " << _cart << '$' << endl;
	cout << "_______________________________\n";
	cout << "_______________________________\n";
	cout << endl;
	cout << "1 - Fantasy" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "2 - Detective" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "3 - Fiction" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "4 - History" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << endl;
	cout << "5 - Novel" << endl;
	cout << endl;
	cout << "_______________________________\n";
	cout << "choose genre" << endl;
	cin >> selectGenre;
	GenreBooks(selectGenre);
}
void Store::GenreBooks(int gen)
{
	char choose[3];
	switch (gen)
	{
	case 1:
		system("cls");
		ShowFantasy(_page);
		cout << "# book:\n(B - back  H - home  N - next)";
		cin >> choose;
		if (choose[0] == 'n' || choose[0] == 'N')
		{
			system("cls");
			++_page;
			GenreBooks(gen);
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page == 0)
		{
			system("cls");
			GenreMenu();
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page > 0)
		{
			system("cls");
			--_page;
			GenreBooks(gen);
		}
		if (choose[0] == 'h' || choose[0] == 'H')
		{
			system("cls");
			_page = 0;
			Start();
		}
		else if (atoi(choose) < arr.size())
		{
			system("cls");
			BookMenu(atoi(choose));
		}
		else
		{
			cout << "Error: Wrong choise!";
			Sleep(2000);
			system("cls");
			GenreBooks(gen);
		}
		break;
	case 2:
		system("cls");
		ShowDetective(_page);
		cout << "# book:\n(B - back  H - home  N - next page)";
		cin >> choose;
		if (choose[0] == 'n' || choose[0] == 'N')
		{
			system("cls");
			++_page;
			GenreBooks(gen);
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page == 0)
		{
			system("cls");
			GenreMenu();
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page > 0)
		{
			system("cls");
			--_page;
			GenreBooks(gen);
		}
		if (choose[0] == 'h' || choose[0] == 'H')
		{
			system("cls");
			_page = 0;
			Start();
		}
		else if (atoi(choose) < arr.size())
		{
			system("cls");
			BookMenu(atoi(choose));
		}
		else
		{
			cout << "Error: Wrong choise!";
			Sleep(2000);
			system("cls");
			GenreBooks(gen);
		}
		break;
	case 3:
		system("cls");
		ShowFiction(_page);
		cout << "# book:\n(B - back  H - home  N - next page)";
		cin >> choose;
		if (choose[0] == 'n' || choose[0] == 'N')
		{
			system("cls");
			++_page;
			GenreBooks(gen);
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page == 0)
		{
			system("cls");
			GenreMenu();
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page > 0)
		{
			system("cls");
			--_page;
			GenreBooks(gen);
		}
		if (choose[0] == 'h' || choose[0] == 'H')
		{
			system("cls");
			_page = 0;
			Start();
		}
		else if (atoi(choose) < arr.size())
		{
			system("cls");
			BookMenu(atoi(choose));
		}
		else
		{
			cout << "Error: Wrong choise!";
			Sleep(2000);
			system("cls");
			GenreBooks(gen);
		}
		break;
	case 4:
		system("cls");
		ShowHistory(_page);
		cout << "# book:\n(B - back  H - home  N - next page)";
		cin >> choose;
		if (choose[0] == 'n' || choose[0] == 'N')
		{
			system("cls");
			++_page;
			GenreBooks(gen);
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page == 0)
		{
			system("cls");
			GenreMenu();
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page > 0)
		{
			system("cls");
			--_page;
			GenreBooks(gen);
		}
		if (choose[0] == 'h' || choose[0] == 'H')
		{
			system("cls");
			_page = 0;
			Start();
		}
		else if (atoi(choose) < arr.size())
		{
			system("cls");
			BookMenu(atoi(choose));
		}
		else
		{
			cout << "Error: Wrong choise!";
			Sleep(2000);
			system("cls");
			GenreBooks(gen);
		}
		break;
	case 5:
		system("cls");
		ShowNovel(_page);
		cout << "# book:\n(B - back  H - home  N - next page)";
		cin >> choose;
		if (choose[0] == 'n' || choose[0] == 'N')
		{
			system("cls");
			++_page;
			GenreBooks(gen);
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page == 0)
		{
			system("cls");
			GenreMenu();
		}
		if ((choose[0] == 'b' || choose[0] == 'B') && _page > 0)
		{
			system("cls");
			--_page;
			GenreBooks(gen);
		}
		if (choose[0] == 'h' || choose[0] == 'H')
		{
			system("cls");
			_page = 0;
			Start();
		}
		else if (atoi(choose) < arr.size())
		{
			system("cls");
			BookMenu(atoi(choose));
		}
		else
		{
			cout << "Error: Wrong choise!";
			Sleep(2000);
			system("cls");
			GenreBooks(gen);
		}
		break;
	default:
		system("cls");
		Start();
		break;
	}
}