//
// Created by Михаил on 19.10.2022.
//

#include "file_target.hpp"

void FileTarget::accept_data(std::string &data)
{
    this->file << data << std::endl;
}

void FileTarget::accept_end(std::string &final_data)
{
    this->file << final_data << std::endl;
}