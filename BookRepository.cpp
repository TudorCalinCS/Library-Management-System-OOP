#include "BookRepository.h"

void BookRepository::storeBook(const Book& book) {
	bookList.push_back(book);
}
Book BookRepository::findBook(const string& ISBN) {
	for (auto& it : getBookList()) {
		if (it.getISBN() == ISBN) {
			return it;
		}
	}
}
void BookRepository::updateBook(const Book& oldBook, const Book& newBook) {
	deleteBook(oldBook);
	storeBook(newBook);
}
void BookRepository::deleteBook(const Book& book) {
	for (int i = 0; i < bookList.size(); i++) {
		Book it = bookList[i];
		if (it.getISBN() == book.getISBN()) {
			bookList.erase(bookList.begin() + i);
			return;
		}
	}
}
vector<Book> BookRepository::getBookList() {
	return bookList;
}
