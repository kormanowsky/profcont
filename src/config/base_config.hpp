//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_CONFIG_HPP
#define PROFCONT_BASE_CONFIG_HPP

#include <vector>
#include <string>

class BaseConfig
{
public:
    virtual std::string get_input_file() = 0;

    virtual std::string get_output_file() = 0;

    virtual std::vector<std::pair<std::string, std::string>> get_extension_params() = 0;
};


#endif //PROFCONT_BASE_CONFIG_HPP
