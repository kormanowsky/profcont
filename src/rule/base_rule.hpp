//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_RULE_HPP
#define PROFCONT_BASE_RULE_HPP

#include <string>

class BaseRule
{
public:
    virtual bool add(std::shared_ptr<BaseRule> &rule)
    {
        return false;
    };

    virtual int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) = 0;
};


#endif //PROFCONT_BASE_RULE_HPP
