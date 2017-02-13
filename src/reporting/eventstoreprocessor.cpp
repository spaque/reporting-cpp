#include <eventstoreprocessor.h>

#include <chrono>
#include <thread>

namespace reporting {

void EventStoreProcessor::start()
{
	while (!d_shutdown) {
		std::this_thread::sleep_for(std::chrono::seconds(5));
		processEvents();
	}
}

void EventStoreProcessor::processEvents()
{
	const std::vector<Event> events = d_store_sp->getAllEvents();
	for (const auto& event : events) {
		d_subject_sp->notify(event);
	}
}

}
