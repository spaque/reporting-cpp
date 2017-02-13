#pragma once
#include <ieventtarget.h>

#include <boost/asio.hpp>

namespace reporting {

	typedef std::shared_ptr<boost::asio::ip::tcp::iostream> TcpIostreamPtr;

	class EventNetworkTarget : public IEventTarget
	{
	public:
		EventNetworkTarget(const TcpIostreamPtr& stream) : d_stream_sp(stream) {}
		virtual ~EventNetworkTarget();

		bool write(const Event&) override;
		size_t getNumWrittenEvents() override;

	private:
		TcpIostreamPtr	d_stream_sp;
		size_t			d_numWrittenEvents;
	};

}
