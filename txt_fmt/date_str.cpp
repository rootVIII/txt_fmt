#include "date_str.h"
#include <ctime>
#include <chrono>
#include <stdexcept>
#include <string>


std::string get_date_str()
{
    const auto time_point = std::chrono::system_clock::now();
    const auto sys_time = std::chrono::system_clock::to_time_t(time_point);
    char tm_buff[30];
    if (ctime_s(tm_buff, sizeof(tm_buff), &sys_time) != 0)
        throw std::runtime_error("system error occurred while retrieving local time");
    std::string datestamp;
    const auto stamp = std::string(tm_buff);
    for (auto &letter : stamp)
    {
        if (letter == 0x20)
            datestamp += '_';
        else if (letter != 0x0A && letter != 0x3A)
            datestamp += letter;
    }
    return datestamp;
}
