#pragma once

#ifndef TXT_FMT_H
#define TXT_FMT_H
#include <string>

class TxtFmt
{

public:
    explicit TxtFmt(std::string path, int max_chars);
    std::string get_output_file_path() const;
    std::string read_file_in() const;
    void process_text(const std::string &file_data) const;
    std::string output_file_path;

private:
    std::string path_;
    int max_chars_;
    
};

#endif
