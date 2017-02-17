#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventSource
	{
	public:
        IEventSource() {}
        virtual ~IEventSource() {}

		virtual bool readEvent(Event&) = 0;
		virtual bool ack(bool) = 0;
        virtual bool isValid() const = 0;
	};

	typedef std::shared_ptr<IEventSource> IEventSourcePtr;
}
