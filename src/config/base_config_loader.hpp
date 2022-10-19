//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_CONFIG_LOADER_HPP
#define PROFCONT_BASE_CONFIG_LOADER_HPP

#include "config/base_config.hpp"

class BaseConfigLoader
{
public:
    virtual std::shared_ptr<BaseConfig> load_config() = 0;
};


#endif //PROFCONT_BASE_CONFIG_LOADER_HPP
