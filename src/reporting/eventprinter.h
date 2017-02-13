#pragma once
#include <ieventobserver.h>

namespace reporting {

	class EventPrinter : public IEventObserver
	{
	public:
		EventPrinter() = default;
		virtual ~EventPrinter() = default;

		virtual void onEvent(const Event&) override;
	};

}
