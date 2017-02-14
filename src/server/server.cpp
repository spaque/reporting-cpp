
#include <eventnetworksource.h>
#include <eventinmemorystore.h>
#include <eventpassthroughfilter.h>
#include <eventfiledump.h>
#include <eventprinter.h>
#include <eventprocessor.h>
#include <eventstoreprocessor.h>
#include <eventsubject.h>

#include <boost/asio.hpp>

#include <iostream>
#include <memory>
#include <thread>

using namespace boost::asio;
using namespace reporting;

void session(
    const IEventSourcePtr& source,
    const IEventTargetPtr& target,
    const IEventFilterPtr& filter)
{
    try {
        EventProcessor proc(source, target, filter);
        proc.start();
    }
    catch (const std::exception& ex) {
        std::cerr << "Caught exception in session: " << ex.what() << std::endl;
    }
}

int main()
{
    IEventStorePtr store = std::make_shared<EventInMemoryStore>();
	IEventTargetPtr target = store;
	IEventFilterPtr filter = std::make_shared<EventPassThroughFilter>();

    IEventObserverPtr printer = std::make_shared<EventPrinter>();
    IEventObserverPtr dump = std::make_shared<EventFileDump>();
    IEventSubjectPtr subject = std::make_shared<EventSubject>();
    subject->registerObserver(printer);
    subject->registerObserver(dump);

    EventStoreProcessor proc(store, subject);
    std::thread st(&EventStoreProcessor::start, &proc);

    try {
        io_service service;
        ip::tcp::endpoint endpoint(ip::tcp::v4(), 42422);
        ip::tcp::acceptor acceptor(service, endpoint);

        for (;;) {
            std::cout << "Waiting for connection..." << std::endl;
            auto socket = std::make_shared<ip::tcp::socket>(service);
            boost::system::error_code error;
            acceptor.accept(*socket, error);
            if (!error) {
                IEventSourcePtr source = std::make_shared<EventNetworkSource>(socket, target);

                std::thread t(session, std::cref(source), std::cref(target), std::cref(filter));
                t.detach();
            }
            else {
                std::cerr << "Error connecting: " << error.message() << std::endl;
            }
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Caught exception in main: " << ex.what() << std::endl;
    }

    return 0;
}

