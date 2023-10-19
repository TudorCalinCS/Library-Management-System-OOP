#include "Service.h"

//Store a new book
void Service::storeBook(string ISBN, string Title, string Author, string Genre, bool isAvailable) {
	Book book{ ISBN,Title,Author,Genre,isAvailable };
	
	//Create an undo action for storing a book
	UndoAction* action = new UndoStoreBook(book, bookRep);
	undoActions.push_back(action);
	
	//Store the created book object
	bookRep.storeBook(book);
}

//Delete an existing book
void Service::deleteBook(string ISBN) {
	//Find the book object by it's ISBN code
	Book book = bookRep.findBook(ISBN);

	//Create an undo action for deleting a book 
	UndoAction* action = new UndoDeleteBook(book, bookRep);
	undoActions.push_back(action);

	//Delete the book
	bookRep.deleteBook(book);
}

void Service::updateBook(string oldISBN, string ISBN, string Title, string Author, string Genre, bool isAvailable) {
	Book oldBook = bookRep.findBook(oldISBN);
	Book newBook{ ISBN,Title,Author,Genre,isAvailable };
	bookRep.updateBook(oldBook, newBook);
}

vector<Book> Service::getBookList() {
	return bookRep.getBookList();
}

void Service::storeUser(string ID, string Name, string phoneNumber, string emailAdress) {
	User user{ ID,Name,phoneNumber,emailAdress };
	UndoAction* action = new UndoStoreUser(user, userRep);
	undoActions.push_back(action);
	userRep.storeUser(user);
}

void Service::deleteUser(string ID) {
	User user = userRep.findUser(ID);
	UndoAction* action = new UndoDeleteUser(user, userRep);
	undoActions.push_back(action);
	userRep.deleteUser(user);
}

void Service::updateUser(string oldID, string ID, string Name, string phoneNumber, string emailAdress) {
	User oldUser = userRep.findUser(ID);
	User newUser{ ID,Name,phoneNumber,emailAdress };
	userRep.updateUser(oldUser, newUser);
}

vector<User> Service::getUserList() {
	return userRep.getUserList();
}

string Service::doUndo() {
	if (!undoActions.empty()) {
		UndoAction* action = undoActions.back();
		undoActions.pop_back();
		action->doUndo();
		string message = action->undoComplete();
		delete action;
		return message;

	}
	return "No undo actions available";
}
