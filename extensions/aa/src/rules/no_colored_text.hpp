//
// Created by Михаил on 21.10.2022.
//

#ifndef PROFCONT_AA_NO_COLORED_TEXT_HPP
#define PROFCONT_AA_NO_COLORED_TEXT_HPP

#include <string>
#include <vector>
#include <regex>

#include <profcont/ext_entrypoint.hpp>

class NoColoredText : public BaseRule
{
public:
    int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) override;

    int handle_end(std::string &output, std::vector<std::string> &errors) override;

private:
    static std::regex get_color_regex();

    int line = 0;
};


#endif //PROFCONT_AA_NO_COLORED_TEXT_HPP
