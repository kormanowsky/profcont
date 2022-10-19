//
// Created by Михаил on 19.10.2022.
//

#include "no_vowels_rule.hpp"

int NoVowelsRule::handle_data(std::string &output, std::vector<std::string> &errors, std::string &data)
{
    int res = 0;
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    output = "";
    for (char &i: data)
    {
        if (std::find(vowels.begin(), vowels.end(), i) != vowels.end())
        {
            res++;
            errors.emplace_back("encountered forbidden symbol: " + std::to_string(i));
        }
        else
        {
            output += i;
        }
    }
    return res;
}