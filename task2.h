#include<iostream>
#include <fstream>
#include <string>

using namespace std;

string replacer(string s)
{
	size_t pos;
	while ((pos = s.find(" a")) != std::string::npos) s.replace(pos+1, 1, 1, 'A');
	while ((pos = s.find(" e")) != std::string::npos) s.replace(pos+1, 1, 1, 'E');
	while ((pos = s.find(" i")) != std::string::npos) s.replace(pos+1, 1, 1, 'I');
	while ((pos = s.find(" o")) != std::string::npos) s.replace(pos+1, 1, 1, 'O');
	while ((pos = s.find(" u")) != std::string::npos) s.replace(pos+1, 1, 1, 'U');
	while ((pos = s.find(" y")) != std::string::npos) s.replace(pos+1, 1, 1, 'Y');
	return s;
}

void task2()
{
	string s;
	string file;
	cin >> file;
	ifstream f;
	f.open(file);
	while (getline(f, s, '\n'))
	{ // пока не достигнут конец файла класть очередную строку в переменную (s)
		s = replacer(s);
		cout << s << endl; // выводим на экран
	}

	f.close();
}
