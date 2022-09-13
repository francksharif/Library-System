#include <iostream>
#include <string.h>
#include "Header.h"

using namespace std;

struct book {
	int id;
	string name;
	int quantity;
};

struct user {
	string id;
	string name;
	char status;
};

int const MAX = 10000;
book books[MAX];
user users[MAX];
int book_add = 0; // book add index
int user_add = 0; // users add index

// Add a new book  in the system with ID and NAME	
void Add_New_Book()
{
	cout << "Enter book Name :";
	cin >> books[book_add].name;
	cout << "Enter book ID:";
	cin >> books[book_add].id;
	cout << "Enter book Quantity:";
	cin >> books[book_add].quantity;
	cout << "book added!\n";
	cout << endl << endl;
	++book_add;
}





void Search_Book_Prefix()
{
	string prefix;
	cout << "Enter prefix of the book :";
	cin >> prefix;
	int z = 0;


	for (size_t i = 0; i < book_add; i++)
	{
		bool verify = false;
		for (size_t j = 0; j < prefix.size(); j++)
		{
			if (prefix[j] == books[i].name[j])
			{
				verify = true;
			}
		}
		if (verify)
		{
			cout << books[i].name << endl;
			++z;
		}
	}

	if (z == 0)
	{
		cout << "No element found in the library!\n";
	}
	cout << endl << endl;
}




void Book_Borrowers()
{
	int book_id;
	cout << "Enter User Name :";
	cin >> users[user_add].name;
	cout << "Enter national ID:";
	cin >> users[user_add].id;
	cout << "Enter book you want to borrow ID :";
	cin >> book_id;
	bool check = false;
	for (size_t i = 0; i < book_add; i++)
	{
		if (book_id == books[i].id)
		{
			check == true;
			users[user_add].status = 'B';
			--books[i].quantity;
			cout << "Saved!\n";
			cout << endl << endl;
		}
	}


	if (check = false)
	{
		cout << "This book ID does not exist please try another one!\n";
    }

	cout << endl << endl;
	++user_add;
}






void Print_Books()
{
	for (int i = 0; i < book_add; i++)
	{
		cout << "-Book Name : " << books[i].name << "       -Book ID : " << books[i].id << "        -Book Quantity : " << books[i].quantity << endl;
	}
	cout << endl << endl;
}





void Book_Returns()
{
	string user_id;
	int book_id = 0;
	bool user_check = false, book_check = false;
	cout << "You want to return a book what is your national ID please :";
	cin >> user_id;

	for (int i = 0; i < user_add; ++i)
	{
		if (user_id == users[i].id)
		{
			user_check = true;
			cout << "User found !\n";
			cout << "What is the book ID do you want to return please? : ";
			cin >> book_id;

			for (size_t j = 0; j < book_add; j++)
			{
				if (book_id == books[j].id)
				{
					book_check = true;
					cout << "Book has been found and returned ! Thank you!\n";
					users[i].status = 'R';
					++books[j].quantity;
				}
			}
		}
	}
	cout << endl << endl;

	if (user_check == false)
	{
		cout << "This user ID has not been found please try another one!\n";
		cout << endl << endl;
		return;
	}

	else if (book_check == false)
	{
		cout << "This book ID dos not exist in the library please try another one !\n";
		cout << endl << endl;
		return;
	}
}




void Print_All_Users()
{
	for (size_t i = 0; i < user_add; i++)
	{
		cout << "-User Name : " << users[i].name << "       -User ID : " << users[i].id << "    -Status : "<< users[i].status << endl;
	}
	cout << endl << endl;
}





int main()
{

	// Create the main menu 

	int choice = 0;
	while (choice != 7)
	{
		cout << "Library Menu \n";
		cout << "1-Add a new book \n";
		cout << "2-Search book by prefix \n";
		cout << "3-Users Borrows\n";
		cout << "4-Print Library Books\n";
		cout << "5-Users Returns\n";
		cout << "6-Print Users \n";
		cout << "7-Exit\n";
		cout << "choose your option : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			Add_New_Book();
			break;
		case 2:
			Search_Book_Prefix();
			break;
		case 3:
			Book_Borrowers();
			break;
		case 4:
			Print_Books();
			break;
			break;
		case 5:
			Book_Returns();
			break;
		case 6:
			Print_All_Users();
			break;
		case 7:
			break;

		default:
			cout << "Choose between 1 and 8!\n";
			break;
		}
	}





	return 0;
}