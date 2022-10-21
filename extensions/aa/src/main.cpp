#ifndef LIBPROFCONT_AA
#define LIBPROFCONT_AA

#include <memory>
#include "rules/no_colored_text.hpp"

class Extension : public BaseExtension
{
public:
    explicit Extension(std::string &arg)
    {
        this->arg = arg;
    }

    std::shared_ptr<BaseRule> get_rule() override
    {
        return std::make_shared<NoColoredText>();
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