#include "txt_fmt.h"
#include <iostream>
#include <string>

std::unique_ptr<TxtFmt> generate_object(const std::string &path, unsigned long long max_line)
{
    auto txt_fmt = std::make_unique<TxtFmt>(path, max_line);
    return txt_fmt;
}

int main(const int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Provide a path to a plain text (.txt) file and max line-length";
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }

    // TODO: add check to ensure file exists and is plain txt
    // TODO: add check to ensure max_line is between 1 and 400
    
    try
    {
        const std::unique_ptr<TxtFmt> txt_fmt = generate_object(*(argv + 1), static_cast<unsigned long long>(std::stoi(*(argv + 2))));
        const std::string file_data = txt_fmt->read_file_in();
        txt_fmt->process_text(file_data);
    }
    catch (const std::exception &err)
    {
        // TODO: remove file if it was created (add get method to retrieve file name)
        
        std::cerr << "Error: " << err.what() << std::endl;
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }
    
    return 0;
}
