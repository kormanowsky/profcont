#include <iostream>
#include "source/file_source.hpp"
#include "target/file_target.hpp"
#include "rule/no_vowels_rule.hpp"
#include "transformer/transformer.hpp"

int main()
{
    std::string filename = "test.tex";
    std::string out_filename = "result.tex";
    std::shared_ptr<BaseSource> src = std::make_shared<FileSource>(filename);
    std::shared_ptr<BaseTarget> tgt = std::make_shared<FileTarget>(out_filename);
    std::shared_ptr<BaseRule> rule = std::make_shared<NoVowelsRule>();
    Transformer t;
    t.transform(tgt, rule, src);
    for (auto &error: t.get_errors())
    {
        std::cerr << error << std::endl;
    }
    return 0;
}
