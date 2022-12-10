#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Keeper.h"
#define FIELDSIZE 15
#define AUXSTRLEN 50

using namespace std;

void keeper::add(Note* toInsert)
{
	place* new_place;
	try { new_place = new place(toInsert); }

	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	new_place->next = head;
	head->prev = new_place;
	head = new_place;
	amount++;
}

void keeper::addToEnd(Note* toInsert)
{
	place* new_place;
	try { new_place = new place(toInsert); }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	new_place->prev = tail->prev;
	new_place->next = tail;
	tail->prev = new_place;
	if (new_place->prev) new_place->prev->next = new_place;
	else head = new_place;
	amount++;
}
void keeper::insert(int pos, Note* toInsert)
{
	place* new_place;
	place* p = head;
	if (pos <= 1)
	{
		this->add(toInsert);
		return;
	}
	if (pos > amount)
	{
		this->addToEnd(toInsert);
		return;
	}
	try { new_place = new place(toInsert); }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	pos -= 2;
	while (pos--) p = p->next;
	new_place->next = p->next;
	new_place->prev = p;
	p->next->prev = new_place;
	p->next = new_place;
	amount++;
}
void keeper::copy(int sou, int dest)
{
	if (sou <= 0 || sou > amount)
	{
		int er = 1;
		throw er;
		return;
	}
	place* p = head;
	sou--;
	while (sou)
	{
		p = p->next;
		sou = sou - 1;
	}
	this->insert(dest, p->ntp->get());
}
void keeper::del(int num)
{
	place* p = head;
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
	}
	if (num > amount || num <= 0)
	{
		double er1 = 1.0;
		throw er1;
		return;
	}
	num--;
	while (num > 0)
	{
		p = p->next;
		num--;
	}
	if (p->prev) p->prev->next = p->next;
	else head = head->next;
	p->next->prev = p->prev;
	delete p;
	amount--;
}
void keeper::changeEl(int num)
{
	place* p = head;
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
		return;
	}
	if (num > amount || num <= 0)
	{
		double er1 = 1.0;
		throw er1;
		return;
	}
	num--;
	while (num > 0)
	{
		p = p->next;
		num--;
	}
	p->ntp->change();
}
void keeper::show(void)
{
	place* p = head;
	while (p->next != nullptr)
	{
		cout << *(p->ntp);
		p = p->next;
	}
}
void keeper::search(int perVal, int perNum)
{
	place* p = head;
	int found = 0;
	if (!amount) { int er = 1; throw er; }
	while (p->next)
	{
		if (p->ntp->getDate(perNum) == perVal)
		{
			found = 1;
			cout << *(p->ntp);
		}
		p = p->next;
	}
	if (!found) cout << "Ничего не найдено!" << endl;
}
void keeper::clear(void)
{
	place* p = head;
	while (amount)
	{
		p = head;
		head = head->next;
		delete p;
		amount = amount - 1;
	}
	head->prev = nullptr;
}
void keeper::sort(int mode)
{
	place* p = head;
	place* p1 = head->next;
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
	}
	unsigned prev = 0;
	bool exit = true;

	while (p->next->next != nullptr)
	{
		p1 = p->next;
		while (p1->next != nullptr)
		{
			if (mode == 1)
			{
				if (strcmp(p->ntp->getName(), p1->ntp->getName()) < 0)
				{
					auto tmp = p->ntp;
					p->ntp = p1->ntp;
					p1->ntp = tmp;
				}
			}
			else
			{
				if (strcmp(p->ntp->getName(), p1->ntp->getName()) > 0)
				{
					auto tmp = p->ntp;
					p->ntp = p1->ntp;
					p1->ntp = tmp;
				}
			}
			p1 = p1->next;
		}
		p = p->next;
	}
}
place* keeper::operator[](int i)
{
	i--;
	place* p = head;
	while (i--) p = p->next;
	return p;
}
keeper::keeper()
{
	cout << "Вызов конструктора класса Keeper." << endl;
	try { head = tail = new place; }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	amount = 0;
}
keeper::keeper(Note* rec)
{
	cout << "Вызов конструктора без параметров класса Keeper." << endl;
	try { head = tail = new place; }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	amount = 0;
	this->add(rec);
}
keeper::keeper(const keeper& toCopy)
{
	cout << "Вызов конструктора копирования класса Keeper." << endl;
	place* ob_p = toCopy.tail->prev;
	try { head = tail = new place; }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	amount = 0;
	while (ob_p != nullptr)
	{

		this->add(ob_p->ntp->get());
		ob_p = ob_p->prev;
		amount++;
	}
}
keeper::~keeper()
{
	cout << "Вызов деструктора класса Keeper." << endl;
	place* p = head;
	while (p != nullptr)
	{
		p = p->next;
		delete head;
		head = p;
	}
}
ostream& operator<<(ostream& stream, const keeper& cont)
{
	place* p = cont.head;
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
		return stream;
	}
	int i = 1;
	while (p->next != nullptr)
	{
		stream << "Человек " << i << ':' << endl;
		stream << *(p->ntp);
		p = p->next;
		i++;
	}
	return stream;
}
istream& operator>>(istream& stream, keeper& cont)
{
	int insMode = 0;
	int insPos = 0;
	Note* g_ptr = nullptr;
	char buffErr[] = "Ошибка буфера ввода.";
	try { g_ptr = new Note; }
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	try { for (int i = 0; i < 6; i++) i >> *(g_ptr); }
	catch (int)
	{
		cout << "Неверная дата!" << endl;
		delete g_ptr;
		return stream;
	}
	cout << endl;
	cout << "Выберите, куда вставить элемент: 0 - в начало, 1 - на заданную позицию, 2 - в конец." << endl;
	try
	{
		cin >> insMode;
		if (cin.bad() || cin.fail()) throw buffErr;
	}
	catch (char*) { exit(1); }
	if (insMode < 0 || insMode>2)
	{
		cout << "Неверная позиция. Объекты будут записаны в начало" << endl;
		insMode = 0;
	}
	switch (insMode)
	{
	case 0:
		cont.add(g_ptr);
		break;
	case 1:
		cout << "Введите новую позицию: " << endl;
		try
		{
			cin >> insPos;
			if (cin.bad() || cin.fail()) throw buffErr;
		}
		catch (char*) { exit(1); }
		cont.insert(insPos, g_ptr);
		break;
	case 2:
		cont.addToEnd(g_ptr);
		break;
	}

	return stream;
}

