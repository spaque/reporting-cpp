#include <eventfilesource.h>

#include <iostream>
#include <regex>

namespace reporting {

EventFileSource::EventFileSource(const std::string& filename)
{
	try {
		d_fs.open(filename, std::fstream::in);
	}
	catch (const std::exception& ex) {
		std::cerr << "Failed to open file. " << ex.what() << std::endl;
	}
}

EventFileSource::~EventFileSource()
{
	if (d_fs.is_open()) {
		d_fs.close();
	}
}

bool EventFileSource::readEvent(Event& event)
{
	try {
		std::string device;
		if (!parseLine(R"(^device:\s*(.+)$)", device)) {
			if (d_fs.fail()) {
				std::cerr << "Could not read event device" << std::endl;
			}
			return false;
		}

		std::string url;
		if (!parseLine(R"(^url:\s*(.+)$)", url)) {
			if (d_fs.fail()) {
				std::cerr << "Could not read event url" << std::endl;
			}
			return false;
		}

		std::string timestamp;
		if (!parseLine(R"(^timestamp:\s*(\d+)$)", timestamp)) {
			if (d_fs.fail()) {
				std::cerr << "Could not read event timestamp" << std::endl;
			}
			return false;
		}

		event.device(device);
		event.url(url);
		event.timestamp(std::atoi(timestamp.c_str()));
		return true;
	}
	catch (const std::exception& ex) {
		std::cerr << "Failed to read from file. " << ex.what() << std::endl;
	}

	return false;
}

void EventFileSource::ack(bool)
{
}

bool EventFileSource::parseLine(const std::string & pattern, std::string& value)
{
	std::string line;
	std::regex regex(pattern, std::regex::icase);
	std::smatch matches;
	if (std::getline(d_fs, line) &&
		std::regex_match(line, matches, regex) &&
		matches.size() == 2) {
		value = matches[1].str();
		return true;
	}

	return false;
}

}
