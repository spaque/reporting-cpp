
#include <eventfilesource.h>
#include <eventnetworktarget.h>
#include <eventquestionablefilter.h>
#include <eventprocessor.h>

#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>

using namespace boost::asio;
using namespace reporting;

int main(int argc, char *argv[])
{
    std::string configfile("config.json");
    if (argc > 1) {
        configfile = argv[1];
    }

    boost::property_tree::ptree pt;
    try {
        boost::property_tree::json_parser::read_json(configfile, pt);
    }
    catch (const std::exception& ex) {
        std::cerr << "Error parsing config file: " << ex.what() << std::endl;
        return 1;
    }
    
    const std::string inputfile(
        pt.get<std::string>("client.input_filename", "sample.log"));
	IEventSourcePtr source = std::make_shared<EventFileSource>(inputfile);

    if (!source->isValid()) {
        std::cerr << "Invalid source " << inputfile << std::endl;
        return 2;
    }

    std::vector<std::string> words;
    const auto child = pt.get_child_optional("questionable_words");
    if (child) {
        for (const auto& item : child.get()) {
            const std::string word(item.second.get_value<std::string>());
            if (!word.empty()) {
                words.push_back(word);
            }
        }
    }
    else {
        words = { "porn", "xxx", "sex", "bieber" };
    }
    IEventFilterPtr filter = std::make_shared<EventQuestionableFilter>(words);

    io_service service;
    auto socket = std::make_shared<ip::tcp::socket>(service);

    boost::system::error_code error;
    ip::tcp::endpoint endpoint(
        ip::address::from_string(pt.get<std::string>("network.server_ip", "127.0.0.1")),
        pt.get<int>("network.port", 42422));
    socket->connect(endpoint, error);
    if (error) {
        std::cerr << "Error connecting to server: " << error.message() << std::endl;
        return 3;
    }

	IEventTargetPtr target = std::make_shared<EventNetworkTarget>(socket);

    std::cout << "Connected to server" << std::endl;

	EventProcessor proc(source, target, filter);
	proc.start();

    return 0;
}

