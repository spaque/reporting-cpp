#include <eventquestionablefilter.h>

#include <regex>
#include <string>

namespace reporting {

bool EventQuestionableFilter::filter(const Event& event)
{
	// TODO get words from a config file
	std::regex re(R"(^(?:\w+://)?[^/]*(?:porn|xxx|sex|bieber).*(?:/.*)?$)", std::regex::icase);

	return !std::regex_match(event.url(), re);
}

}
