#pragma once

#include <eventresponse.h>

#include <memory>

namespace reporting {

	class IEventAck
	{
	public:
		IEventAck() = default;
		virtual ~IEventAck() = default;

		virtual void ackEvent(const EventResponse&) = 0;
	};

	typedef std::shared_ptr<IEventAck> IEventAckPtr;

}
