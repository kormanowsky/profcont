//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_ARGPARSE_CONFIG_LOADER_HPP
#define PROFCONT_ARGPARSE_CONFIG_LOADER_HPP

#include "exception/prof_cont_exception.hpp"

#include "config/argparse/argparse.hpp"
#include "config/base_config_loader.hpp"
#include "config/base_config.hpp"

class ArgparseConfig : public BaseConfig
{
public:
    ArgparseConfig(std::string &input_file, std::string &output_file,
        std::vector<std::pair<std::string, std::string>> &extension_params)
        : input_file(input_file), output_file(output_file), extension_params(extension_params)
    {

    }

    std::string get_input_file() override
    {
        return this->input_file;
    }

    std::string get_output_file() override
    {
        return this->output_file;
    }

    std::vector<std::pair<std::string, std::string>> get_extension_params() override
    {
        return this->extension_params;
    }

private:
    std::string input_file, output_file;
    std::vector<std::pair<std::string, std::string>> extension_params;
};

class ArgparseConfigLoader : public BaseConfigLoader
{
public:
    explicit ArgparseConfigLoader(int argc, char **argv) : argc(argc), argv(argv)
    {
        this->parser = argparse::ArgumentParser("profcont");
        this->parser.add_description("Un Profesor Contento!\n"
                                     "Transforms text files and performs useful checks to help students pass their reports quickly");
        this->parser.add_argument("input_file").help("input file").required();
        this->parser.add_argument("-o", "--output").help("output file (if needed)").default_value("/dev/null");
        this->parser.add_argument("-e", "--extension").help("one or more extensions (if needed)").append();
    }

    std::shared_ptr<BaseConfig> load_config() override
    {
        try
        {
            parser.parse_args(argc, argv);
        } catch (const std::runtime_error &err)
        {
            std::cerr << parser << std::endl;
            std::cerr << err.what() << std::endl;
            throw ProfContException("config loader unable to load config");
        }
        auto input_file = parser.get("input_file"), output_file = parser.get("--output");
        auto extension_params = this->load_extension_params();
        return std::make_shared<ArgparseConfig>(
            input_file,
            output_file,
            extension_params
        );
    }

protected:
    std::vector<std::pair<std::string, std::string>> load_extension_params()
    {
        std::vector<std::pair<std::string, std::string>> extension_params;
        auto extensions = parser.get<std::vector<std::string>>("--extension");
        for (auto &extension: extensions)
        {
            auto eq_pos = extension.find("=");
            std::pair<std::string, std::string> ext_params;
            if (eq_pos == std::string::npos)
            {
                ext_params.first = extension;
                ext_params.second = "";
            }
            else if (std::count(extension.begin(), extension.end(), '=') != 1)
            {
                throw ProfContException("invalid extension with argument: " + extension + ". There must be 0 or 1 = in extension");
            }
            else
            {
                std::string name = extension.substr(0, eq_pos), arg = extension.substr(eq_pos);
                ext_params.first = name;
                ext_params.second = arg;
            }
            extension_params.emplace_back(ext_params);
        }
        return extension_params;
    }

private:
    int argc;
    char **argv;
    argparse::ArgumentParser parser;
};


#endif //PROFCONT_ARGPARSE_CONFIG_LOADER_HPP
