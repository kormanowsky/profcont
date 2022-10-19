//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_TRANSFORMER_HPP
#define PROFCONT_TRANSFORMER_HPP

#include <string>
#include <vector>
#include <memory>

#include "transformer/base_transformer.hpp"

class Transformer : public BaseTransformer
{
public:
    int transform(std::shared_ptr<BaseTarget> &target, std::shared_ptr<BaseRule> &rule, std::shared_ptr<BaseSource> &source) override;

    std::vector<std::string> &get_errors() override;

private:
    std::vector<std::string> errors = {};
};


#endif //PROFCONT_TRANSFORMER_HPP
