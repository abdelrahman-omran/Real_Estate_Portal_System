#include<iostream>
#include<string>
#include<map>
#include<vector>
#include "Admin.h"
#include "User.h"
#include "Property.h"
using namespace std;

int main() {
	int n;
	int id = 0;
	int inputPerson,operation;
	string userEmail, userName, userPassword;

	map<string, Admin*> adm;
	map<string, pair<string,User>>usersAccounts;
	map<int, Property>p;

	vector<User>users;
	vector<Property>properties;

	while (true) {

		cout << "***** welcome *****" << endl;
		cout << "Who are you? \n1- Admin   2- User  3- Exit" << endl;
		cin >> inputPerson;
		while(inputPerson == 1) {
			cout << "press 1 to register" << " " << "press 2 to login" << " " << "press 3 to exit" << endl;
			cin >> n;
			if (n == 1) {

				Admin::registerUser(adm);
				cout << "do you want to continue" << endl;
				string y;
				cin >> y;
				if (y == "n" or y == "N") {
					break;
				}
			}
			else if (n == 2) {
				Admin::login(adm);
				cout << "Admin functionalities: " << endl;
				cout << "1- Display users \n2- Display properties\n3- delete property\n4- delete user account\n";
				cin >> operation;
				if (operation == 1)
				{
					for (auto it : usersAccounts)
					{
						it.second.second.display();
					}
				}
				else if (operation == 2)
				{
					for (auto it : p)
					{
						it.second.Display();
						cout << "--------------------------------" << endl;
					}
				}
				else if (operation == 3)
				{
					int ID;
					cout << "enter the id of the property you want to remove" << endl;
					cin >> ID;
					Property::RemoveProperty(ID, p);
				}
				else if (operation == 4)
				{
					string username, password;
					cout << "Enter username" << endl;
					cin >> username;
					cout << "Enter password" << endl;
					cin >> password;
					int confirm;
					cout << "Are you sure you want to delete this account?\n type 1 to confirm\n";
					cin >> confirm;
					if (confirm == 1) {
						User::removeUser(users, username, password);
						usersAccounts.erase(username);
					}
				}
				else if (operation == 5) {
					break;
				}
				else {
					cout << "Invalid operation" << endl;
				}
			}
			else if (n == 3) {
				break;
			}
			else {
				cout << "Invalid operation" << endl;
			}
		}
		while(inputPerson == 2)
		{
			cout << "press 1 to register | press 2 to login | press 3 to exit" << endl;
			cin >> n;
			if (n == 1) {

				cout << "Enter your email" << endl;
				cin >> userEmail;
				cout << "Enter your name" << endl;
				cin >> userName;
				cout << "Enter your password" << endl;
				cin >> userPassword;

				User user(userEmail, userPassword, userName);
				users.push_back(user);
				usersAccounts[userEmail].first = userPassword;
				usersAccounts[userEmail].second = user;
			}
			else if (n == 2)
			{
				bool access = false;
				User* user = User::login(usersAccounts, access);
				while (access) {
					cout << "User functionalties: " << endl;
					cout << "1- submit property \n2- edit property \n3- remove property \n4- display properties\n5- Search Property\n";
					cout<< "6- modify account\n7 - delete account\n8 - Exit\n";
					cin >> operation;
					if (operation == 1)
					{
						string type, name, location, owner;
						int room_num;
						double area, price;
						cout << "Enter property type" << endl;
						cin >> type;
						cout << "Enter property name" << endl;
						cin >> name;
						cout << "Enter property location" << endl;
						cin >> location;
						cout << "Enter property owner" << endl;
						cin >> owner;
						cout << "Enter property number of rooms" << endl;
						cin >> room_num;
						cout << "Enter property area" << endl;
						cin >> area;
						cout << "Enter property price" << endl;
						cin >> price;
						Property prop(type, name, location, owner, room_num, area, price);
						user->submit(prop);
						properties.push_back(prop);
						p[id] = prop;
						id++;
					}
					else if (operation == 2)
					{
						int ID;
						cout << "enter the id of the property you want to edit"<<endl;
						cin >> ID;
						Property::EditProperty(ID, p);
					}
					else if (operation == 3)
					{
						int ID;
						cout << "enter the id of the property you want to remove"<<endl;
						cin >> ID;
						Property::RemoveProperty(ID, p);
					}
					else if (operation == 4)
					{
						int choice;
						cout << "1- Display all Properties | 2- Display My properties" << endl;
						cin >> choice;
						if (choice == 1) {
							for (auto it : p)
							{
								it.second.Display();
							}
						}
						else if (choice == 2)
						{
							user->getMyProperties();
						}
						else
						{
							cout << "Invalid operation" << endl;
						}
					}
					else if (operation == 5)
					{
						int s,id = -1;
						string type = "-1", location = "-1";
						int room_num = -1;
						double area = -1, price = -1;
						cout << "1- search with ID  | 2- search with features" << endl;
						cin >> s;
						if (s == 1)
						{
							cin >> id;
							Property::search(id, type, location, room_num, area, price, p);
						}
						else{
							cout << "Enter the value for each feature (type -1 to skip feature)" << endl;
							cout << "Enter property type" << endl;
							cin >> type;
							cout << "Enter property location" << endl;
							cin >> location;
							cout << "Enter property number of bedrooms" << endl;
							cin >> room_num;
							cout << "Enter property area" << endl;
							cin >> area;
							cout << "Enter property price" << endl;
							cin >> price;
							Property::search(id, type, location, room_num, area, price, p);
						}
												
					}
					else if (operation == 6)
					{
						int choice;
						cout << "1- Modify name \n2- Modify password\n";
						cin >> choice;
						if (choice == 1)
						{
							user->modifyName();
						}
						else if (choice == 2)
						{
							user->modifyPassword();
						}
						else
							cout << "Invalid operation" << endl;
					}
					else if (operation == 7)
					{
						string username, password;
						cout << "Enter your username" << endl;
						cin >> username;
						cout << "Enter your password" << endl;
						cin >> password;
						int confirm;
						cout << "Are you sure you want to delete your account?\n type 1 to confirm\n";
						cin >> confirm;
						if (confirm == 1) {
							User::removeUser(users, username, password);
							usersAccounts.erase(username);
						}
							
					}
					else if (operation == 8)
					{
						break;
					}
					else
					{
						cout << "Invalid operation" << endl;
					}
				}

			
			}
			else if (n == 3) {
				break;
			}
			else
			{
				cout << "Invalid operation" << endl;
			}
		}
		if(inputPerson == 3)
		{
			cout << "Thanks for using our application"<<endl;
			break;
		}
		else
		{
			cout << "Invalid operation" << endl;
		}


	}
	return 0;
}