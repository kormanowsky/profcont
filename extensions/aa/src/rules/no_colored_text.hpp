//
// Created by Михаил on 21.10.2022.
//

#ifndef PROFCONT_AA_NO_COLORED_TEXT_HPP
#define PROFCONT_AA_NO_COLORED_TEXT_HPP

#include <string>
#include <vector>

#include "../../../../ext_entrypoint.hpp"

class NoColoredText : public BaseRule
{
public:
    int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) override;
};


#endif //PROFCONT_AA_NO_COLORED_TEXT_HPP
