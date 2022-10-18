//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_FILE_SOURCE_HPP
#define PROFCONT_FILE_SOURCE_HPP

#include <fstream>

#include "source/base_source.hpp"
#include "exception/source_exception.hpp"


class FileSource : public BaseSource
{
public:
    explicit FileSource(std::string &filename) : BaseSource()
    {
        this->file.open(filename, std::ios::in);
        if (!this->file.is_open())
        {
            throw SourceException("unable to open file: " + filename);
        }
    }

    std::string get_data() override;

    bool is_over() override;

    ~FileSource()
    {
        this->file.close();
    }

private:
    std::ifstream file;
};


#endif //PROFCONT_FILE_SOURCE_HPP
