//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_TARGET_HPP
#define PROFCONT_BASE_TARGET_HPP

#include <string>

class BaseTarget
{
public:
    virtual void accept_data(std::string &data) = 0;

    virtual void accept_end() = 0;
};


#endif //PROFCONT_BASE_TARGET_HPP
