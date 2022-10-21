//
// Created by Михаил on 22.10.2022.
//

#include "has_required_chapters.hpp"

int HasRequiredChapters::handle_data(std::string &output, std::vector<std::string> &errors, std::string &data)
{
    output = data;
    std::smatch matches;
    if (std::regex_search(data, matches, HasRequiredChapters::get_chapter_regex()))
    {
        auto star = matches[1].str(), chapter_name = matches[2].str();
        if (this->chapter_it >= this->chapters.cend())
        {
            errors.emplace_back("profcont_aa.has_required_chapters: extra chapter: " + chapter_name);
            return 1;
        }
        auto expected_chapter = *this->chapter_it;
        if (expected_chapter.first != chapter_name)
        {
            errors.emplace_back("profcont_aa.has_required_chapters: unexpected chapter: " +
                chapter_name + ", expected " + expected_chapter.first);
            return 1;
        }
        if (star == "*" && expected_chapter.second)
        {
            errors.emplace_back("profcont_aa.has_required_chapters: missing number for chapter: " +
                chapter_name + ", remove * from \\chapter*");
            return 1;
        }
        if (star.empty() && !expected_chapter.second)
        {
            errors.emplace_back("profcont_aa.has_required_chapters: extra number for chapter: " +
                chapter_name + ", add * to \\chapter");
            return 1;
        }
        ++chapter_it;
    }
    return 0;
}

int HasRequiredChapters::handle_end(std::string &output, std::vector<std::string> &errors)
{
    int res = 0;
    if (this->chapter_it < this->chapters.cend())
    {
        std::string error = "profcont_aa.has_required_chapters: missing chapters: ";
        while (this->chapter_it < this->chapters.cend())
        {
            error += (*this->chapter_it).first + ";";
        }
        errors.emplace_back(error);
        res = 1;
    }
    this->chapter_it = this->chapters.cbegin();
    return res;
}

std::regex HasRequiredChapters::get_chapter_regex()
{
    return std::regex(R"(\\chapter(\*)?\{([^\}]*)\})");
}