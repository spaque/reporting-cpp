#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventSource
	{
	public:
		IEventSource() = default;
		virtual ~IEventSource() = default;

		virtual bool readEvent(Event&) = 0;
		virtual void ack(bool) = 0;
	};

	typedef std::shared_ptr<IEventSource> IEventSourcePtr;
}
