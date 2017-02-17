#include <eventprocessor.h>

namespace reporting {

void EventProcessor::start()
{
	Event evt;
	while (d_eventSource_sp->readEvent(evt)) {
		if (!d_eventFilter_sp->filter(evt)) {
			bool success = d_eventTarget_sp->writeEvent(evt);
			success = d_eventSource_sp->ack(success) && success;
			if (!success) {
				break;
			}
		}
	}
}

}
