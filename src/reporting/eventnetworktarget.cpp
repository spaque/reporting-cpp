#include <eventnetworktarget.h>

#include <iostream>

namespace reporting {

namespace {

const char SEPARATOR[] = "\x15";

}

EventNetworkTarget::~EventNetworkTarget()
{
	d_socket_sp->close();
}

bool EventNetworkTarget::writeEvent(const Event& event)
{
    std::ostringstream stream;
    stream << event.device() << SEPARATOR << event.url() << SEPARATOR << event.timestamp();

    boost::system::error_code error;
    d_socket_sp->write_some(boost::asio::buffer(stream.str()), error);
    if (error) {
        std::cerr << "Error writing to socket: " << error.message() << std::endl;
        return false;
    }

    char ack[64];
    size_t length = d_socket_sp->read_some(boost::asio::buffer(ack), error);
    if (error == boost::asio::error::eof) {
        std::cerr << "Server disconnected" << std::endl;
        return false;
    }
    if (error) {
        std::cerr << "Error reading from socket: " << error.message() << std::endl;
        return false;
    }
    ack[length] = '\0';

    bool success = false;
    size_t numEvents = 0;
    parseAck(ack, success, numEvents);

	d_numWrittenEvents++;

	return success;
}

size_t EventNetworkTarget::getNumWrittenEvents()
{
	return d_numWrittenEvents;
}

bool EventNetworkTarget::parseAck(char* data, bool& success, size_t& numEvents)
{
    std::vector<std::string> tokens;

    char* token = strtok(data, SEPARATOR);
    while (token) {
        tokens.push_back(token);
        token = strtok(NULL, SEPARATOR);
    }

    if (tokens.size() != 2) {
        std::cerr << "Failed to parse data" << std::endl;
        return false;
    }

    try {
        numEvents = std::stoi(tokens[1]);
        success = std::stoi(tokens[0]);
    }
    catch (const std::exception& ex) {
        std::cerr << "Failed to parse data. " << ex.what() << std::endl;
        return false;
    }

    return true;
}

}
