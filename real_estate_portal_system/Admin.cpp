#include "Admin.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;

Admin::Admin(string Username, int Password) {
	username = Username;
	password = Password;
}
void Admin::registerUser(map<string, Admin*>& adm) {
	string u;
	int p;
	cout << "enter your username:" << " " << endl;
	cin >> u;
	cout << "enter your password:" << " " << endl;
	cin >> p;
	adm[u] = new Admin(u, p);
}
void Admin::login(map<string, Admin*>& adm) {
	string u;
	int p;
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
void Admin::Blacklist(map<int, Admin*>& adm, map<int, Admin*>& Blist) {
	string u;
	int p;
	cout << "enter your username" << endl;
	cin >> u;
	cout << "enter your password" << endl;
	cin >> p;
	Blist[p] = new Admin(u, p);
	if (Blist.find(p) != Blist.end() && adm.find(p) != adm.end()) {
		delete adm[p];
		adm.erase(p);
	}
}
//void Admin::removeUser(string username, int password) {
//	for (auto it = users.begin(); it != users.end(); ++it) {
//		if (it->getUsername() == username && it->getPassword() == password) {
//			users.erase(it);
//			cout << "User '" << username << "' has been removed successfully." << endl;
//			return;
//		}
//	}
//	cout << "User not found or incorrect credentials." << endl;
//}
