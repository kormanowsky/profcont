//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_EXTENSION_LOADER_HPP
#define PROFCONT_EXTENSION_LOADER_HPP

#include <dlfcn.h>
#include <vector>
#include <utility>
#include <map>
#include <filesystem>

#include "exception/prof_cont_exception.hpp"
#include "extension/base_extension_loader.hpp"

class ExtensionLoader : public BaseExtensionLoader
{
public:

    ExtensionLoader();

    std::shared_ptr<BaseExtension> load_extension(std::string &name) override;

    std::shared_ptr<BaseExtension> load_extension(std::string &name, std::string &arg) override;

    void unload_extension(std::string &name) override;

    ~ExtensionLoader();

protected:
    std::string resolve_name(std::string &name);

    void *open_handle(std::string &name);

    static std::shared_ptr<BaseExtension> make_extension(ExtensionCreator *creator, ExtensionDeleter *deleter, std::string &arg);

private:
    std::vector<std::string> extension_paths;
    std::map<std::string, void *> handles;
};


#endif //PROFCONT_EXTENSION_LOADER_HPP
