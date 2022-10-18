#include "../../../src/extension/base_extension.hpp"

class StringAtLeast4Sym : public BaseRule
{
    int handle_data(std::string &output, std::string &data) override
    {
        if (data.length() < 4)
        {
            output = "";
            return 1;
        }
        output = data;
        return 0;
    }
};

class Extension : public BaseExtension
{
public:
    std::shared_ptr<BaseRule> get_rule() override
    {
        return std::shared_ptr<BaseRule>(new StringAtLeast4Sym);
    }
};

extern "C" BaseExtension *extension_creator()
{
    return new Extension;
}

extern "C" void extension_deleter(BaseExtension *ext)
{
    delete ext;
}
