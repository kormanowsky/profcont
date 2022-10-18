#include <iostream>
#include <memory>

#include "dlfcn.h"

#include "extension/base_extension.hpp"
#include "extension/extension_loader.hpp"
#include "source/file_source.hpp"
#include "target/file_target.hpp"
#include "rule/no_vowels_rule.hpp"
#include "transformer/transformer.hpp"

int main()
{
    ExtensionLoader loader;
    std::shared_ptr<BaseRule> rule = std::make_shared<NoVowelsRule>();
    std::string extension;
    std::cin >> extension;
    if (extension == "ext_aa")
    {
        auto ext = loader.load_extension(extension);
        rule = ext->get_rule();
    }
    std::string filename;
    std::string out_filename;
    std::cin >> filename >> out_filename;
    std::shared_ptr<BaseSource> src = std::make_shared<FileSource>(filename);
    std::shared_ptr<BaseTarget> tgt = std::make_shared<FileTarget>(out_filename);

    Transformer t;
    t.transform(tgt, rule, src);
    for (auto &error: t.get_errors())
    {
        std::cerr << error << std::endl;
    }
    return 0;
}
