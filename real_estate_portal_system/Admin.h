#pragma once
#include<iostream>
#include<map>
#include<string>
#include "User.h"
using namespace std;
class Admin
{
public:
	string username;
	string password;
	Admin(string Username, string Password);
	static void registerUser(map<string, Admin*>& adm);
	static void login(map<string, Admin*>& adm);
	void Blacklist(map<string, User>& approvedusers, map<string, User>& Blist);
	void approve(map<string, User>& waitinglist, map<string, User>& approvedusers);
};

