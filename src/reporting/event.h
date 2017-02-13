#pragma once

#include <string>

namespace reporting {

	class Event
	{
	public:
		Event() = default;
		explicit Event(
			const std::string& device,
			const std::string& url,
			unsigned timestamp)
			: d_device(device), d_url(url), d_timestamp(timestamp) {}

		const std::string& device() const { return d_device; }
		void device(const std::string& device) { d_device = device; }
		void device(std::string&& device) { d_device = std::move(device); }

		const std::string& url() const { return d_url; }
		void url(const std::string& url) { d_url = url; }
		void url(std::string&& url) { d_url = std::move(url); }

		unsigned timestamp() const { return d_timestamp; }
		void timestamp(unsigned timestamp) { d_timestamp = timestamp; }

        bool operator==(const Event& rhs) const
        {
            return d_device == rhs.d_device &&
                d_url == rhs.d_url &&
                d_timestamp == rhs.d_timestamp;
        }

	private:
		std::string d_device;
		std::string d_url;
		unsigned	d_timestamp;
	};

}
