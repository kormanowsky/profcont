//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_RULE_SOLUTION_HPP
#define PROFCONT_RULE_SOLUTION_HPP

#include <vector>
#include <string>
#include <typeinfo>

#include "config/base_config.hpp"
#include "extension/base_extension_loader.hpp"
#include "rule/complex_rule.hpp"

class RuleSolution
{
public:
    RuleSolution(std::shared_ptr<BaseConfig> &config, std::shared_ptr<BaseExtensionLoader> &loader);

    std::shared_ptr<BaseRule> create();

private:
    std::shared_ptr<BaseRule> rule;
    std::shared_ptr<BaseConfig> config;
    std::shared_ptr<BaseExtensionLoader> loader;
};


#endif //PROFCONT_RULE_SOLUTION_HPP
