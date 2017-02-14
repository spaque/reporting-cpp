
#include <eventfilesource.h>
#include <eventnetworktarget.h>
#include <eventquestionablefilter.h>
#include <eventprocessor.h>

#include <iostream>

using namespace boost::asio;
using namespace reporting;

int main()
{
	IEventSourcePtr source = std::make_shared<EventFileSource>("sample.log");
	IEventFilterPtr filter = std::make_shared<EventQuestionableFilter>();

    io_service service;
    ip::tcp::resolver resolver(service);
    auto socket = std::make_shared<ip::tcp::socket>(service);

    boost::system::error_code error;
    connect(*socket, resolver.resolve({ "localhost", "42422" }), error);
    if (error) {
        std::cerr << "Error connecting to server: " << error.message() << std::endl;
        return 1;
    }

	IEventTargetPtr target = std::make_shared<EventNetworkTarget>(socket);

	EventProcessor proc(source, target, filter);
	proc.start();

    return 0;
}
