#include <eventfiledump.h>

#include <iostream>

namespace reporting {

EventFileDump::EventFileDump(const std::string& filename)
{
	d_fs.open(filename, std::ofstream::out);
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
