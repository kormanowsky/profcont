//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_SOURCE_HPP
#define PROFCONT_BASE_SOURCE_HPP

#include <string>

class BaseSource
{
public:
    virtual std::string get_data() = 0;

    virtual bool is_over() = 0;
};


#endif //PROFCONT_BASE_SOURCE_HPP
