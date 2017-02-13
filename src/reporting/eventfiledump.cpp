#include <eventfiledump.h>

#include <iostream>

namespace reporting {

EventFileDump::EventFileDump()
{
	try {
		d_fs.open("output.txt", std::fstream::out);
	}
	catch (const std::exception& ex) {
		std::cerr << "Failed to open file. " << ex.what() << std::endl;
	}
}

EventFileDump::~EventFileDump()
{
	if (d_fs.is_open()) {
		d_fs.close();
	}
}

void EventFileDump::onEvent(const Event& event)
{
	if (d_fs) {
		d_fs << "device: " << event.device() << "\n"
			 << "url: " << event.url() << "\n"
			 << "timestamp: " << event.timestamp() << std::endl;
	}
}

}
