#pragma once
#include <ieventfilter.h>

#include <vector>

namespace reporting {
	class EventQuestionableFilter :	public IEventFilter
	{
	public:
        EventQuestionableFilter(const std::vector<std::string>& words);
        virtual ~EventQuestionableFilter() {}

		bool filter(const Event& event) override;

    private:
        std::string d_pattern;
	};

}
