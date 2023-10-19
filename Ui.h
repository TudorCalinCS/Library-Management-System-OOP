#pragma once
#include "Service.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
class Ui
{
private:
	Service service;
public:
	//Constructor
	Ui(Service serv) :service{ serv } {}
	
	void start();
	void Menu();
	void printMenu();
	void undoUi();

	void printAllBooks();
	void addBookUi();
	void deleteBookUi();
	void updateBookUi();

	void addUserUi();
	void deleteUserUi();
	void updateUserUi();
	void printAllUsers();
};