void keeper::loadToFile(char* name)
{
	ofstream file(name, ios::out | ios::trunc);
	if (!file)
	{
		cout << "Ошибка открытия файла." << endl;
		return;
	}
	file << "Записная книжка." << endl;
	file << "\n\n";
	place* p = tail->prev;
	int i = 1;
	if (p == nullptr)
	{
		int er = 1;
		throw er;
		file.close();
		return;
	}
	while (p != nullptr)
	{
		file << *(p->ntp);
		p = p->prev;
	}
	file.close();
}

void keeper::loadFromFile(char* name)
{
	ifstream file(name, ios::in);
	if (!file)
	{
		cout << "Ошибка открытия файла!" << endl;
		return;
	}
	place* p = head;
	this->clear();
	Note* g_ptr = nullptr;
	char t = 0;
	char sp = 0;
	short date[3] = { 0 };
	char buffErr[] = "Ошибка буфера ввода.";
	char incData[] = "Другой тип данных";
	short perF = 0;
	short digF = 0;
	short busF = 0;
	char* pos = 0;
	char* numPos = 0;
	char* s;
	char* lows;
	char** fields;
	try
	{
		s = new char[AUXSTRLEN];
		lows = new char[AUXSTRLEN];
		fields = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			fields[i] = new char[FIELDSIZE];
			memset(fields[i], 0, FIELDSIZE);
		}
	}
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	while (file)
	{
		file.getline(s, AUXSTRLEN);
		strcpy(lows, s);
		_strlwr(lows);
		try
		{
			if ((pos = strstr(lows, "Имя:")) != NULL && strstr(lows, "Фамилия:") == NULL)
			{

				if (t) throw 'b';
				g_ptr = new Note;
				t = 1;
				if (perF == 0) perF = 1;
				else throw incData; 
				pos = s + (lows - pos) + 5;
				strcpy(fields[0], pos);
			}
			else if ((pos = strstr(lows, "Фамилия:")) != NULL)
			{
				if (perF == 1) perF = 2;
				else throw incData; 
				pos = s + (lows - pos) + 8;
				strcpy(fields[1], pos);
			}
			else if ((pos = strstr(lows, "Номер:")) != NULL)
			{
				if (perF == 2) perF = 3;
				else throw incData; 
				pos = s + (lows - pos) + 12;
				strcpy(fields[2], pos);
			}
			else if ((pos = strstr(lows, "Дата рождения:")) != NULL)
			{
				if (perF == 3) perF = 0; 
				else throw incData; 
				pos = s + (lows - pos) + 14;
				t = 0;
				numPos = pos;
				for (int i = 0; i < 3;)
				{
					if (isdigit(*(numPos))) digF = 1; 
					else if (digF)
					{
						digF = 0;
						sp = *numPos;
						*numPos = '\0';
						date[i] = atoi(pos);
						*numPos = sp;
						pos = numPos + 1;
						i++;
					}
					else if (*numPos == '\0')
					{
						perF = i + 3;
						throw t;
					}
					numPos++;
				}
				if (date[0] < 1 || date[0]>31 || date[1] < 1 || date[1]>12 || date[2] < 0) throw incData; 
				g_ptr->set(fields[0], fields[1], fields[2], date[0], date[1], date[2]);
				this->addToEnd(g_ptr);
				g_ptr = nullptr;
				for (int i = 0; i < 3; i++) memset(fields[i], 0, FIELDSIZE); 
				for (int i = 0; i < 3; i++) date[i] = 0; 
			}
		}
		catch (char* er)
		{
			cout << er << endl;
			perF = 0;
			t = 0;
			for (int i = 0; i < 3; i++) memset(fields[i], 0, FIELDSIZE);
			for (int i = 0; i < 3; i++) date[i] = 0;
			if (g_ptr)
			{
				delete g_ptr;
				g_ptr = nullptr;
			}
		}
		catch (char dig)
		{

			cout << "В объекте отсутствуют: " << endl;
			cout << endl;
			if (fields[0][0]) { cout << "Имя:" << fields[0] << endl; }
			if (fields[1][0]) { cout << "Фамилия:" << fields[1] << endl; }
			if (fields[2][0]) { cout << "Номер:" << fields[2] << endl; }
			if (date[0]) { cout << "День рождения:" << date[0] << endl; }
			if (date[1]) { cout << "Месяц рождения:" << date[1] << endl; }
			cout << endl;
			cout << "Вы можете ввести: " << endl;
			cout << endl;
			switch (perF)
			{
			case 0:
				cout << "Введите новое имя: " << endl;
				try
				{
					cin >> fields[0];
					if (cin.bad() || cin.fail()) throw buffErr; 
				}
				catch (char*) { exit(1); }
			case 1:
				cout << "Введите новую фамилию: " << endl;
				try
				{
					cin >> fields[1];
					if (cin.bad() || cin.fail()) throw buffErr;
				}
				catch (char*) { exit(1); }
			case 2:
				cout << "Введите новый номер: " << endl;
				try
				{
					cin >> fields[2];
					if (cin.bad() || cin.fail()) throw buffErr; 
				}
				catch (char*) { exit(1); }
			case 3:
				cout << "Введите новый день рождения: " << endl;
				try
				{
					cin >> date[0];
					if (cin.bad() || cin.fail()) throw buffErr; 
				}
				catch (char*) { exit(1); }
			case 4:
				cout << "Введите новый месяц рождения: " << endl;
				try
				{
					cin >> date[1];
					if (cin.bad() || cin.fail()) throw buffErr; 
				}
				catch (char*) { exit(1); }
			case 5:
				cout << "Введите новый год рождения: " << endl;
				try
				{
					cin >> date[2];
					if (cin.bad() || cin.fail()) throw buffErr;
				}
				catch (char*) { exit(1); }
			}
			if (!(date[0] < 1 || date[0]>31 || date[1] < 1 || date[1]>12 || date[2] < 0))
			{
				g_ptr->set(fields[0], fields[1], fields[2], date[0], date[1], date[2]);
				this->addToEnd(g_ptr);
			}
			else
			{
				cout << "Неверная дата!" << endl;
				delete g_ptr;
				g_ptr = nullptr;
			}

			for (int i = 0; i < 3; i++) memset(fields[i], 0, FIELDSIZE); 
			for (int i = 0; i < 3; i++) date[i] = 0;
			if (dig)
			{
				g_ptr = new Note;
				pos = s + (lows - pos) + 5;
				strcpy(fields[0], pos);
				perF = 1;
			}
			else perF = 0;
		}
	}
	if (perF)
	{

		cout << "В объекте отсутствуют: " << endl;
		cout << endl;
		if (fields[0][0]) { cout << "Имя:" << fields[0] << endl; }
		if (fields[1][0]) { cout << "Фамилия:" << fields[1] << endl; }
		if (fields[2][0]) { cout << "Номер:" << fields[2] << endl; }
		if (date[0]) { cout << "День рождения:" << date[0] << endl; }
		if (date[1])
		{
			cout << "Месяц рождения:" << date[1] << endl;
			perF = 5;
		}
		cout << endl;
		cout << "Вы можете ввести: " << endl;
		cout << endl;
		switch (perF)
		{
		case 0:
			cout << "Введите новое имя: " << endl;
			try
			{
				cin >> fields[0];
				if (cin.bad() || cin.fail()) throw buffErr; 
			}
			catch (char*) { exit(1); }
		case 1:
			cout << "Введите новую фамилию: " << endl;
			try
			{
				cin >> fields[1];
				if (cin.bad() || cin.fail()) { throw buffErr; }
			}
			catch (char*) { exit(1); }
		case 2:
			cout << "Введите новый номер: " << endl;
			try
			{
				cin >> fields[2];
				if (cin.bad() || cin.fail()) throw buffErr; 
			}
			catch (char*) { exit(1); }
		case 3:
			cout << "Введите новый день рождения: " << endl;
			try
			{
				cin >> date[0];
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
		case 4:
			cout << "Введите новый месяц рождения: " << endl;
			try
			{
				cin >> date[1];
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
		case 5:
			cout << "Введите новый год рождения: " << endl;
			try
			{
				cin >> date[2];
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
		}
		perF = 0;
		if (!(date[0] < 1 || date[0]>31 || date[1] < 1 || date[1]>12 || date[2] < 0))
		{
			g_ptr->set(fields[0], fields[1], fields[2], date[0], date[1], date[2]);
			this->addToEnd(g_ptr);
		}
		else
		{
			cout << "Введена неверная дата!" << endl;
			delete g_ptr;
			g_ptr = nullptr;
		}
		for (int i = 0; i < 3; i++) memset(fields[i], 0, FIELDSIZE);
		for (int i = 0; i < 3; i++) date[i] = 0;
	}
	file.close();
	delete[] s;
	delete[] lows;
	for (int i = 0; i < 3; i++)
		delete[] fields[i];
	delete[] fields;
}
