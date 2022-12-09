#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include "Note.h"
#include "Keeper.h"
#define FIELDSIZE 20
#define BUFLEN 5000

void task1()
{
	char* searchS;
	int searchDate = 0;
	char* filename;
	try
	{
		searchS = new char[FIELDSIZE];
		filename = new char[50];
	}
	catch (bad_alloc)
	{
		cout << "Ошибка оператора new." << endl;
		exit(-1);
	}
	Note* g_ptr = nullptr;
	keeper cont1;
	int mode = 0;
	int charMode = 0;
	int sortMode = 0;
	int num = 0;
	int copied = 0;
	int toCopy = 0;
	char buffErr[] = "Ошибка буфера ввода.";
	do
	{
		cout << endl;
		cout << "Введите задание:" << endl;
		cout << "1 - ввод." << endl;
		cout << "2 - сортировка данных" << endl;
		cout << "3 - скопировать данные." << endl;
		cout << "4 - редактировать дааные." << endl;
		cout << "5 - удалить данные." << endl;
		cout << "6 - очистка." << endl;
		cout << "7 - вывод всего." << endl;
		cout << "8 - поиск записей по месяцу рождения" << endl;
		cout << "9 - load data to a file" << endl;
		cout << "10 - load data from a file." << endl;
		try
		{
			cin >> mode;
			if (cin.bad() || cin.fail()) { throw buffErr; }
		}
		catch (char*) { exit(1); }
		cout << endl;
		if (mode < 0 || mode > 11) { cout << "Неверный код! Попробуйте снова!" << endl; continue; }
		switch (mode)
		{
		case 1: cin >> cont1; break;
		case 2: cout << "Ввести режим сортировки:\n0 - в порядке возрастания.\n1 - в порядке убывания." << endl;
			try
			{
				cin >> sortMode;
				if (cin.bad() || cin.fail()) { throw buffErr; }
			}
			catch (char*) { exit(1); }
			try { cont1.sort(sortMode); }
			catch (int) { cout << "Пусто!" << endl; }
			break;
		case 3:
			cout << "Введите позицию копирования: " << endl;
			try
			{
				cin >> copied;
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
			cout << "Введите позицию вставки: " << endl;
			try
			{
				cin >> toCopy;
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
			try { cont1.copy(copied, toCopy); }
			catch (int) { cout << "Не найдено!" << endl; }
			break;
		case 4:
			cout << "Введите номер элемента." << endl;
			try
			{
				cin >> num;
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
			cout << endl;
			try { cont1.changeEl(num); }
			catch (int) { cout << "Пусто!" << endl; }
			catch (double) { cout << "Не найдено!" << endl; }
			break;
		case 5:
			cout << "Введите номер элемента." << endl;
			try
			{
				cin >> num;
				if (cin.bad() || cin.fail()) throw buffErr; 
			}
			catch (char*) { exit(1); }
			cout << endl;
			try { cont1.del(num); }
			catch (int) { cout << "Пусто!" << endl;}
			catch (double) { cout << "Не найдено!" << endl; }
			break;
		case 6:
			cont1.clear();
			cout << "Пусто!" << endl;
			break;
		case 7:
			try { cout << cont1; }
			catch (int) { cout << "Пусто!" << endl; }
			break;
		case 8:
			cout << "Введите месяц: " << endl;
			try
			{
				cin >> searchDate;
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
			try { cont1.search(searchDate, 1); }
			catch (int) { cout << "Пусто!" << endl; }
			break;
		case 9:
			cout << "Ввести путь файла:" << endl;
			try
			{
				cin >> filename;
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
			try { cont1.loadToFile(filename); }
			catch (int) { cout << "Пусто!" << endl; }
			break;
		case 10:
			cout << "Ввести путь файла:" << endl;
			try
			{
				cin >> filename;
				if (cin.bad() || cin.fail()) throw buffErr;
			}
			catch (char*) { exit(1); }
			cont1.loadFromFile(filename);
			break;
		}
	}
	while (mode != 0);

	delete[] searchS;
	delete[] filename;
}
