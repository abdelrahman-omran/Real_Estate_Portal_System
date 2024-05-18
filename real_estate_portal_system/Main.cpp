#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include <fstream>
#include <sstream>
#include "Admin.h"
#include "User.h"
#include "Property.h"
using namespace std;
map<string, string> adm;
map<string, pair<string, User>> usersAccounts;
map<int, Property>p;

queue<Property> propertyQueue; //FIFO,
//any other data structure, won't work.

static vector<User>users;
vector<Property>properties;
vector<int>propCompareID;

static vector<string> splitString(string& s, char del) {
	stringstream ss(s);
	string word;
	vector<string> str;
	while (getline(ss, word, del)) {
		str.push_back(word);
	}
	return str;
}

void writeFile() {
	ofstream File("File_Data.txt", ios::out | ios::trunc);
	if (File.is_open()) {
		File << "ADMIN INFO" << endl;
		for (auto it : adm) {
			File << it.first << "," << it.second << endl;
		}
		File << "USER INFO" << endl;
		for (auto it : usersAccounts) {
			File << it.second.second.getEmail() << "," << it.second.second.getPassword() << "," << it.second.second.getUsername() << endl;
		}
		File << "PROPERTY INFO" << endl;
		for (auto it : p) {
			File << it.first << "," << it.second.getType() << "," << it.second.getName() << "," << it.second.getLocation() << "," << it.second.getOwner() << "," << it.second.getRooms() << "," << it.second.getArea() << "," << it.second.getPrice() << endl;
		}
		File << "NEW PROPERTY LISTINGS" << endl;
		while (!propertyQueue.empty()) {
			File << propertyQueue.front().getType() << "," << propertyQueue.front().getName() << "," << propertyQueue.front().getLocation() << "," << propertyQueue.front().getOwner() << "," << propertyQueue.front().getRooms() << "," << propertyQueue.front().getArea() << "," << propertyQueue.front().getPrice() << endl;
			propertyQueue.pop();
		}
		File.close();
	}
	else {
		cout << "Unable to open file to write data!" << endl;
	}
}
void readFile() {

	ifstream File("File_Data.txt");
	if (File.is_open()) {
		string email, password, name;
		string line;
		vector<string>lines;
		while (getline(File, line)) {
			if (line == "ADMIN INFO")
				continue;
			if (line == "USER INFO")
				break;
			lines = splitString(line, ',');
			email = lines[0];
			password = lines[1];
			Admin Admin(email,password);
			adm[email] = password;
		}
		while (getline(File, line)) {
			if (line == "USER INFO")
				continue;
			if (line == "PROPERTY INFO")
				break;
			lines = splitString(line, ',');
			email = lines[0];
			password = lines[1];
			name = lines[2];
			User user(email, password, name);
			usersAccounts[email].first = password;
			usersAccounts[email].second = user;
		}
		while (getline(File, line)) {
			if (line == "PROPERTY INFO")
				continue;
			if (line == "NEW PROPERTY LISTINGS")
				break;
			lines = splitString(line, ',');
			int id = stoi(lines[0]);
			string type = lines[1] ;
			string name = lines[2];
			string location = lines[3];
			string owner = lines[4];
			int room_num = stoi(lines[5]);
			double area = stod(lines[6]);
			double price = stod(lines[7]);
			Property prop(type, name, location, owner, room_num, area, price);
			usersAccounts[owner].second.AddProperty(prop);
			p[id] = prop;
			}
		while (getline(File, line)) {
			if (line == "NEW PROPERTY LISTINGS")
				continue;
			lines = splitString(line, ',');
			string type = lines[0];
			string name = lines[1];
			string location = lines[2];
			string owner = lines[3];
			int room_num = stoi(lines[4]);
			double area = stod(lines[5]);
			double price = stod(lines[6]);
			Property prop(type, name, location, owner, room_num, area, price);
			propertyQueue.push(prop); // check again if they are in the right place.
			}
		File.close();
		return;
	}
	else {
		cout << "Unable to open file to read data!" << endl;
		return;
	}

}

