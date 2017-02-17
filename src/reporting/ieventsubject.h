#pragma once

#include <ieventobserver.h>

#include <memory>

namespace reporting {

	class IEventSubject
	{
	public:
        IEventSubject() {}
        virtual ~IEventSubject() {}

		virtual void registerObserver(const IEventObserverPtr& observer) = 0;

		virtual void notify(const Event& event) = 0;
	};

	typedef std::shared_ptr<IEventSubject> IEventSubjectPtr;

}

