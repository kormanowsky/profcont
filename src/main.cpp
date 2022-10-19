#include <iostream>
#include <memory>

#include "config/argparse/argparse_config_loader.hpp"
#include "extension/base_extension.hpp"
#include "extension/extension_loader.hpp"
#include "source/file_source.hpp"
#include "target/file_target.hpp"
#include "rule/rule_solution.hpp"
#include "transformer/transformer.hpp"

int main(int argc, char **argv)
{
    ArgparseConfigLoader config_loader(argc, argv);
    auto config = config_loader.load_config();
    ExtensionLoader loader;
    RuleSolution solution(config, loader);
    std::shared_ptr<BaseRule> rule = solution.create_rule();
    std::string filename = config->get_input_file();
    std::string out_filename = config->get_output_file();
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
