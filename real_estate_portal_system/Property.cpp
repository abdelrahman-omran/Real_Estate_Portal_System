#include "Property.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

Property::Property(int ID, string Type, string Location)
{
	id = ID;
	type = Type;
	location = Location;
}
void Property::Display()
{
	cout << "ID: " << id << endl;
	cout << "Type: " << type << endl;
	cout << "Location: " << location << endl;
}
Property Property::Search(int ID, map<int, Property>p)
{
	return p[id];
}