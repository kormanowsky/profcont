//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_TARGET_EXCEPTION_HPP
#define PROFCONT_TARGET_EXCEPTION_HPP

#include "exception/prof_cont_exception.hpp"

class TargetException : public ProfContException
{
public:
    explicit TargetException(std::string reason) : ProfContException(reason)
    {
        // TODO; some logic here
    }
};


#endif //PROFCONT_TARGET_EXCEPTION_HPP
