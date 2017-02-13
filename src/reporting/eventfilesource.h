#pragma once
#include <ieventsource.h>

#include <fstream>
#include <string>

namespace reporting {

	class EventFileSource : public IEventSource
	{
	public:
		explicit EventFileSource(const std::string& filename);
		virtual ~EventFileSource();

		bool readEvent(Event& event) override;
		void ack(bool success) override;

	private:
		bool parseLine(const std::string& pattern, std::string& value);

		std::fstream d_fs;
	};

}
