#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventTarget
	{
	public:
        IEventTarget() {}
        virtual ~IEventTarget() {}

		virtual bool writeEvent(const Event& event) = 0;

		virtual size_t getNumWrittenEvents() = 0;
	};

	typedef std::shared_ptr<IEventTarget> IEventTargetPtr;

}
