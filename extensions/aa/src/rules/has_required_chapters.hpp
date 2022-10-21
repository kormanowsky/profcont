//
// Created by Михаил on 22.10.2022.
//

#ifndef PROFCONT_AA_HAS_REQUIRED_CHAPTERS_HPP
#define PROFCONT_AA_HAS_REQUIRED_CHAPTERS_HPP

#include <vector>
#include <string>
#include <utility>
#include <regex>
#include <iostream>

#include <profcont/ext_entrypoint.hpp>

#include "entitiles/chapter.hpp"

class HasRequiredChapters : public BaseRule
{
public:
    explicit HasRequiredChapters(const std::vector<std::shared_ptr<Chapter>> &chapters) :
        chapters(chapters)
    {
        this->chapter_it = this->chapters.cbegin();
    }

    int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) override;

    int handle_end(std::string &output, std::vector<std::string> &errors) override;

private:
    static std::regex get_chapter_regex();

    std::vector<std::shared_ptr<Chapter>> chapters;
    std::vector<std::shared_ptr<Chapter>>::const_iterator chapter_it;
};


#endif //PROFCONT_AA_HAS_REQUIRED_CHAPTERS_HPP
