//
// Created by Михаил on 21.10.2022.
//

#include "no_colored_text.hpp"

int NoColoredText::handle_data(std::string &output, std::vector<std::string> &errors, std::string &data)
{
    output = data;
    this->line++;
    std::regex regex = NoColoredText::get_color_regex();
    auto colored_begin = std::sregex_iterator(data.begin(), data.end(), regex),
        colored_end = std::sregex_iterator();
    if (colored_begin == colored_end)
    {
        return 0;
    }
    while (colored_begin != colored_end)
    {
        auto match = *colored_begin;
        errors.emplace_back("profcont_aa.nocoloredtext: line " + std::to_string(this->line) + " has colored text: " + match.str());
        ++colored_begin;
    }
    return 1;
}

int NoColoredText::handle_end(std::string &output, std::vector<std::string> &errors)
{
    this->line = 0;
    return BaseRule::handle_end(output, errors);
}

std::regex NoColoredText::get_color_regex()
{
    return std::regex(R"((\\textcolor(\[([^\[]*)\])?(\{([^\}]*)\}){1,}))");
}