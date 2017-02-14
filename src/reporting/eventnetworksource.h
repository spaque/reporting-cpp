#pragma once
#include <ieventsource.h>
#include <ieventtarget.h>

#include <boost/asio.hpp>

namespace reporting {

	typedef std::shared_ptr<boost::asio::ip::tcp::socket> TcpSocketPtr;

	class EventNetworkSource : public IEventSource
	{
	public:
		explicit EventNetworkSource(const TcpSocketPtr& socket, const IEventTargetPtr& target)
			: d_socket_sp(socket), d_target_sp(target) {}
		virtual ~EventNetworkSource();

		bool readEvent(Event&) override;
		void ack(bool) override;

	private:
        bool parseEvent(char* data, Event& event);

        TcpSocketPtr d_socket_sp;
		IEventTargetPtr d_target_sp;
	};

}
