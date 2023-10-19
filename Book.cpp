#include "Book.h"
string Book::getISBN() const {
	return ISBN;
}
string  Book::getTitle() const {
	return Title;
}
string Book::getAuthor() const {
	return Author;
}
string Book::getGenre() const {
	return Genre;
}
bool Book::getAvaialbility() const {
	return isAvailable;
}