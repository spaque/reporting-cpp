#include <eventfilesource.h>

#include <iostream>
#include <regex>

namespace reporting {

EventFileSource::EventFileSource(const std::string& filename)
{
	d_fs.open(filename, std::ifstream::in);
    if (!d_fs.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
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
		if (!parseLine("^device:\\s*(.+)$", device)) {
			return false;
		}

		std::string url;
		if (!parseLine("^url:\\s*(.+)$", url)) {
			return false;
		}

		std::string timestamp;
		if (!parseLine("^timestamp:\\s*(\\d+)$", timestamp)) {
			return false;
		}

        // Store timestamp first so if there's an exception, the event is not modified
        event.timestamp(std::stoi(timestamp));
		event.device(device);
		event.url(url);

		return true;
	}
	catch (const std::exception& ex) {
		std::cerr << "Failed to read from file. " << ex.what() << std::endl;
	}

	return false;
}

bool EventFileSource::parseLine(const std::string & pattern, std::string& value)
{
	std::string line;
    if (!std::getline(d_fs, line)) {
        // Reached EOF
        return false;
    }

    std::regex regex(pattern, std::regex::icase);
    std::smatch matches;
	if (std::regex_match(line, matches, regex) &&
		matches.size() == 2) {
		value = matches[1].str();
		return true;
    }
    else {
        std::cerr << "Failed to parse line: " << line << std::endl;
        return false;
    }

	return false;
}

}
