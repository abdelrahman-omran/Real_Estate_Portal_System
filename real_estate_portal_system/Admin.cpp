#include "Admin.h"
#include "User.h"
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
int Admin::propertyID = 0;
Admin::Admin(string Username, string Password) {
	username = Username;
	password = Password;
}
bool Admin::login(map<string, string> adm) {
	string u;
	string p;
	cout << "enter your username:" << " " << endl;
	cin >> u;
	cout << "enter your password:" << " " << endl;
	cin >> p;
	if (adm[u] == p) {
		cout << "Access granted" << endl;
		return true;
	}
	else {
		cout << "Access denied" << endl;
		return false;
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
 void Admin::approve(queue<Property>& propertyQueue, map<int,Property>& p, vector<Property>& properties)
{
	if (propertyQueue.empty()) {
		cout << "No properties left to approve." << endl;
		return;
	}
	cout << "You have " << propertyQueue.size() << "properties needed to be approved." << endl;

	while (true) {
			cout << "First property newly submitted:" << endl;
			propertyQueue.front().Display();
			cout << "press 1 to approve, 2 to decline, 3 exit" << endl;
			int approve;
			cin >> approve;
			if (approve == 1) {
				properties.push_back(propertyQueue.front());
				p[Admin::propertyID] = propertyQueue.front();
				Admin::propertyID++;
				cout << "property added successfully!" << endl;
				propertyQueue.pop();
			}
			else if (approve == 2)
			{
				cout << "Property declined!" << endl;
				propertyQueue.pop();

			}
			else
			{
				return;
			}
			if (propertyQueue.empty())
			{
				cout << "No properties left to approve." << endl;
				return;
			}
	}
}