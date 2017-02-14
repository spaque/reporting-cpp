#pragma once
#include <ieventstore.h>

#include <mutex>
#include <vector>

namespace reporting {

	class EventInMemoryStore : public IEventStore
	{
	public:
		EventInMemoryStore() : d_numWrittenEvents(0) {};
		virtual ~EventInMemoryStore() = default;

		bool writeEvent(const Event&) override;
		std::vector<Event> removeAllEvents() override;
		size_t getNumWrittenEvents() override;

	private:
		std::mutex			d_mutex;
		std::vector<Event>	d_store;
		size_t				d_numWrittenEvents;
	};
}
