//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_RULE_SOLUTION_HPP
#define PROFCONT_RULE_SOLUTION_HPP

#include <vector>
#include <string>
#include <typeinfo>

#include "dependencies/argparse/argparse.hpp"
#include "extension/extension_loader.hpp"
#include "rule/complex_rule.hpp"
#include "rule/no_vowels_rule.hpp"

class RuleSolution
{
public:
    RuleSolution(argparse::ArgumentParser &parser, ExtensionLoader &loader)
    {
        this->rule = std::make_shared<ComplexRule>();
        auto extensions = parser.get<std::vector<std::string>>("--extension");
        for (auto &extension: extensions)
        {
            std::shared_ptr<BaseExtension> ext;
            auto eq_pos = extension.find("=");
            if (eq_pos == std::string::npos)
            {
                ext = loader.load_extension(extension);
            }
            else if (std::count(extension.begin(), extension.end(), '=') != 1)
            {
                throw ProfContException("invalid extension with argument: " + extension + ". There must be 0 or 1 = in extension");
            }
            else
            {
                std::string name = extension.substr(0, eq_pos), arg = extension.substr(eq_pos);
                ext = loader.load_extension(name, arg);
            }
            auto ext_rule = ext->get_rule();
            this->rule->add(ext_rule);
        }
    }

    std::shared_ptr<BaseRule> create_rule()
    {
        return this->rule;
    }

private:
    std::shared_ptr<BaseRule> rule;
};


#endif //PROFCONT_RULE_SOLUTION_HPP
