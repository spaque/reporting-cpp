#pragma once

#include <ieventstore.h>
#include <ieventsubject.h>

#include <atomic>

namespace reporting {

	class EventStoreProcessor
	{
	public:
		explicit EventStoreProcessor(
                const IEventStorePtr& store,
                const IEventSubjectPtr& subject,
                int delay = 5)
			: d_store_sp(store), d_subject_sp(subject), d_delay(delay), d_shutdown(false) {}
		~EventStoreProcessor() = default;

		void start();
		void shutdown() { d_shutdown = false; }

	private:
		void processEvents();

		IEventStorePtr	d_store_sp;
		IEventSubjectPtr d_subject_sp;

        int d_delay;

		std::atomic_bool d_shutdown;
	};

}

