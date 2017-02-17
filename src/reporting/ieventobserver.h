#pragma once

#include <event.h>

#include <memory>

namespace reporting {

	class IEventObserver
	{
	public:
        IEventObserver() {}
        virtual ~IEventObserver() {}

		virtual void onEvent(const Event& event) = 0;
	};

	typedef std::shared_ptr<IEventObserver> IEventObserverPtr;

}
