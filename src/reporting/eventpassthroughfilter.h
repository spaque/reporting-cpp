#pragma once

#include <ieventfilter.h>

namespace reporting {

	class EventPassThroughFilter : public IEventFilter
	{
	public:
		EventPassThroughFilter() = default;
		virtual ~EventPassThroughFilter() = default;

		bool filter(const Event&) override { return false; }
	};

}
