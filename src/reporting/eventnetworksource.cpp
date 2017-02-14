#include <eventnetworksource.h>

#include <iostream>

namespace reporting {

namespace {

const char SEPARATOR[] = "\x15";

}

EventNetworkSource::~EventNetworkSource()
{
	d_socket_sp->close();
}

bool EventNetworkSource::readEvent(Event& event)
{
    char data[2048];
    boost::system::error_code error;
    size_t length = d_socket_sp->read_some(boost::asio::buffer(data), error);
    if (error == boost::asio::error::eof) {
        std::cerr << "Client disconnected" << std::endl;
        return false;
    }
    if (error) {
        std::cerr << "Error reading from socket: " << error.message() << std::endl;
        return false;
    }
    data[length] = '\0';

	return parseEvent(data, event);
}

void EventNetworkSource::ack(bool success)
{
    std::ostringstream stream;
    stream << success << SEPARATOR << d_target_sp->getNumWrittenEvents();

    boost::system::error_code error;
    d_socket_sp->write_some(boost::asio::buffer(stream.str()), error);
    if (error) {
        std::cerr << "Error sending ack: " << error.message() << std::endl;
    }
}

bool EventNetworkSource::parseEvent(char* data, Event& event)
{
    std::vector<std::string> tokens;

    char* token = strtok(data, SEPARATOR);
    while (token) {
        tokens.push_back(token);
        token = strtok(NULL, SEPARATOR);
    }

    if (tokens.size() != 3) {
        std::cerr << "Failed to parse data" << std::endl;
        return false;
    }

    try {
        event.timestamp(std::stoi(tokens[2]));
        event.device(tokens[0]);
        event.url(tokens[1]);
    }
    catch (const std::exception& ex) {
        std::cerr << "Failed to parse data. " << ex.what() << std::endl;
        return false;
    }

    return true;
}

}
