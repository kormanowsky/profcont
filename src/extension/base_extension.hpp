//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_BASE_EXTENSION_HPP
#define PROFCONT_BASE_EXTENSION_HPP

#include <memory>
#include "../rule/base_rule.hpp"

class BaseExtension
{
public:
    virtual std::shared_ptr<BaseRule> get_rule() = 0;

    virtual ~BaseExtension() = default;
};

using ExtensionCreator = BaseExtension *(std::string &arg);
using ExtensionDeleter = void(BaseExtension *);

#endif //PROFCONT_BASE_EXTENSION_HPP
