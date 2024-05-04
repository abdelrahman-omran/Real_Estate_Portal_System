#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Property
{
public:
	int id;
	string type;
	string location;
	Property(int ID, string Type, string Location);
	void Display();
	Property Search(int ID, map<int, Property>p);
};

