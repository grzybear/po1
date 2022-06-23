#pragma once
#include <iostream>
#include <list>
#include <string>
#define MAX_CAPACITY 16
class EventList
{
private:
	std::list<std::string> list;
	void Print(std::ostream& out) const;
protected:
	friend std::ostream& operator<<(std::ostream& os, const EventList& list);
public:
	EventList();
	~EventList();
	void Add(std::string s);
};

