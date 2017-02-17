#pragma once

#include <ieventtarget.h>
#include <event.h>

#include <memory>
#include <vector>

namespace reporting {

	class IEventStore : public IEventTarget
	{
	public:
        IEventStore() {}
        virtual ~IEventStore() {}

		virtual bool writeEvent(const Event&) = 0;

		virtual std::vector<Event> removeAllEvents() = 0;

		virtual size_t getNumWrittenEvents() = 0;
	};

	typedef std::shared_ptr<IEventStore> IEventStorePtr;
}
