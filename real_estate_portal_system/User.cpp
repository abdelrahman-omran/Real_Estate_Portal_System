#include "User.h"
#include "Property.h"
#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;
#define ll long long
#define st size_t
#define L << '\n'
#define pb push_back
#define eb emplace_back

User::User()
{
	email = "";
	password = "";
	name = "";
}
User::User(string userEmail, string userPassword, string userName)
{
	try
	{
		isValidEmail(userEmail) ? email = userEmail : throw invalid_argument("Invalid Email format!");
		isValidPassword(userPassword) ? password = userPassword : throw invalid_argument("Invalid Password format!");
		isValidName(userName) ? name = userName : throw invalid_argument("Invalid Name format!");
		id++;
		user[id] = *this;
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
}
User* User::login(map<string, pair<string, User>>& usersAccounts, bool &access)
{
		string userEmail, userPassword;
		cout << "enter your email" << endl;
		cin >> userEmail;
		cout << "enter your password" << endl;
		cin >> userPassword;
		auto it = usersAccounts.find(userEmail);
		if (it != usersAccounts.end())
		{
			if (it->second.first == userPassword)
			{
				access = true;
				return &(it->second.second);
			}
			else
			{
				cout << "Wrong Password !\n" << endl;
			}
		}
		else
		{
			cout << "No such an email !\n" << endl;
		}
		return NULL;
}
void User::modifyPassword()
{
		string newPassword;
		cout << "Enter new password please : ";
		cin >> newPassword;
		if (User::isValidPassword(newPassword))
		{
			User::setPassword(newPassword);
		}
		else
		{
			cout << "Invalid Password Format !\n";
			cout << "Please Try Again : ";
		}
}
void User::modifyName()
{
		string newName;
		cout << "Enter new name please : ";
		cin >> newName;
		if (User::isValidName(newName))
		{
			User::setName(newName);
		}
		else
		{
			cout << "Invalid Name Format !\n";
			cout << "Please Try Again : ";
		}
} 
void User::compare(vector<int>ids, map<int, Property>& p) {
	vector<Property>propCompare;
	for (int i = 0; i < ids.size(); i++) //only up to 4 so O(1)
	{
		if (p.find(ids[i]) != p.end())
		{
			propCompare.push_back(p[ids[i]]);
		}
		else
		{
			cout << "Property with id " << ids[i] << " does not exist";
		}
	}
	cout << "---------------------------------" << endl;
	cout << "Type     | ";
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getType() << "		| ";
	}
	cout << endl;

	cout << "Name     | ";
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getName() << "		| ";
	}
	cout << endl;

	cout << "Location | ";
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getLocation() << "		| ";
	}
	cout << endl;

	cout << "Owner    | ";
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getOwner() << "		| ";
	}
	cout << endl;

	cout << "Bedrooms | ";
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getRooms() << "		| ";
	}
	cout << endl;

	cout << "Area     | "  ;
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getArea() << "		| ";
	}
	cout << endl;

	cout << "Price    | "  ;
	for (int i = 0; i < propCompare.size(); i++)
	{
		cout << propCompare[i].getPrice() << "		| ";
	}
	cout << endl;
	cout << "---------------------------------" << endl;
}
void User::submit(Property& prop, queue<Property>& propertyQueue) {
	propertyQueue.push(prop);
}
void User::AddProperty(Property& prop) //only used while writing from file
{ 
	userProperties.push_back(prop);
}

void User::getMyProperties() {
	for (auto prop : userProperties) {
		prop.Display();
	}
}

void User::removeUser(vector<User>& users, string username, string password) {
	for (auto it = users.begin(); it != users.end(); ++it) {
		if (it->getUsername() == username && it->getPassword() == password) {
			users.erase(it);
			cout << "User '" << username << "' has been removed successfully." << endl;
			return;
		}
	}
	cout << "User not found or incorrect credentials." << endl;
}
void User::display() {
	cout << "---------------------------------" << endl;
	cout << "Email: " << email << endl;
	cout << "Username: " << name << endl;
	cout << "Number of properties: " << userProperties.size()<<endl;
	cout << "Password: " << password <<endl;
	cout << "---------------------------------" << endl;
}

#pragma region Checking valid inputs
bool User::isValidEmail(string email)
{
	size_t at = email.find('@');
	size_t dot = email.find('.');
	return (at >= 9 && (dot - at) > 2);
}
bool User::isValidName(string name)
{
	return (name.size() >= 6);
}
bool User::isValidPassword(string password)
{
	bool hasChars = false;
	bool hasNumbers = false;
	bool valid = true;
	for (char ch : password)
	{
		if (isalpha(ch))
		{
			hasChars = true;
		}
		else if (isdigit(ch))
		{
			hasNumbers = true;
		}
		else
		{
			valid = false;
		}
		if (hasChars && hasNumbers && valid && password.size() >= 10)
		{
			return true;
		}
	}
	return false;
}
#pragma endregion

#pragma region Setter and getter
void User::setEmail(string newEmail)
{
	email = newEmail;
}

void User::setPassword(string newPassword)
{
	password = newPassword;
}

void User::setName(string newName)
{
	name = newName;
}

string User::getPassword() {
	return password;
}
string User::getUsername() {
	return name;
}
string User::getEmail() {
	return email;
}
#pragma endregion
