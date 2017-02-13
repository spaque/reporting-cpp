#include <eventsubject.h>

namespace reporting {

void EventSubject::registerObserver(const IEventObserverPtr& observer)
{
	if (observer) {
		d_observers.push_back(observer);
	}
}

void EventSubject::notify(const Event& event)
{
	for (const auto& observer : d_observers) {
		observer->onEvent(event);
	}
}

}
