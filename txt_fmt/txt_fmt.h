#pragma once

#ifndef TXT_FMT_H
#define TXT_FMT_H
#include <string>

class TxtFmt
{

public:
    explicit TxtFmt(std::string path, int max_chars);
    // TODO: possibly move read_file_in() to private:
    std::string read_file_in() const;
    void process_text(const std::string &file_data) const;
    // unsigned long long max_line;

    // TODO: add public getter to retrieve the new filepath with datestamp

private:
    std::string path_;
    int max_chars_;
    
};

#endif
