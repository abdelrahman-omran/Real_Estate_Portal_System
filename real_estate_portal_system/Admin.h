#pragma once
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include "User.h"
using namespace std;
class Admin
{
public:
	static int propertyID;
	Admin(string Username, string Password);
	static bool login(map<string, string> adm);
	void Blacklist(map<string, User>& approvedusers, map<string, User>& Blist);
	static void approve(queue<Property>& propertyQueue, map<string, pair<string, User>> &usersAccounts
	,map<int, Property>& p, vector<Property>& properties, int size);
private:
	string username;
	string password;
};

