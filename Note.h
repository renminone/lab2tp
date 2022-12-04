#pragma once
#include <iostream>

using namespace std;

class Note
{
	char *Surname;
	char *Name;
	int number;
	int birthday[3];
public:

	Note();
	Note(char* s, char* n, int nu, int b[3]);
	Note(const Note& obj);
	~Note();

	void set();
	void get();

	friend ostream& operator<<(ostream& stream, Note obj);
	friend istream& operator>>(istream& stream, Note& obj);
};
