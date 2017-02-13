#pragma once

#include <ieventstore.h>
#include <eventsubject.h>

#include <atomic>

namespace reporting {

	class EventStoreProcessor
	{
	public:
		explicit EventStoreProcessor(const IEventStorePtr& store, const EventSubjectPtr& subject)
			: d_store_sp(store), d_subject_sp(subject), d_shutdown(false) {}
		~EventStoreProcessor() = default;

		void start();
		void shutdown() { d_shutdown = false; }

	private:
		void processEvents();

		IEventStorePtr	d_store_sp;
		EventSubjectPtr d_subject_sp;

		std::atomic_bool d_shutdown;
	};

}
