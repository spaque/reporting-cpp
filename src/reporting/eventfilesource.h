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
        bool ack(bool success) override { return true; }
        bool isValid() const override { return d_fs.good(); }

	private:
		bool parseLine(const std::string& pattern, std::string& value);

		std::ifstream d_fs;
	};

}
