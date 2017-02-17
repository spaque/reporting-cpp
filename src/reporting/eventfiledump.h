#pragma once
#include <ieventobserver.h>

#include <fstream>

namespace reporting {

	class EventFileDump : public IEventObserver
	{
	public:
		EventFileDump(const std::string& filename);
		virtual ~EventFileDump();

		virtual void onEvent(const Event& event) override;

	private:
		std::ofstream d_fs;
	};

}
