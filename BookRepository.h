#pragma once
#include "Book.h"
#include <vector>
using std::vector;
class BookRepository
{
private:
	vector<Book> bookList;
public:
	void storeBook(const Book& book);
	Book findBook(const string& ISBN);
	void updateBook(const Book& oldBook, const Book& newBook);
	void deleteBook(const Book& book);
	vector<Book> getBookList();
};
