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
        ++this->chapter_it;
        if (expected_chapter->get_name() != chapter_name)
        {
            errors.emplace_back("profcont_aa.has_required_chapters: unexpected chapter: " +
                chapter_name + ", expected " + expected_chapter->get_name());
            return 1;
        }
        if (star == "*" && !expected_chapter->is_starred())
        {
            errors.emplace_back("profcont_aa.has_required_chapters: missing number for chapter: " +
                chapter_name + ", remove * from \\chapter*");
            return 1;
        }
        if (star.empty() && expected_chapter->is_starred())
        {
            errors.emplace_back("profcont_aa.has_required_chapters: extra number for chapter: " +
                chapter_name + ", add * to \\chapter");
            return 1;
        }
    }
    return 0;
}

int HasRequiredChapters::handle_end(std::string &output, std::vector<std::string> &errors)
{
    output = "";
    int res = 0;
    auto end_it = this->chapters.cend();
    auto cur_it = this->chapter_it;
    if (cur_it < end_it)
    {
        while (cur_it < end_it)
        {
            errors.emplace_back("profcont_aa.has_required_chapters: missing chapter: " + (*cur_it)->get_name());
            ++cur_it;
        }
        res = 1;
    }
    this->chapter_it = this->chapters.cbegin();
    return res;
}

std::regex HasRequiredChapters::get_chapter_regex()
{
    return std::regex(R"(\\chapter(\*)?\{([^\}]*)\})");
}