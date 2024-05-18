#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;

class Property
{
private:
	map<int, Property> p;
	string type;
	string name;
	string location;
	string owner;
	int room_num;
	double area;
	double price;

public:
	Property();
	Property(string, string, string, string, int, double, double);
	static void EditProperty(int, map<int, Property>& p);
	static void RemoveProperty(int id, map<int, Property>& p);
	void Display();
	void search();
	static void search(int, string, string, int, double, double, double, map<int, Property> p);
//setters and getters
	string getType();
	string getName();
	string getLocation();
	string getOwner();
	int getRooms();
	double getArea();
	double getPrice();

	void setType(string Type);
	void setName(string Name);
	void setLocation(string Location);
	void setOwner(string Owner);
	void setRooms(int Rooms);
	void setArea(double Area);
	void setPrice(double Price);
};

