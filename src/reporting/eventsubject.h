#pragma once

#include <ieventsubject.h>
#include <ieventobserver.h>

#include <vector>

namespace reporting {

	class EventSubject : public IEventSubject
	{
	public:
		EventSubject() = default;
		virtual ~EventSubject() = default;

		void registerObserver(const IEventObserverPtr&) override;
		void notify(const Event&) override;

	private:
		std::vector<IEventObserverPtr> d_observers;
	};

}

