#include "date_str.h"
#include "txt_fmt.h"
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <windows.h>


TxtFmt::TxtFmt(std::string path, const int max_chars) : path_(std::move(path)), max_chars_(max_chars) 
{
    output_file_path = path_ + "." + get_date_str();
}

std::string TxtFmt::get_output_file_path() const
{
    return output_file_path;
}

std::string TxtFmt::read_file_in() const
{
    std::ifstream file_handle(path_);
    std::stringstream buffer;
    if (file_handle.is_open())
        buffer << file_handle.rdbuf();
    else
        throw std::runtime_error("failed to open file for read operation");
    
    file_handle.close();
    return buffer.str();
}

void TxtFmt::process_text(const std::string &file_data) const
{
    std::ofstream file_handle;
    file_handle.open(output_file_path);
    if (!(file_handle.is_open()))
        throw std::runtime_error("failed to open file for write operation");
    
    std::vector<std::string> text_blocks;
    const std::regex new_lines(R"(\n)");
    std::copy(std::sregex_token_iterator(file_data.begin(), file_data.end(), new_lines, -1),
        std::sregex_token_iterator(), std::back_inserter(text_blocks));

    for (auto& text : text_blocks)
    {
        if (text.empty())
        {
            file_handle << "\n";
            continue;
        }
       
        const std::regex spaces(R"([\s\t])");
        std::sregex_token_iterator iter_spaces(text.begin(),  text.end(), spaces, -1);

        std::string current_line;
        int word_index = 0;
        for (const std::sregex_token_iterator end; iter_spaces != end; ++iter_spaces)
        {
            std::string word = *iter_spaces;
            if (word.length() > static_cast<unsigned long long>(max_chars_))
            {
                file_handle.close();
                throw std::invalid_argument("words in input text cannot exceed max-chars");
            }

            if (word.length() < 1)
                word = " ";
            
            if (current_line.length() + word.length() + 1 > static_cast<unsigned long long>(max_chars_))
            {
                file_handle << current_line << "\n";
                current_line = word;
            }
            else if (word_index > 0 && word != " ")
            {
                current_line.append(" " + word);
            }
            else
            {
                current_line.append(word);
            }

            word_index++;
        }
        file_handle << current_line << std::endl;
    }

    file_handle.close();
}
