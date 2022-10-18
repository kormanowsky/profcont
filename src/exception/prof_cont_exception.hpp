//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_PROF_CONT_EXCEPTION_HPP
#define PROFCONT_PROF_CONT_EXCEPTION_HPP

#include <string>
#include <exception>

class ProfContException : public std::exception
{
public:
    explicit ProfContException(std::string &reason) : reason(reason), std::exception()
    {

    }

    const char *what() const noexcept override
    {
        return this->reason.c_str();
    }

private:
    std::string reason;
};


#endif //PROFCONT_PROF_CONT_EXCEPTION_HPP
