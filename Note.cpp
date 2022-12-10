#define _CRT_SECURE_NO_WARNINGS
#include "Note.h"
#include <iostream>
#include <string.h>
#define FIELDSIZE 15

using namespace std;

Note::Note(void)
{
	cout << "Вызов конструктора класса Note." << endl;
	name = surname = number = nullptr;
	birthDate = nullptr;
	nsize = 0;
}

Note::Note(char* s1, char* s2, char* s3, short day, short month, short year)
{
	cout << "Вызов конструктора класса Note." << endl;
	try
	{
		if (!name) name = new char[FIELDSIZE];
		strcpy(name, s1);
		if (!surname) surname = new char[FIELDSIZE];
		strcpy(surname, s2);
		if (!number) number = new char[FIELDSIZE];
		strcpy(number, s3);
		if (!birthDate) birthDate = new short[3];
	}
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	birthDate[0] = day;
	birthDate[1] = month;
	birthDate[2] = year;
	nsize = 0;
}

Note::Note(const Note& toCopy)
{
	cout << "Вызов конструктора для класса Note." << endl;
	try
	{
		if (toCopy.name)
		{
			name = new char[FIELDSIZE];
			strcpy(name, toCopy.name);
		}
		else name = nullptr;
		if (toCopy.surname)
		{
			surname = new char[FIELDSIZE];
			strcpy(surname, toCopy.surname);
		}
		else surname = nullptr;
		if (toCopy.number)
		{
			number = new char[FIELDSIZE];
			strcpy(number, toCopy.number);
		}
		else number = nullptr;
		if (toCopy.birthDate)
		{
			birthDate = new short[3];
			for (int i = 0; i < 3; i++) birthDate[i] = toCopy.birthDate[i];
		}
		else birthDate = nullptr;
	}
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	nsize = toCopy.nsize;
}
Note::~Note(void)
{
	cout << "Вызов деструктора класса Note." << endl;
	delete[] name;
	delete[] surname;
	delete[] number;
	delete[] birthDate;
}

char* Note::getName()
{
	return name;
}

void Note::change(void)
{
	int chanProp;
	char buffErr[] = "Ошибка буфера ввода!";
	cout << "Оригинальные данные: " << endl;
	cout << endl;
	cout << *(this);
	cout << "Введите данные для изменения:\n1 - Имя.\n2 - Фамилия.\n3 - Номер.\n4 - День рождения.\n5 - Месяц рождения.\n6 - Год рождения." << endl;
	try
	{
		cin >> chanProp;
		if (cin.bad() || cin.fail()) throw buffErr;
	}
	catch (char*) { exit(1); }
	if (chanProp < 0 || chanProp>6)
	{
		cout << "Неверный режим." << endl;
		return;
	}
	chanProp--;
	try { chanProp >> *(this); }
	catch (int) { cout << "Неверные данные." << endl; return; }

}
Note* Note::get(void)
{
	Note* new_ob;
	try { new_ob = new Note(*this); }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	return new_ob;
}
char* Note::get(int propNum)
{
	switch (propNum)
	{
	case 0: return name;
	case 1: return surname;
	case 2: return number;
	}
}
short Note::getDate(int perNum) { return birthDate[perNum]; }
void Note::set(char* s1, char* s2, char* s3, short day, short month, short year)
{
	try
	{
		if (!name) name = new char[FIELDSIZE];
		strcpy(name, s1);
		if (!surname) surname = new char[FIELDSIZE];
		strcpy(surname, s2);
		if (!number) number = new char[FIELDSIZE];
		strcpy(number, s3);
		if (!birthDate) birthDate = new short[3]; 
	}
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	birthDate[0] = day;
	birthDate[1] = month;
	birthDate[2] = year;
}
ostream& operator<<(ostream& out, Note& per)
{
	out << "Имя:" << per.name << endl;
	out << "Фамилия:" << per.surname << endl;
	out << "Номер:" << per.number << endl;
	out << "Дата рождения:" << per.birthDate[0] << '.' << per.birthDate[1] << '.' << per.birthDate[2] << endl;
	out << endl;
	return out;
}
void operator>>(int perNum, Note& per)
{
	int errDate = 0;
	short b = 0;
	char buffErr[] = "Ошибка буфера ввода!";
	try
	{
		if (!per.name) per.name = new char[FIELDSIZE];
		if (!per.surname) per.surname = new char[FIELDSIZE];
		if (!per.number) per.number = new char[FIELDSIZE];
		if (!per.birthDate) per.birthDate = new short[3];
	}
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	try
	{
		switch (perNum)
		{
		case 0:
			cout << "Введите имя:" << endl;
			cin >> per.name;
			if (cin.bad() || cin.fail()) throw buffErr;
			cout << endl;
			break;
		case 1:
			cout << "Введите фамилию:" << endl;
			cin >> per.surname;
			if (cin.bad() || cin.fail()) throw buffErr;
			cout << endl;
			break;
		case 2:
			cout << "Введите номер телефона:" << endl;
			cin >> per.number;
			if (cin.bad() || cin.fail()) throw buffErr;
			cout << endl;
			break;
		case 3:
			cout << "Введите день рождения:" << endl;
			cin >> b;
			if (cin.bad() || cin.fail()) throw buffErr;
			if (b < 1 || b > 31) throw errDate;
			per.birthDate[0] = b;
			cout << endl;
			break;
		case 4:
			cout << "Введите месяц рождения:" << endl;
			cin >> b;
			if (cin.bad() || cin.fail()) throw buffErr;
			if (b < 1 || b > 12) throw errDate;
			per.birthDate[1] = b;
			cout << endl;
			break;
		case 5:
			cout << "Введите год рождения:" << endl;
			cin >> b;
			if (cin.bad() || cin.fail()) { throw buffErr; }
			if (b < 0) { throw errDate; }
			per.birthDate[2] = b;
			break;
		}
	}
	catch (char*) { exit(1); }
}
