#pragma once
#include <ieventobserver.h>

#include <fstream>

namespace reporting {

	class EventFileDump : public IEventObserver
	{
	public:
		EventFileDump();
		virtual ~EventFileDump();

		virtual void onEvent(const Event&) override;

	private:
		std::fstream d_fs;
	};

}
