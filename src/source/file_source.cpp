//
// Created by Михаил on 19.10.2022.
//

#include "file_source.hpp"

std::string FileSource::get_data()
{
    std::string line;
    std::getline(this->file, line);
    return line;
}

bool FileSource::is_over()
{
    return this->file.eof();
}