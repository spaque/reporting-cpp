#include <eventprinter.h>

#include <iostream>

namespace reporting {

void EventPrinter::onEvent(const Event& event)
{
	std::cout << "Received questionable activity: " 
			  << "["
			  << "device: " << event.device() << ", "
			  << "url: " << event.url() << ", "
			  << "timestamp: " << event.timestamp()
			  << "]"
			  << std::endl;
}

}
