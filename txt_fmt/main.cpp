#include "txt_fmt.h"
#include <iostream>
#include <string>

std::unique_ptr<TxtFmt> generate_object(const std::string &file_path)
{
    auto file_io = std::make_unique<TxtFmt>(file_path);
    return file_io;
}

int main(const int argc, char* argv[])
{
    // TODO: add max_line_ as an arg
    if (argc != 2)
    {
        std::cerr << "Provide a path to a plain text (.txt) file";
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }

    // TODO: add check to ensure file exists and is plain txt
    // TODO: add check to ensure max_line is between 1 and 300

    try
    {
        const std::unique_ptr<TxtFmt> file_io = generate_object(*++argv);
        const std::string file_data = file_io->read_file_in();
        // std::cout << file_data << std::endl;
        file_io->process_text(file_data);
    }
    catch (const std::exception &err)
    {
        // TODO: remove file if it was created (add get method to retrieve file name)
        
        std::cerr << "Error: " << err.what() << std::endl;
        exit(1);  // NOLINT(concurrency-mt-unsafe)
    }
    
    return 0;
}
