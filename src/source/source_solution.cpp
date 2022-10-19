//
// Created by Михаил on 19.10.2022.
//

#include "source_solution.hpp"

SourceSolution::SourceSolution(std::shared_ptr<BaseConfig> &config, std::shared_ptr<BaseExtensionLoader> &loader)
{
    this->input_file = config->get_input_file();
}

std::shared_ptr<BaseSource> SourceSolution::create()
{
    return std::make_shared<FileSource>(this->input_file);
}