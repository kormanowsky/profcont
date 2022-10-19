#ifndef EXT_AA
#define EXT_AA

#include <iostream>
#include <vector>
#include "../../../ext_entrypoint.hpp"

class StringAtLeast4Sym : public BaseRule
{
    int handle_data(std::string &output, std::vector<std::string> &errors, std::string &data) override
    {
        if (data.length() < 4)
        {
            output = "";
            errors.emplace_back("line length is less than 4: " + data);
            return 1;
        }
        output = data;
        return 0;
    }
};

class Extension : public BaseExtension
{
public:
    Extension(std::string &arg)
    {
        std::cout << "you instantiated Extension for AA with arg" + arg << std::endl;
    }

    std::shared_ptr<BaseRule> get_rule() override
    {
        return std::make_shared<StringAtLeast4Sym>();
    }
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