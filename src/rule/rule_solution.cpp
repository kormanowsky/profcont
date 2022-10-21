//
// Created by Михаил on 19.10.2022.
//

#include "rule_solution.hpp"

RuleSolution::RuleSolution(std::shared_ptr<BaseConfig> &config, std::shared_ptr<BaseExtensionLoader> &loader)
{
    this->rule = std::make_shared<ComplexRule>();
    this->config = config;
    this->loader = loader;
}

std::shared_ptr<BaseRule> RuleSolution::create()
{
    for (auto &params: this->config->get_extension_params())
    {
        auto ext = this->loader->load_extension(params.first, params.second);
        auto rules = ext->get_rules();
        for (auto &r: rules)
        {
            this->rule->add(r);
        }
    }
    return this->rule;
}