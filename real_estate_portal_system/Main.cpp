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
	int inputPerson;
	string userEmail, userName, userPassword;
	map<string, Admin*> adm;
	map<int, Property>p;
	vector<User>users;
	vector<Property>properties;
	while (true) {

		cout << "***** welcome *****" << endl;
		cout << "Who are you?      1- Admin   2- User  3- Exit" << endl;
		cin >> inputPerson;
		while (inputPerson == 1) {
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
				cout << "Admin functionalities: " << endl;
				cout << "1- delete account\n2- delete property\n";
			}
			else if (n == 2) {
				Admin::login(adm);
			}
			else if (n == 3) {
				break;
			}
		}
		while(inputPerson == 2)
		{
			cout << "press 1 to register" << " " << "press 2 to login" << " " << "press 3 to exit" << endl;
			cin >> n;
			if (n == 1) {

				cout << "Enter your email" << endl;
				cin >> userEmail;
				cout << "Enter your name" << endl;
				cin >> userName;
				cout << "Enter your password" << endl;
				cin >> userPassword;

				User user(userEmail, userName, userPassword);
				users.push_back(user);
			}
			else if (n == 2) {
				cout << "enter your email" << endl;
				cin >> userEmail;
				cout << "enter your password" << endl;
				cin >> userPassword;
				int opertaion;
				while (true) {
					cout << "User functionalties: " << endl;
					cout << "1- submit property \n2- edit property \n3- remove property \n4- display properties \n5- modify account\n6- delete account\n7- Exit";
					cin >> opertaion;
					if (opertaion == 1)
					{
						string type, location;
						cout << "Enter property type" << endl;
						cin >> type;
						cout << "Enter property location" << endl;
						cin >> location;
						properties.push_back(Property(id,type, location));
						id++;
					}
					else if (opertaion == 2)
					{

					}
					else if (opertaion == 3)
					{

					}
					else if (opertaion == 4)
					{
						for (auto property = properties.begin(); property != properties.end(); ++property)
						{
							
						}
					}
					else if (opertaion == 5)
					{

					}
					else if (opertaion == 6)
					{
					
					}
					else
						break;
				}
			
			}
			else if (n == 3) {
				break;
			}
		}
		if(inputPerson == 3)
		{
			cout << "Thanks for using our application";
			break;
		}


	}
}