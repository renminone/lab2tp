#include <iostream>
#include "Note.h"

using namespace std;

Note::Note() { }

Note::Note(string s, string n, string nu, string b[3])
{
	this->Surname = s;
	this->Name = n;
	this->number = nu;
	this->birthday[0] = b[0];
	this->birthday[1] = b[1];
	this->birthday[2] = b[2];
}

Note::Note(const Note& obj) { }

Note::~Note() { }

void Note::put()
{
	notepad.pushBack(Surname);
	notepad.pushBack(Name);
	notepad.pushBack(number);
	for (int i = 0; i < 3; i++)
		notepad.pushBack(birthday[i]);
}
ostream& operator<<(ostream& stream, Note obj)
{
	stream << obj.Surname << " ";
	stream << obj.Name << " ";
	stream << obj.number << " ";
	stream << obj.birthday[0] << "/";
	stream << obj.birthday[1] << "/";
	stream << obj.birthday[2] << "\n";

	return stream;
}

istream& operator>>(istream& stream, Note& obj)
{
	stream >> obj.Surname;
	stream >> obj.Name;
	stream >> obj.number;
	stream >> obj.birthday[0];
	stream >> obj.birthday[1];
	stream >> obj.birthday[2];

	return stream;
}
