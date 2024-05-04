#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;
class Admin
{
public:
	string username;
	int password;
	Admin(string Username, int Password);
	static void registerUser(map<string, Admin*>& adm);
	static void login(map<string, Admin*>& adm);
	void removeUser(string username, int password);
	void Blacklist(map<int, Admin*>& adm, map<int, Admin*>& Blist);
};

