#include <iostream>
#include "source/file_source.hpp"
#include "target/file_target.hpp"

int main()
{
    std::string filename = "test.tex";
    std::string out_filename = "result.tex";
    FileSource src(filename);
    FileTarget tgt(out_filename);
    while (!src.is_over())
    {
        std::string data = src.get_data();
        tgt.accept_data(data);
    }
    tgt.accept_end();
    return 0;
}
