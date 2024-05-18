#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include<queue>
#include <optional>
#include "Property.h"
using namespace std;
class User
{
public:
	User();
	User(string userEmail, string userPassword, string userName);
	map<size_t, User>user;
	queue<Property> propertyQueue;
	void submit(Property& prop, queue<Property>& propertyQueue);
	static User* login(map<string, pair<string, User>>& usersAccounts, bool &access);
	void modifyName();
	void modifyPassword();
	static void removeUser(vector<User>& users, string username, string password);
	void getMyProperties();
	void display();
	void compare(vector<int>ids, map<int,Property>& p);
	void setEmail(string newEmail);
	void setPassword(string newPassword);
	void setName(string newName);
	string getPassword();
	string getUsername();
	string getEmail();

private:
	string email, password, name;
	size_t id = 1000000;
	vector<Property>userProperties;
	bool isValidEmail(string email);
	bool isValidName(string name);
	bool isValidPassword(string password);
};