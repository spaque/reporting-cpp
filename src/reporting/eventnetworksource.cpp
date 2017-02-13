#include <eventnetworksource.h>

#include <iostream>

namespace reporting {

EventNetworkSource::~EventNetworkSource()
{
	d_stream_sp->close();
}

bool EventNetworkSource::readEvent(Event& event)
{
	return true;
}

void EventNetworkSource::ack(bool success)
{

}

}
