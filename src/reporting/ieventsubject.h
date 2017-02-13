#pragma once

#include <ieventobserver.h>

#include <memory>

namespace reporting {

	class IEventSubject
	{
	public:
		IEventSubject() = default;
		virtual ~IEventSubject() = default;

		virtual void registerObserver(const IEventObserverPtr&) = 0;

		virtual void notify(const Event&) = 0;
	};

	typedef std::shared_ptr<IEventSubject> IEventSubjectPtr;

}

