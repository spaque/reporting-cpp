#pragma once

#include <ieventfilter.h>
#include <ieventsource.h>
#include <ieventtarget.h>

namespace reporting {

	class EventProcessor
	{
	public:
		explicit EventProcessor(
			const IEventSourcePtr& source, 
			const IEventTargetPtr& target,
			const IEventFilterPtr& filter)
			: d_eventSource_sp(source)
			, d_eventTarget_sp(target)
			, d_eventFilter_sp(filter) {}
        ~EventProcessor() {}

		void start();

	private:
		IEventSourcePtr d_eventSource_sp;
		IEventTargetPtr d_eventTarget_sp;
		IEventFilterPtr d_eventFilter_sp;
	};

}
