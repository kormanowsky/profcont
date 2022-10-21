#ifndef LIBPROFCONT_AA
#define LIBPROFCONT_AA

#include <memory>
#include <profcont/ext_entrypoint.hpp>
#include "rules/no_colored_text.hpp"
#include "rules/has_required_chapters.hpp"
#include "entitiles/chapter.hpp"

class Extension : public BaseExtension
{
public:
    explicit Extension(std::string &arg)
    {
        this->arg = arg;
    }

    std::vector<std::shared_ptr<BaseRule>> get_rules() override
    {
        std::vector<std::shared_ptr<Chapter>> req = {
            std::make_shared<Chapter>("Введение", true),
            std::make_shared<Chapter>("Аналитический раздел"),
            std::make_shared<Chapter>("Конструкторский раздел"),
            std::make_shared<Chapter>("Технологический раздел"),
            std::make_shared<Chapter>("Экспериментальный раздел"),
            std::make_shared<Chapter>("Заключение", true),
        };

        return {
            std::make_shared<NoColoredText>(),
            std::make_shared<HasRequiredChapters>(req)
        };
    }

private:

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