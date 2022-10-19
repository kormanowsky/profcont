#include <iostream>

#include "config/argparse/argparse_config_loader.hpp"
#include "extension/extension_loader.hpp"
#include "source/source_solution.hpp"
#include "target/target_solution.hpp"
#include "rule/rule_solution.hpp"
#include "transformer/transformer.hpp"

int main(int argc, char **argv)
{
    ArgparseConfigLoader config_loader(argc, argv);
    std::shared_ptr<BaseConfig> config;
    try
    {
        config = config_loader.load_config();
    } catch (ProfContException &exc)
    {
        exit(-1);
    }

    ExtensionLoader loader;

    RuleSolution rule_solution(config, loader);
    SourceSolution source_solution(config, loader);
    TargetSolution target_solution(config, loader);

    auto target = target_solution.create();
    auto rule = rule_solution.create();
    auto source = source_solution.create();

    Transformer t;
    int rc = t.transform(
        target,
        rule,
        source
    );

    for (auto &error: t.get_errors())
    {
        std::cerr << error << std::endl;
    }
    return rc;
}
