#pragma once
#include <conio.h>
#include "Note.h"
#include "vector.h"
#include "vector.cpp"

vector<Note> notepad;

void task1()
{
	vector<Note> notepad;
	Note cd;
	int l = 1;
	int i;
	int d;
	cout << "Меню задания: " << endl;
	cout << "1 - вставка объекта." << endl;
	cout << "2 - извлечение объекта." << endl;
	cout << "3 - удаление объекта." << endl;
	cout << "4 - вывод экран информации о людях, чьи дни рождения приходятся на определённый месяц." << endl;
	cout << "5 - вывод все данный в алфавитном порядке." << endl;
	cout << "0 - выход." << endl << endl;
	while (l != 0)
	{
		switch (_getch())
		{
		case '1':
			cd.set();
			notepad.pushBack(cd);
			cd.get();
			break;
		case '2':
			cout << "Введите номер элемента: ";
			cin >> i;
			notepad.element(i);
			break;
		case '3':
			cout << "Введите номер элемента: ";
			cin >> i;
			notepad.remove(i);
			break;
		case '4':
			break;
		case '5':
			notepad.show_vector(notepad);
			break;
		case '0': l = 0; break;
		}
	}
}
