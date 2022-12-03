#pragma once
#include <iostream>
#include "vctr.h"

using namespace std;

class Note
{
	string Surname;
	string Name;
	string number;
	string birthday[3];
public:
	Note();
	Note(string s, string n, string nu, string b[3]);
	Note(const Note& obj);
	~Note();

	void put();
	void set();

	friend ostream& operator<<(ostream& stream, Note obj);
	friend istream& operator>>(istream& stream, Note& obj);
};
