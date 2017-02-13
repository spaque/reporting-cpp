#pragma once

namespace reporting {

	class EventResponse
	{
	public:

		EventResponse() = default;
		explicit EventResponse(bool success, size_t numEvents)
			: d_success(success), d_numEvents(numEvents) {}

		bool success() const { return d_success; }
		void success(bool success) { d_success = success; }

		size_t numEvents() const { return d_numEvents; }
		void numEvents(size_t numEvents) { d_numEvents = numEvents; }

	private:
		bool d_success;
		size_t d_numEvents;
	};

}
