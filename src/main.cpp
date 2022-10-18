#include <iostream>
#include "source/file_source.hpp"

int main()
{
    std::string filename = "test.tex";
    FileSource src(filename);
    while (!src.is_over())
    {
        std::cout << src.get_data() << std::endl;
    }
    return 0;
}
