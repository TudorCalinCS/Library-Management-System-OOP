#include "UserRepository.h"

void UserRepository::storeUser(const User& user) {
	userList.push_back(user);
}
User UserRepository::findUser(const string& ID) {
	for (auto& it : getUserList()) {
		if (it.getID() == ID) {
			return it;
		}
	}
}
void UserRepository::updateUser(const User& oldUser, const User& newUser) {
	deleteUser(oldUser);
	storeUser(newUser);
}
void UserRepository::deleteUser(const User& user) {
	for (int i = 0; i < userList.size(); i++) {
		User it = userList[i];
		if (it.getID() == user.getID()) {
			userList.erase(userList.begin() + i);
			return;
		}
	}
}
vector<User> UserRepository::getUserList() {
	return userList;
}


