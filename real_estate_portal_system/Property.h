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
	static void EditProperty(int, map<int, Property> p);
	static void RemoveProperty(int id, map<int, Property> p);
	void Display();
	void search();
	int getType();
	~Property();

};

