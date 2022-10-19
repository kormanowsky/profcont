//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_COMPLEX_RULE_HPP
#define PROFCONT_COMPLEX_RULE_HPP

#include <vector>
#include <memory>
#include "rule/base_rule.hpp"

class ComplexRule : public BaseRule
{
public:
    bool add(std::shared_ptr<BaseRule> &rule) override;

    int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) override;

private:
    std::vector<std::shared_ptr<BaseRule>> rules;
};


#endif //PROFCONT_COMPLEX_RULE_HPP
