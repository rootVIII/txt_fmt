#include "date_str.h"
#include <ctime>
#include <stdexcept>
#include <string>


std::string get_date_str()
{
    std::tm time_info {};
    const auto timer = std::time(nullptr);
    const errno_t error = localtime_s(&time_info, &timer);
    if (error)
        throw std::runtime_error("system error occurred while retrieving local time");

    char buffer[32];
    if (!(std::strftime(buffer, 32, "%d-%m-%Y_%H%M%S", &time_info)))
        throw std::runtime_error("system error occurred while setting local time buffer");

    return buffer;
}
