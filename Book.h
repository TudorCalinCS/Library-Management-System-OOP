#pragma once
#include <string>
using std::string;

class Book
{
	/*
	Book class with attributes like ISBN, title, author, genre, and availability status.
Implement methods for adding, updating, and removing books from the library.
Show a list of available books.
	*/
private:
	string ISBN;
	string Title;
	string Author;
	string Genre;
	bool isAvailable;
public:
	//Constructor
	//Book() = default;
	Book(string isbn, string title, string author, string genre, bool isavailable) :ISBN{ isbn }, Title{ title }, Author{ author }, Genre{ genre }, isAvailable{ isavailable } {}
	//Getters
	string getISBN() const;
	string  getTitle() const;
	string getAuthor() const;
	string getGenre() const;
	bool getAvaialbility() const;
};

