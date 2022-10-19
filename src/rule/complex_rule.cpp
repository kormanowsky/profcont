//
// Created by Михаил on 19.10.2022.
//

#include "complex_rule.hpp"

int ComplexRule::handle_data(std::string &output, std::string &data)
{
    int res = 0;
    std::string tmp;
    for (auto &rule: this->rules)
    {
        res += rule->handle_data(tmp, data);
        data = tmp; // TODO: затирание результатов?
    }
    output = tmp;
    return res;
}

bool ComplexRule::add(std::shared_ptr<BaseRule> &rule)
{
    this->rules.emplace_back(rule);
    return true;
}