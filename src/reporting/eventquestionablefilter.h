#pragma once
#include <ieventfilter.h>

namespace reporting {
	class EventQuestionableFilter :	public IEventFilter
	{
	public:
		EventQuestionableFilter() = default;
		virtual ~EventQuestionableFilter() = default;

		bool filter(const Event&) override;
	};

}
