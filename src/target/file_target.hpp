//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_FILE_TARGET_HPP
#define PROFCONT_FILE_TARGET_HPP

#include <string>
#include <fstream>

#include "target/base_target.hpp"
#include "exception/target_exception.hpp"

class FileTarget : public BaseTarget
{
public:
    FileTarget(std::string &filename) : BaseTarget()
    {
        this->file.open(filename, std::ios::out);
        if (!this->file.is_open())
        {
            throw TargetException("unable to open file: " + filename);
        }
    }

    void accept_data(std::string &data) override;

    void accept_end(std::string &final_data) override;

    ~FileTarget()
    {
        this->file.close();
    }

private:
    std::ofstream file;
};


#endif //PROFCONT_FILE_TARGET_HPP
