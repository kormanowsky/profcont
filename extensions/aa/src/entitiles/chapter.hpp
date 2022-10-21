//
// Created by Михаил on 22.10.2022.
//

#ifndef PROFCONT_AA_CHAPTER_HPP
#define PROFCONT_AA_CHAPTER_HPP

#include <string>
#include <utility>

class Chapter
{
public:
    Chapter(std::string name, const bool starred = false) : name(std::move(name)), starred(starred)
    {}

    std::string get_name();

    bool is_starred();

private:
    std::string name;
    bool starred;
};


#endif //PROFCONT_AA_CHAPTER_HPP
