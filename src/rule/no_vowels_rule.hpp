//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_NO_VOWELS_RULE_HPP
#define PROFCONT_NO_VOWELS_RULE_HPP

#include <string>
#include <vector>
#include <algorithm>

#include "base_rule.hpp"

class NoVowelsRule : public BaseRule
{
public:
    int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) override;
};


#endif //PROFCONT_NO_VOWELS_RULE_HPP
