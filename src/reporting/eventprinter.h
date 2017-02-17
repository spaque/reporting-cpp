#pragma once
#include <ieventobserver.h>

namespace reporting {

	class EventPrinter : public IEventObserver
	{
	public:
        EventPrinter() {}
        virtual ~EventPrinter() {}

		virtual void onEvent(const Event& event) override;
	};

}
