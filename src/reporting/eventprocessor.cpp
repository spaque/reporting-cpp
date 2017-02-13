#include <eventprocessor.h>

#include <iostream>

namespace reporting {

void EventProcessor::start()
{
	Event evt;
	while (d_eventSource_sp->readEvent(evt)) {
		std::cout << "Read event " << evt.device() << std::endl;
		if (!d_eventFilter_sp->filter(evt)) {
			bool success = d_eventTarget_sp->write(evt);
			std::cout << "Event written " << success << std::endl;
			d_eventSource_sp->ack(success);
			if (!success) {
				break;
			}
		}
		else {
			std::cout << "Event filtered" << std::endl;
		}
	}
}

}
