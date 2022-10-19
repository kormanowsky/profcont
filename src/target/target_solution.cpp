//
// Created by Михаил on 19.10.2022.
//

#include "target_solution.hpp"

TargetSolution::TargetSolution(std::shared_ptr<BaseConfig> &config, std::shared_ptr<BaseExtensionLoader> &loader)
{
    this->output_file = config->get_output_file();
}

std::shared_ptr<BaseTarget> TargetSolution::create()
{
    return std::make_shared<FileTarget>(this->output_file);
}