#pragma once
#include <iostream>

using namespace std;

class Note
{
	char *surname;
	char *name;
	char* number;
	short int* birthDate;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	
	int nsize;
	Note(void);
	Note(char* s1, char* s2, char* s3, short day, short month, short year);
	Note(const Note& toCopy);
	~Note(void);

	char *getName();
	void change(void);
	Note* get(void);
	char* get(int propNum);
	short getDate(int perNum);
	void set(char* s1, char* s2, char* s3, short day, short month, short year);
	friend ostream& operator<<(ostream& out, Note& per);
	friend void operator>>(int perNum, Note& per);
};
