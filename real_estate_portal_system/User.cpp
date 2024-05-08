#include "User.h"
#include "Property.h"
#include<iostream>
#include<string>
#include<map>
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
User::User(const string userEmail, const string userPassword, const string userName)
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
bool User::isValidEmail(const string email)
{
	size_t at = email.find('@');
	size_t dot = email.find('.');
	return (at >= 9 && (dot - at) > 2);
}
bool User::isValidName(const string name)
{
	return (name.size() >= 6);
}
bool User::isValidPassword(const string& password)
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
void User::submit(const Property& prop) {
	propertyQueue.push(prop);
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

string User::getPassword() {
	return email;
}
string User::getUsername() {
	return password;
}
