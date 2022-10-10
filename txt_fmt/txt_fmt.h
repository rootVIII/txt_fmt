#pragma once

#ifndef TXT_FMT_H
#define TXT_FMT_H
#include <string>

class TxtFmt
{

public:
    explicit TxtFmt(std::string path, unsigned long long max_line);
    std::string read_file_in() const;
    void process_text(const std::string &file_data) const;
    // unsigned long long max_line;

private:
    std::string path_;
    unsigned long long max_line_;
};

#endif
