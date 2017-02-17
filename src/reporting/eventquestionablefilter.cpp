#include <eventquestionablefilter.h>

#include <algorithm>
#include <regex>
#include <string>
#include <sstream>

namespace reporting {

EventQuestionableFilter::EventQuestionableFilter(const std::vector<std::string>& words)
{
    if (!words.empty()) {
        std::ostringstream stream;
        stream << "^(\?:\\w+://)\?[^/]*(\?:";
        if (words.size() > 1) {
            std::copy(words.begin(), words.end() - 1, std::ostream_iterator<std::string>(stream, "|"));
        }
        stream << words.back() << ").*(\?:/.*)\?$";

        d_pattern = stream.str();
    }
}

bool EventQuestionableFilter::filter(const Event& event)
{
    if (d_pattern.empty()) {
        return false;
    }

	std::regex re(d_pattern, std::regex::icase);

	return !std::regex_match(event.url(), re);
}

}
