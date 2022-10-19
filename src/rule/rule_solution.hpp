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
    RuleSolution(std::shared_ptr<BaseConfig> &config, BaseExtensionLoader &loader)
    {
        this->rule = std::make_shared<ComplexRule>();
        for (auto &params: config->get_extension_params())
        {
            auto ext = loader.load_extension(params.first, params.second);
            auto _rule = ext->get_rule();
            this->rule->add(_rule);
        }
    }

    std::shared_ptr<BaseRule> create()
    {
        return this->rule;
    }

private:
    std::shared_ptr<BaseRule> rule;
};


#endif //PROFCONT_RULE_SOLUTION_HPP
