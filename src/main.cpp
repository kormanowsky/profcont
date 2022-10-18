#include <iostream>
#include "source/file_source.hpp"
#include "target/file_target.hpp"
#include "rule/no_vowels_rule.hpp"

int main()
{
    std::string filename = "test.tex";
    std::string out_filename = "result.tex";
    FileSource src(filename);
    FileTarget tgt(out_filename);
    NoVowelsRule rule;
    while (!src.is_over())
    {
        std::string data = src.get_data();
        std::string output;
        int errors = rule.handle_data(output, data);
        if (errors != 0)
        {
            std::cerr << "errors:" << errors << std::endl;
        }
        tgt.accept_data(output);
    }
    tgt.accept_end();
    return 0;
}
