#pragma once

#include <ieventfilter.h>

namespace reporting {

	class EventPassThroughFilter : public IEventFilter
	{
	public:
        EventPassThroughFilter() {}
        virtual ~EventPassThroughFilter() {}

		bool filter(const Event&) override { return false; }
	};

}
