#pragma once
#include <string>
using std::string;

class User
{
private:
	string ID;
	string Name;
	string phoneNumber;
	string emailAdress;

public:
	//Constructor
	//User() = default;
	User(string id, string name, string phonenumber, string emailadress) :ID{ id }, Name{ name }, phoneNumber{ phonenumber }, emailAdress{ emailadress } {}
	//Getters
	string getID() const;
	string getName() const;
	string getPhone() const;
	string getEmail() const;
};

