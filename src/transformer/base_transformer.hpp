//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_TRANSFORMER_HPP
#define PROFCONT_BASE_TRANSFORMER_HPP

#include <string>
#include <vector>

#include "source/base_source.hpp"
#include "target/base_target.hpp"
#include "rule/base_rule.hpp"

class BaseTransformer
{
public:
    virtual void transform(BaseTarget &target, BaseRule &rule, BaseSource &source) = 0;

    virtual std::vector<std::string> &get_errors() = 0;
};


#endif //PROFCONT_BASE_TRANSFORMER_HPP
