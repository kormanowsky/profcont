#include <iostream>
#include <utility>
#include <string>

#include "config/argparse/argparse_config_loader.hpp"
#include "extension/extension_loader.hpp"
#include "source/source_solution.hpp"
#include "target/target_solution.hpp"
#include "rule/rule_solution.hpp"
#include "transformer/transformer.hpp"

int main(int argc, char **argv)
{
    std::cout << "profcont by Mikhail Kormanovskiy, BMSTU" << std::endl;
    setlocale(LC_ALL, "Russian");
    ArgparseConfigLoader config_loader(argc, argv);
    std::shared_ptr<BaseConfig> config;
    try
    {
        config = config_loader.load_config();
    } catch (ProfContException &exc)
    {
        exit(-1);
    }

    std::shared_ptr<BaseExtensionLoader> loader = std::make_shared<ExtensionLoader>();

    RuleSolution rule_solution(config, loader);
    SourceSolution source_solution(config, loader);
    TargetSolution target_solution(config, loader);

    Transformer t;
    int rc;

    try
    {
        auto target = target_solution.create();
        auto rule = rule_solution.create();
        auto source = source_solution.create();
        rc = t.transform(
            target,
            rule,
            source
        );
    } catch (ProfContException &exc)
    {
        std::cerr << exc.what() << std::endl;
        return 1;
    }

    auto errors = t.get_errors();
    for (auto &error: t.get_errors())
    {
        std::cerr << error << std::endl;
    }

    std::cout << "profcont found " << errors.size() << " error" + std::string(errors.size() != 1 ? "s" : "") + "" << std::endl;

    return rc;
}
