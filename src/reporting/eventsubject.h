#pragma once

#include <ieventobserver.h>

#include <memory>
#include <vector>

namespace reporting {

	class EventSubject
	{
	public:
		EventSubject() = default;
		virtual ~EventSubject() = default;

		void registerObserver(const IEventObserverPtr&);
		void notify(const Event&);

	private:
		std::vector<IEventObserverPtr> d_observers;
	};

	typedef std::shared_ptr<EventSubject> EventSubjectPtr;

}
