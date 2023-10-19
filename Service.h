#pragma once
#include "BookRepository.h"
#include "UserRepository.h"
#include "UndoAction.h"

class Service
{
private:
	BookRepository bookRep;
	UserRepository userRep;
	vector<UndoAction*> undoActions;
public:
	//Constructor
	Service(BookRepository bookrep, UserRepository userrep) :bookRep{ bookrep }, userRep{ userrep } {}
	Service() = default;

	//Functions to add, delete and update books in the Book Repository
	void storeBook(string ISBN, string Title, string Author, string Gender, bool isAvailable);
	void deleteBook(string ISBN);
	void updateBook(string oldISBN, string ISBN, string Title, string Author, string Gender, bool isAvailable);
	vector<Book> getBookList();

	//Functions to add, delete and update users in the User Repository
	void storeUser(string ID, string Name, string phoneNumber, string emailAdress);
	void deleteUser(string ID);
	void updateUser(string oldID, string ID, string Name, string phoneNumber, string emailAdress);
	vector<User> getUserList();

	//Undo operation function
	string doUndo();
};

