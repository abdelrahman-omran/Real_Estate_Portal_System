#include "Admin.h"
#include "User.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;

Admin::Admin(string Username, string Password) {
	username = Username;
	password = Password;
}
void Admin::registerUser(map<string, Admin*>& adm) {
	string u;
	string p;
	cout << "enter your username:" << " " << endl;
	cin >> u;
	cout << "enter your password:" << " " << endl;
	cin >> p;
	adm[u] = new Admin(u, p);
}
void Admin::login(map<string, Admin*>& adm) {
	string u;
	string p;
	cout << "enter your username:" << " " << endl;
	cin >> u;
	cout << "enter your password:" << " " << endl;
	cin >> p;
	if (adm[u]->password == p) {
		cout << "Access granted" << endl;
	}
	else {
		cout << "Access denied" << endl;
	}
}
void Admin::Blacklist(map<string, User>& approvedusers, map<string, User>& Blist)
{
	string u;
	cout << "Enter the username of the user you want to blacklist:" << endl;
	cin >> u;
	if (approvedusers.find(u) != approvedusers.end()) {
		Blist[u] = approvedusers[u];
		approvedusers.erase(u);
		cout << "User " << u << " has been blacklisted." << endl;
	}
	else {
		cout << "User " << u << " not found!" << endl;
	}
}
void Admin::approve(map<string, User>& waitinglist, map<string, User>& approvedusers) {
	string u;
	cout << "Enter the username of the user you want to approve:" << " " << endl;
	cin >> u;
	if (waitinglist.find(u) != waitinglist.end()) {
		approvedusers[u] = waitinglist[u];
		waitinglist.erase(u);
		cout << "User " << u << " has been approved." << endl;
	}
	else {
		cout << "User " << u << " not found in the waiting list!" << endl;
	}
}