#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventObserver
	{
	public:
		IEventObserver() = default;
		virtual ~IEventObserver() = default;

		virtual void onEvent(const Event&) = 0;
	};

	typedef std::shared_ptr<IEventObserver> IEventObserverPtr;

}
