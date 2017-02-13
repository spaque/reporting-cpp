#pragma once
#include <ieventsource.h>
#include <ieventtarget.h>

#include <boost/asio.hpp>

namespace reporting {

	typedef std::shared_ptr<boost::asio::ip::tcp::iostream> TcpIostreamPtr;

	class EventNetworkSource : public IEventSource
	{
	public:
		explicit EventNetworkSource(const TcpIostreamPtr& stream, const IEventTargetPtr& target)
			: d_stream_sp(stream), d_target_sp(target) {}
		virtual ~EventNetworkSource();

		bool readEvent(Event&) override;
		void ack(bool) override;

	private:
		TcpIostreamPtr d_stream_sp;
		IEventTargetPtr d_target_sp;
	};

}
