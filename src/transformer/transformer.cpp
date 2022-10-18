//
// Created by Михаил on 19.10.2022.
//

#include "transformer.hpp"

void Transformer::transform(BaseTarget &target, BaseRule &rule, BaseSource &source)
{
    while (!source.is_over())
    {
        std::string data = source.get_data();
        std::string output;
        int err_count = rule.handle_data(output, data);
        if (err_count != 0)
        {
            this->errors.emplace_back("errors:" + std::to_string(err_count));
        }
        target.accept_data(output);
    }
    target.accept_end();
}

std::vector<std::string> &Transformer::get_errors()
{
    return this->errors;
}