#pragma once

#include <ieventtarget.h>
#include <event.h>

#include <memory>
#include <vector>

namespace reporting {

	class IEventStore : public IEventTarget
	{
	public:
		IEventStore() = default;
		virtual ~IEventStore() = default;

		virtual bool write(const Event&) = 0;

		virtual std::vector<Event> getAllEvents() = 0;

		virtual size_t getNumWrittenEvents() = 0;
	};

	typedef std::shared_ptr<IEventStore> IEventStorePtr;
}
