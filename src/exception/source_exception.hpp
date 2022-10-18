//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_SOURCE_EXCEPTION_HPP
#define PROFCONT_SOURCE_EXCEPTION_HPP

#include "exception/prof_cont_exception.hpp"

class SourceException : public ProfContException
{

public:
    explicit SourceException(std::string reason) : ProfContException(reason)
    {
// TODO: logic here
    }
};

#endif //PROFCONT_SOURCE_EXCEPTION_HPP
