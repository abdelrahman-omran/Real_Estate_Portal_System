#include<iostream>
#include<map>
#include<string>
#include"Property.h" 
using namespace std;

Property::Property()
{
}

Property::Property(string Type, string Name, string Location, string Owner, int Room_num, double Area, double Price)
{
	type = Type;
	name = Name;
	location = Location;
	owner = Owner;
	room_num = Room_num;
	area = Area;
	price = Price;
	cout << "Adding Done." << endl;
}

void Property::EditProperty(int id, map<int, Property> p)
{
	if (p.find(id) != p.end()) {
		char choice = 'z';
		do {
			cout << "1.edit price." << endl;
			cout << "2.edit owner." << endl;
			int option;
			cin >> option;
			if (option == 1) {
				double new_price;
				cout << "Enter new price:" << endl;
				cin >> new_price;
				p.at(id).price = new_price;
			}
			else if (option == 2) {
				string new_owner;
				cout << "Enter new owner" << endl;
				cin >> new_owner;
				p.at(id).owner = new_owner;
			}
			else {
				cout << "Invalid option!" << endl;
			}
			cout << "Property " << id << " edited." << endl;
			cout << "Do you want to continue editing ?" << endl;
			cin >> choice;
		} while (choice == 'Y' || choice == 'y');
	}
	else {
		cout << "Property " << id << "not exist." << endl;
	}
}

void Property::RemoveProperty(int id, map<int, Property> p)
{
	if (p.find(id) != p.end()) {
		p.erase(id);
		cout << "Property " << id << "removed" << endl;
	}
	else {
		cout << "Property " << id << "not exist" << endl;
	}
}

Property::~Property()
{

}

void Property::Display() {
	cout << "type: "<< type << endl;
	cout << "name: " << name << endl;
	cout << "location: " << location << endl;
	cout << "owner: " << owner << endl;
	cout << "room_num: " << room_num << endl;
	cout << "area: " << area << endl;
	cout << "price: " << price << endl;
}
void Property::search()
{

}