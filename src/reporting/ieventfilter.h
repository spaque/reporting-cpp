#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventFilter
	{
	public:
        IEventFilter() {}
        virtual ~IEventFilter() {}

		virtual bool filter(const Event& event) = 0;
	};

	typedef std::shared_ptr<IEventFilter> IEventFilterPtr;

}
