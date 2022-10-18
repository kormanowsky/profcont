//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_EXTENSION_LOADER_HPP
#define PROFCONT_BASE_EXTENSION_LOADER_HPP

#include "base_extension.hpp"

class BaseExtensionLoader
{
public:
    virtual std::shared_ptr<BaseExtension> load_extension(std::string &name) = 0;
};


#endif //PROFCONT_BASE_EXTENSION_LOADER_HPP
