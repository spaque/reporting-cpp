#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventTarget
	{
	public:
		IEventTarget() = default;
		virtual ~IEventTarget() = default;

		virtual bool write(const Event&) = 0;

		virtual size_t getNumWrittenEvents() = 0;
	};

	typedef std::shared_ptr<IEventTarget> IEventTargetPtr;

}
