#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include "Property.h"
#define ll long long
#define st size_t
#define L << '\n'
#define pb push_back
#define eb emplace_back

using namespace std;
class User
{
public:
	User();
	User(const string userEmail, const string userPassword, const string userName);
	map<size_t, User>user;
	queue<Property> propertyQueue;
	void submit(const Property& prop);
	static bool login();
	static void removeUser(vector<User>& users, string username, string password);
	void getMyProperties();
	string getPassword();
	string getUsername();

private:
	string email, password, name;
	size_t id = 1000000;
	vector<Property>userProperties;
	bool isValidEmail(const string email);
	bool isValidName(const string name);
	bool isValidPassword(const string& password);
};