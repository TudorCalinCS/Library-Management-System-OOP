#pragma once
#include "BookRepository.h"
#include "UserRepository.h"

//Base class for undo actions
class UndoAction {
public:
	//Virtual desctuctor to ensure proper cleanup
	virtual ~UndoAction() = default;

	//Perform the undo action
	virtual void doUndo() = 0;

	//Describe the action that was undone
	virtual string undoComplete() = 0;
};

//Derived class for undoing a 'store book' action
class UndoStoreBook : public UndoAction {
	Book book;
	BookRepository& bookRepository;
public:
	//Constructor
	UndoStoreBook(Book b, BookRepository& bookRep) :book{ b }, bookRepository{ bookRep } {}

	//Perform the undo action by deleting the stored book
	void doUndo() override {
		bookRepository.deleteBook(book);
	}

	//Describe what undo action was performed
	string undoComplete() override {
		return "Undo 'Store Book' performed";
	}
};

//Derived class for undoing a 'delete book' action
class UndoDeleteBook : public UndoAction {
	Book book;
	BookRepository& bookRepository;
public:
	//Constructor
	UndoDeleteBook(Book b, BookRepository& bookRep) :book{ b }, bookRepository{ bookRep } {}

	//Perform the undo action by storing the deleted book
	void doUndo() override {
		bookRepository.storeBook(book);
	}

	//Describe what undo action was performed
	string undoComplete() override {
		return "Undo 'Delete Book' performed";
	}
};
class UndoStoreUser : public UndoAction {
	User user;
	UserRepository& userRepository;
public:
	UndoStoreUser(User u, UserRepository& userRep) :user{ u }, userRepository{ userRep } {}

	void doUndo() override {
		userRepository.deleteUser(user);
	}

	string undoComplete() override {
		return "Undo 'Store User' performed";
	}
};
class UndoDeleteUser : public UndoAction {
	User user;
	UserRepository& userRepository;
public:
	UndoDeleteUser(User u, UserRepository& userRep) :user{ u }, userRepository{ userRep } {}

	void doUndo() override {
		userRepository.storeUser(user);
	}

	string undoComplete() override {
		return "Undo 'Delete User' performed";
	}
};


