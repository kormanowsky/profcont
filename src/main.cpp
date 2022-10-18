#include <iostream>
#include "source/file_source.hpp"
#include "target/file_target.hpp"
#include "rule/no_vowels_rule.hpp"
#include "transformer/transformer.hpp"

int main()
{
    std::string filename = "test.tex";
    std::string out_filename = "result.tex";
    FileSource src(filename);
    FileTarget tgt(out_filename);
    NoVowelsRule rule;
    Transformer t;
    t.transform(tgt, rule, src);
    for (auto &error: t.get_errors())
    {
        std::cerr << error << std::endl;
    }
    return 0;
}
