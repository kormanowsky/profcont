//
// Created by Михаил on 22.10.2022.
//

#include "chapter.hpp"

std::string Chapter::get_name()
{
    return this->name;
}

bool Chapter::is_starred()
{
    return this->starred;
}
