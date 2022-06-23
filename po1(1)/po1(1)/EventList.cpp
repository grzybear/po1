#include "EventList.h"

void EventList::Print(std::ostream& out) const {
	for (auto s : list) {
		out << s << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const EventList& list) {
	list.Print(os);
	return os;
}
EventList::EventList() {};
EventList::~EventList() {};
void EventList::Add(std::string s) {
	list.push_back(s);
	if (list.size() > MAX_CAPACITY)list.pop_front();
}