#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventFilter
	{
	public:
		IEventFilter() = default;
		virtual ~IEventFilter() = default;

		virtual bool filter(const Event&) = 0;
	};

	typedef std::shared_ptr<IEventFilter> IEventFilterPtr;

}
