#ifndef LIBPROFCONT_AA
#define LIBPROFCONT_AA

#include <memory>
#include <profcont/ext_entrypoint.hpp>
#include "rules/no_colored_text.hpp"
#include "rules/has_required_chapters.hpp"

class Extension : public BaseExtension
{
public:
    explicit Extension(std::string &arg)
    {
        this->arg = arg;
    }

    std::vector<std::shared_ptr<BaseRule>> get_rules() override
    {
        auto required_chapters = Extension::get_required_chapters();
        return {
            std::make_shared<NoColoredText>(),
            std::make_shared<HasRequiredChapters>(required_chapters)
        };
    }

private:

    static std::vector<std::pair<std::string, bool>> get_required_chapters(){
        return {
            {"Введение",                 false},
            {"Аналитический раздел",     true},
            {"Конструкторский раздел",   true},
            {"Технологический раздел",   true},
            {"Экспериментальный раздел", true},
            {"Заключение",               false},
        };
    }

    std::string arg;
};

extern "C" BaseExtension *extension_creator(std::string &arg)
{
    return new Extension(arg);
}

extern "C" void extension_deleter(BaseExtension *ext)
{
    delete ext;
}

#endif