#include<iostream>
#include<map>
#include<string>
#include<vector>
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

void Property::EditProperty(int id, map<int, Property>& p)
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

void Property::RemoveProperty(int id, map<int, Property>& p)
{
	if (p.find(id) != p.end()) {
		p.erase(id);
		cout << "Property " << id << "removed" << endl;
	}
	else {
		cout << "Property " << id << "not exist" << endl;
	}
}
void Property::Display() {
	cout << "type: "<< type << endl;
	cout << "name: " << name << endl;
	cout << "location: " << location << endl;
	cout << "owner: " << owner << endl;
	cout << "number of bedrooms: " << room_num << endl;
	cout << "area: " << area << endl;
	cout << "price: " << price << endl;
	cout << "---------------------------------" << endl;
}
#pragma region Search
void Property::search(int id, string Type, string Location, int Room_num, double Area, double MinPrice, double MaxPrice, map<int, Property> p)
{
	if (id != -1)
	{
		if (p.find(id) != p.end())
		{
			p[id].Display();
		}
		else
		{
			cout << "No Property with this ID exists!" << endl;
		}
	}
	else
	{
		if (Type != "-1")
		{
			for (auto it = p.begin(); it != p.end();) {
				if (it->second.type != Type) {
					it = p.erase(it);
				}
				else {
					it++;
				}
			}
		}
		if (Location != "-1")
		{
			for (auto it = p.begin(); it != p.end();) {
				if (it->second.location != Location) {
					it = p.erase(it);
				}
				else {
					it++;
				}
			}
		}
		if (Room_num != -1)
		{
			for (auto it = p.begin(); it != p.end();) {
				if (it->second.room_num != Room_num) {
					it = p.erase(it);
				}
				else {
					it++;
				}
			}
		}
		if (Area != -1)
		{
			for (auto it = p.begin(); it != p.end();) {
				if (it->second.area != Area) {
					it = p.erase(it);
				}
				else {
					it++;
				}
			}
		}
		if (MinPrice != -1)
		{
			for (auto it = p.begin(); it != p.end();) {
				if (it->second.price < MinPrice) {
					it = p.erase(it); 
				}
				else {
					it++;
				}
			}
		}
		if (MaxPrice != -1)
		{
			for (auto it = p.begin(); it != p.end();) {
				if (it->second.price > MaxPrice) {
					it = p.erase(it);
				}
				else {
					it++;
				}
			}
		}
		if (p.empty())
		{
			cout << "No property exists with these features!" << endl;
		}
		else
		{
			for (auto it : p)
			{
				it.second.Display();
			}
		}
	}
}
#pragma endregion

#pragma region setters and getters
string Property::getType() {
	return type;
}
string Property::getName() {
	return name;
}
string Property::getLocation() {
	return location;
}
string Property::getOwner() {
	return owner;
}
int Property::getRooms() {
	return room_num;
}
double Property::getArea() {
	return area;
}
double Property::getPrice() {
	return price;
}
//setters
void Property::setType(string Type) {
	type = Type;
}
void Property::setName(string Name) {
	name = Name;
}
void Property::setLocation(string Location) {
	location = Location;
}
void Property::setOwner(string Owner) {
	owner = Owner;
}
void Property::setRooms(int Rooms) {
	room_num = Rooms;
}
void Property::setArea(double Area) {
	area = Area;
}
void Property::setPrice(double Price) {
	price = Price;
}
#pragma endregion