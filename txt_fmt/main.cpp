#include "txt_fmt.h"
#include <iostream>
#include <string>


std::unique_ptr<TxtFmt> generate_object(const std::string &path, int max_chars)
{
    auto txt_fmt = std::make_unique<TxtFmt>(path, max_chars);
    return txt_fmt;
}


bool is_valid_file(const std::string &file_path)
{
    struct stat file_name_buff{};
    return stat(file_path.c_str(), &file_name_buff) == 0;
}


int validate_digit(const std::string &digit)
{
    try
    {
        const int max_line_chars = std::stoi(digit);
        if (max_line_chars < 1 || max_line_chars > 400) 
        {
            throw std::invalid_argument("max-chars arg is not between 1 and 400");
        }
        return max_line_chars;
    }
    catch(const std::exception &err)
    {
        (void)err;
        throw std::invalid_argument("max-chars arg not a valid integer between 1 & 400");
    }
    
}


int main(const int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "error: provide a path to a plain-text file & a max line-length\n";
        std::cerr << "usage: txt_fmt <file-path> <max-chars-per-line>  txt_fmt test.txt 79\n";
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }

    const std::string input_file = *(argv + 1);
    int max_chars_arg;
    
    try
    {
        if (!(is_valid_file(input_file)))
        {
            throw std::invalid_argument("input filepath arg does not exist");
        }
        max_chars_arg = validate_digit(*(argv + 2));
    }
    catch (const std::invalid_argument &err)
    {
        std::cerr << "error: " << err.what() << std::endl;
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }

    const std::unique_ptr<TxtFmt> txt_fmt = generate_object(input_file, max_chars_arg);
    
    try
    {
        const std::string file_data = txt_fmt->read_file_in();
        txt_fmt->process_text(file_data);
    }
    catch (const std::exception &err)
    {
        // TODO: remove file if it was created (add get method to retrieve file name)
        
        std::cerr << "error: " << err.what() << std::endl;
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }
    
    return 0;
}
