//
// Created by Михаил on 21.10.2022.
//

#include "no_colored_text.hpp"

int NoColoredText::handle_data(std::string &output, std::vector<std::string> &errors, std::string &data)
{
    int res = 0;
    if (data.find("\\textcolor") != std::string::npos)
    {
        errors.emplace_back("colored text: " + data);
        res = 1;
    }
    output = data;
    return res;
}