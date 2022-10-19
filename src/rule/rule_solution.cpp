//
// Created by Михаил on 19.10.2022.
//

#include "rule_solution.hpp"

RuleSolution::RuleSolution(std::shared_ptr<BaseConfig> &config, BaseExtensionLoader &loader)
{
    this->rule = std::make_shared<ComplexRule>();
    for (auto &params: config->get_extension_params())
    {
        auto ext = loader.load_extension(params.first, params.second);
        auto _rule = ext->get_rule();
        this->rule->add(_rule);
    }
}