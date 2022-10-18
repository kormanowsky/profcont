//
// Created by Михаил on 19.10.2022.
//

#include "no_vowels_rule.hpp"

int NoVowelsRule::handle_data(std::string &output, std::string &data)
{
    int errors = 0;
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    output = "";
    for (char &i: data)
    {
        if (std::find(vowels.begin(), vowels.end(), i) != vowels.end())
        {
            errors++;
        }
        else
        {
            output += i;
        }
    }
    return errors;
}