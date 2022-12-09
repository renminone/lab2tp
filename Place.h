#pragma once
#include "Note.h"

class place
{
public:
	place* prev;
	place* next;
	Note* ntp;
	place(Note* veh);
	place(void);
	place(const place& toCopy);
	~place();
};
