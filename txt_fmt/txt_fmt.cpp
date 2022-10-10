#include "txt_fmt.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>


TxtFmt::TxtFmt(std::string path) : file_path_(std::move(path))
{
    // TODO remove max line and add datestamp here
    
    max_line = 79;
}

std::string TxtFmt::read_file_in() const
{
    std::ifstream file_handle(file_path_);
    std::stringstream buffer;
    if (file_handle.is_open())
    {
        buffer << file_handle.rdbuf();
    }
    else
    {
        throw std::runtime_error("Failed to open file for read operation");
    }
    file_handle.close();
    return buffer.str();
}

void TxtFmt::process_text(const std::string &file_data) const
{
    std::ofstream file_handle;
    
    // TODO: add datestamp instead of .out
    
    file_handle.open(file_path_ + ".out");
    if (!(file_handle.is_open()))
    {
        throw std::runtime_error("Failed to open file for write operation");
    }

    std::vector<std::string> text_blocks;
    const std::regex pattern_newlines(R"(\n)");
    std::copy(std::sregex_token_iterator(file_data.begin(), file_data.end(), pattern_newlines, -1),
        std::sregex_token_iterator(), std::back_inserter(text_blocks));

    for (auto& text_block : text_blocks)
    {
        if (text_block.empty())
        {
            file_handle << "\n";
        }
        else
        {
            const std::regex spaces(R"([\s\t])");
            std::sregex_token_iterator iter_spaces(text_block.begin(),  text_block.end(), spaces, -1);

            std::string current_line;

            for (const std::sregex_token_iterator end; iter_spaces != end; ++iter_spaces)
            {
                std::string word = *iter_spaces;

                // TODO: Check if word is longer than max_line_, throw exception if too long and close the open file handle
                
                if (word.length() < 1)
                {
                    word = " ";
                }
                
                if (current_line.length() + word.length() > max_line)
                {
                    file_handle << current_line << "\n";
                    current_line = word;
                }
                else
                {
                    current_line.append(word);
                }

                if (word != " ")
                {
                    current_line.append(" ");
                }
            }
        }
    }

    file_handle.close();
}
