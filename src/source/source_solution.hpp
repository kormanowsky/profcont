//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_SOURCE_SOLUTION_HPP
#define PROFCONT_SOURCE_SOLUTION_HPP

#include "config/base_config.hpp"
#include "extension/base_extension_loader.hpp"
#include "source/file_source.hpp"

class SourceSolution
{
public:
    SourceSolution(std::shared_ptr<BaseConfig> &config, std::shared_ptr<BaseExtensionLoader> &loader);

    std::shared_ptr<BaseSource> create();

private:
    std::string input_file;
};


#endif //PROFCONT_SOURCE_SOLUTION_HPP
