#pragma once
#include "Place.h"
#include "Note.h"

class keeper
{
private:
	place* head;
	place* tail;
	int amount;
protected:
	place* operator[](int i);
public:
	void add(Note* toInsert);
	void addToEnd(Note* toInsert);
	void insert(int pos, Note* toInsert);
	void copy(int sou, int dest);
	void del(int num);
	void changeEl(int num);
	void show(void);
	void search(int perVal, int perNum);
	void clear(void);
	void sort(int mode = 0);
	keeper();
	keeper(Note* ob);
	keeper(const keeper& ob);
	~keeper();
	void loadToFile(char* name);
	void loadFromFile(char* name);
	friend ostream& operator<<(ostream& stream, const keeper& cont);
	friend istream& operator>>(istream& stream, keeper& cont);

};
