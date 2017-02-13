#include <eventstoreprocessor.h>

#include <chrono>
#include <thread>

namespace reporting {

void EventStoreProcessor::start()
{
	while (!d_shutdown) {
		processEvents();
		std::this_thread::sleep_for(std::chrono::seconds(d_delay));
	}
}

void EventStoreProcessor::processEvents()
{
	const std::vector<Event> events = d_store_sp->removeAllEvents();
	for (const auto& event : events) {
		d_subject_sp->notify(event);
	}
}

}

