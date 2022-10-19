#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "dependencies/argparse/argparse.hpp"

#include "extension/base_extension.hpp"
#include "extension/extension_loader.hpp"
#include "source/file_source.hpp"
#include "target/file_target.hpp"
#include "rule/no_vowels_rule.hpp"
#include "rule/rule_solution.hpp"
#include "transformer/transformer.hpp"

int main(int argc, char **argv)
{
    argparse::ArgumentParser parser("profcont");
    parser.add_description("Un Profesor Contento!\n"
                           "Transforms text files and performs useful checks to help students pass their reports quickly");
    parser.add_argument("input_file").help("input file").required();
    parser.add_argument("-o", "--output").help("output file (if needed)").default_value("/dev/null");
    parser.add_argument("-e", "--extension").help("one or more extensions (if needed)").append();
    try
    {
        parser.parse_args(argc, argv);
    } catch (const std::runtime_error &err)
    {
        std::cerr << parser << std::endl;
        std::cerr << err.what() << std::endl;
        return 1;
    }
    ExtensionLoader loader;
    RuleSolution solution(parser, loader);
    std::shared_ptr<BaseRule> rule = solution.create_rule();
    std::string filename = parser.get("input_file");
    std::string out_filename = parser.get("--output");
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
