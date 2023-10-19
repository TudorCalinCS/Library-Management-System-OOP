#include "Ui.h"
void Ui::Menu() {
	cout << "1.Print\n2.Add book\n3.Delete book\n4.Update book\n5.Add user\n6.Delete user\n7.Update user\n8.Undo\n";
	cout << "0.Quit\n";
}
void Ui::printMenu() {
	cout << "1.Books\n2.Users\n";
	int cmdPrint;
	cin >> cmdPrint;
	switch (cmdPrint) {
	case 1:
		printAllBooks();
		break;
	case 2:
		printAllUsers();
		break;
	}
}
void Ui::undoUi() {
	cout << "\n" << service.doUndo()<<"\n";
}

void Ui::printAllBooks() {
	cout << "\nBooks:\n";
	vector<Book> list = service.getBookList();
	for (auto& book : list) {
		cout << book.getISBN() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getGenre() << " " << book.getAvaialbility() << '\n';
	}
	cout << "\n";
}
void Ui::addBookUi() {
	string ISBN;
	cout << "\nISBN: ";
	cin >> ISBN;
	string Title;
	cout << "\nTitle: ";
	cin >> Title;
	string Author;
	cout << "\nAuthor: ";
	cin >> Author;
	string Genre;
	cout << "\nGenre: ";
	cin >> Genre;
	bool isAvailable;
	cout << "\nIs the book available?[Y/N]: ";
	string Answer;
	cin >> Answer;
	if (Answer == "Y")
		isAvailable = true;
	else isAvailable = false;
	service.storeBook(ISBN, Title, Author, Genre, isAvailable);

}
void Ui::deleteBookUi() {
	string ISBN;
	cout << "\nISBN: ";
	cin >> ISBN;
	service.deleteBook(ISBN);
}
void Ui::updateBookUi() {
	string oldISBN;
	cout << "\nOld ISBN: ";
	cin >> oldISBN;
	string ISBN;
	cout << "\nNew ISBN: ";
	cin >> ISBN;
	string Title;
	cout << "\nNew Title: ";
	cin >> Title;
	string Author;
	cout << "\nNew Author: ";
	cin >> Author;
	string Genre;
	cout << "\nNew Genre: ";
	cin >> Genre;
	bool isAvailable;
	cout << "\nIs the new book available?[Y/N]: ";
	string Answer;
	cin >> Answer;
	if (Answer == "Y")
		isAvailable = true;
	else isAvailable = false;
	service.updateBook(oldISBN, ISBN, Title, Author, Genre, isAvailable);
}
void Ui::addUserUi() {
	string ID;
	cout << "\nID: ";
	cin >> ID;
	string Name;
	cout << "\nName: ";
	cin >> Name;
	string phoneNumber;
	cout << "\nPhone Nunber: ";
	cin >> phoneNumber;
	string emailAdress;
	cout << "\nEmail Adress: ";
	cin >> emailAdress;
	service.storeUser(ID, Name, phoneNumber, emailAdress);
}
void Ui::deleteUserUi() {
	string ID;
	cout << "\nID: ";
	cin >> ID;
	service.deleteUser(ID);
}
void Ui::updateUserUi() {
	string oldID;
	cout << "\nOld ID: ";
	cin >> oldID;
	string newID;
	cout << "\nNew ID: ";
	cin >> newID;
	string Name;
	cout << "\nNew Name: ";
	cin >> Name;
	string phoneNumber;
	cout << "\nNew Phone Nunber: ";
	cin >> phoneNumber;
	string emailAdress;
	cout << "\nNew Email Adress: ";
	cin >> emailAdress;
	service.updateUser(oldID, newID, Name, phoneNumber, emailAdress);
}
void Ui::printAllUsers() {
	cout << "\nUsers:\n";
	vector<User> list = service.getUserList();
	for (auto& user : list) {
		cout << user.getID() << " " << user.getName() << " " << user.getPhone() << " " << user.getEmail() << '\n';
	}
	cout << "\n";

}
void Ui::start() {
	while (true) {
		Menu();
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 0:
			return;
		case 1:
			printMenu();
			break;
		case 2:
			addBookUi();
			break;
		case 3:
			deleteBookUi();
			break;
		case 4:
			updateBookUi();
			break;
		case 5:
			addUserUi();
			break;
		case 6:
			deleteUserUi();
			break;
		case 7:
			updateUserUi();
			break;
		case 8:
			undoUi();
			break;
		}
	}
}