int main() {
	readFile();
	int n;
	int id = 0;
	int inputPerson,operation;
	string userEmail, userName, userPassword;
	adm["admin"] = "admin";
	while (true) {

		cout << "***** welcome *****" << endl;
		cout << "Who are you? \n1- Admin   2- User  3- Exit" << endl;
		cin >> inputPerson;
		while(inputPerson == 1) {
			cout << "press 1 to register" << " " << "press 2 to login" << " " << "press 3 to exit" << endl;
			cin >> n;
			if (n == 1) {
				string username, password;
				cout << "You must be a super admin to register new admins!"<<endl;
				cout << "Enter super admin username"<<endl;
				cin >> username;
				cout << "Enter super admin password"<<endl;
				cin >> password;
				if (username != "admin" || password != "admin")
				{
					cout << "access denied"<<endl;
				}
				else {
					cout << "access approved" << endl;
					cout << "Enter admin username" << endl;
					cin >> username;
					cout << "Enter admin password" << endl;
					cin >> password;
					Admin admin(username, password); //O(1)
					adm[username] = password;
					cout << "do you want to continue" << endl;
					string y;
					cin >> y;
					if (y == "n" or y == "N") {
						break;
					}
				}
			}
			else if (n == 2) {
				bool access;
				access = Admin::login(adm);
				while (access)
				{
					cout << "Admin functionalities: " << endl;
					cout << "1- Display users \n2- Display properties \n3- Approve property\n4- Delete property\n5- Delete user account\n";
					cout << "6- Exit\n";
					cin >> operation;
					if (operation == 1)
					{
						for (auto it : usersAccounts) // O(N)
						{
							it.second.second.display();
						}
					}
					else if (operation == 2)
					{
						for (auto it : p) //O(N)
						{
							cout << "---------------------------------" << endl;
							cout << "ID: " << it.first << endl;
							it.second.Display(); //O(1)
						}
					}
					else if (operation == 3)
					{
						Admin::approve(propertyQueue, usersAccounts, p, properties, p.size()); //O(N)
					}
					else if (operation == 4)
					{
						int ID;
						cout << "enter the id of the property you want to remove" << endl;
						cin >> ID;
						Property::RemoveProperty(ID, p);
					}
					else if (operation == 5)
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
					else if (operation == 6) {
						break;
					}
					else {
						cout << "Invalid operation" << endl;
					}
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
				cout << "Enter your password" << endl;
				cin >> userPassword;
				cout << "Enter your name" << endl;
				cin >> userName;

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
					cout << "User functionalities: " << endl;
					cout << "1- submit property \n2- edit property \n3- remove property \n4- display properties\n5- Search Property\n";
					cout<< "6- Compare properties \n7- modify account\n8 - delete account\n9 - Exit\n";
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
						//cout << "Enter property owner" << endl;
						//cin >> owner;
						cout << "Enter property number of rooms" << endl;
						cin >> room_num;
						cout << "Enter property area" << endl;
						cin >> area;
						cout << "Enter property price" << endl;
						cin >> price;
						Property prop(type, name, location, user->getEmail(), room_num, area, price);
						user->submit(prop, propertyQueue);
					}
					else if (operation == 2)
					{
						int ID;
						cout << "enter the id of the property you want to edit"<<endl;
						cin >> ID;
						Property::EditProperty(ID, p); //O(logN)
					}
					else if (operation == 3)
					{
						int ID;
						cout << "enter the id of the property you want to remove"<<endl;
						cin >> ID;
						Property::RemoveProperty(ID, p); //O(logN)
					}
					else if (operation == 4)
					{
						int choice;
						cout << "1- Display all Properties | 2- Display My properties" << endl;
						cin >> choice;
						if (choice == 1) {
							for (auto it : p)
							{
								cout << "---------------------------------" << endl;
								cout <<"ID: " << it.first << endl;
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
						double area = -1, minPrice = -1, maxPrice;
						cout << "1- search with ID  | 2- search with features" << endl;
						cin >> s;
						if (s == 1) 
						{
							cin >> id;
							Property::search(id, type, location, room_num, area, minPrice, maxPrice, p); //O(LogN)
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
							cout << "Enter property minimum price" << endl;
							cin >> minPrice;
							cout << "Enter property maximum price" << endl;
							cin >> maxPrice;
							Property::search(id, type, location, room_num, area, minPrice, maxPrice, p); //O(N)
						}
												
					}
					else if (operation == 6)
					{
						int num,id;
						cout << "How many properties you want to compare?" << endl;
						cin >> num;
						for (int i = 1; i <= num; i++)
						{
							cout << "Enter ID: " << i << endl;
							cin >> id;
							propCompareID.push_back(id);
						}
						user->compare(propCompareID, p);
						propCompareID.clear();
					}
					else if (operation == 7)
					{
						int choice;
						cout << "1- Modify name \n2- Modify password\n";
						cin >> choice;
						if (choice == 1)
						{
							user->modifyName(); //O(1)
						}
						else if (choice == 2)
						{
							user->modifyPassword();
						}
						else
							cout << "Invalid operation" << endl;
					}
					else if (operation == 8)
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
							break;
						}
					}
					else if (operation == 9)
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
			writeFile();
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