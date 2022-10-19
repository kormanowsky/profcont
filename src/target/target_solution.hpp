//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_TARGET_SOLUTION_HPP
#define PROFCONT_TARGET_SOLUTION_HPP

#include "config/base_config.hpp"
#include "extension/base_extension_loader.hpp"
#include "target/file_target.hpp"

class TargetSolution
{
public:
    TargetSolution(std::shared_ptr<BaseConfig> &config, BaseExtensionLoader &loader);

    std::shared_ptr<BaseTarget> create();

private:
    std::string output_file;
};


#endif //PROFCONT_TARGET_SOLUTION_HPP
