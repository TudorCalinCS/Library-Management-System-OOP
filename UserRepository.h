#pragma once
#include "User.h"
#include <vector>
using std::vector;
class UserRepository
{
private:
	vector<User> userList;
public:
	void storeUser(const User& user);
	User findUser(const string& ID);
	void updateUser(const User& oldUser, const User& newUser);
	void deleteUser(const User& user);
	vector<User> getUserList();
};
