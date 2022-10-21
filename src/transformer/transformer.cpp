//
// Created by Михаил on 19.10.2022.
//

#include "transformer.hpp"

int Transformer::transform(std::shared_ptr<BaseTarget> &target, std::shared_ptr<BaseRule> &rule, std::shared_ptr<BaseSource> &source)
{
    std::string output;
    int res = 0;
    while (!source->is_over())
    {
        std::string data = source->get_data();
        res += rule->handle_data(output, this->errors, data);
        target->accept_data(output);
    }
    rule->handle_end(output, errors);
    target->accept_end(<#initializer#>);
    return res;
}

std::vector<std::string> &Transformer::get_errors()
{
    return this->errors;
}