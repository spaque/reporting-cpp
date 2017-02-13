#include <eventnetworktarget.h>

#include <iostream>
#include <thread>
namespace reporting {

EventNetworkTarget::~EventNetworkTarget()
{
	d_stream_sp->close();
}

bool EventNetworkTarget::write(const Event& event)
{
	d_numWrittenEvents++;

	return success;
}

size_t EventNetworkTarget::getNumWrittenEvents()
{
	return d_numWrittenEvents;
}

}
