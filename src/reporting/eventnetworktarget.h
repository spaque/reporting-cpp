#pragma once
#include <ieventtarget.h>

#include <boost/asio.hpp>

namespace reporting {

	typedef std::shared_ptr<boost::asio::ip::tcp::socket> TcpSocketPtr;

	class EventNetworkTarget : public IEventTarget
	{
	public:
		EventNetworkTarget(const TcpSocketPtr& socket) : d_socket_sp(socket) {}
		virtual ~EventNetworkTarget();

		bool writeEvent(const Event&) override;
		size_t getNumWrittenEvents() override;

	private:
        bool parseAck(char* data, bool& success, size_t& numEvents);

        TcpSocketPtr	d_socket_sp;
		size_t			d_numWrittenEvents;
	};

}
