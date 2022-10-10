#pragma once

#ifndef FILE_IO_H
#define FILE_IO_H
#include <string>

class TxtFmt
{

public:
    explicit TxtFmt(std::string path);
    std::string read_file_in() const;
    void process_text(const std::string &file_data) const;
    unsigned long long max_line;

private:
    std::string file_path_;
};

#endif
