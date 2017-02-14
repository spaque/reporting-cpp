#include <eventinmemorystore.h>

namespace reporting {

bool EventInMemoryStore::writeEvent(const Event &event)
{
	std::lock_guard<std::mutex> lock(d_mutex);

	d_store.push_back(event);

	d_numWrittenEvents++;

	return true;
}

std::vector<Event> EventInMemoryStore::removeAllEvents()
{
	std::lock_guard<std::mutex> lock(d_mutex);

	std::vector<Event> events;
	events.swap(d_store);

	return events;
}

size_t EventInMemoryStore::getNumWrittenEvents()
{
	std::lock_guard<std::mutex> lock(d_mutex);

	return d_numWrittenEvents;
}

}
