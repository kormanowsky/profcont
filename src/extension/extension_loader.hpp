//
// Created by Михаил on 19.10.2022.
//

#ifndef PROFCONT_EXTENSION_LOADER_HPP
#define PROFCONT_EXTENSION_LOADER_HPP

#include <dlfcn.h>
#include <vector>
#include <utility>

#include "exception/prof_cont_exception.hpp"
#include "extension/base_extension_loader.hpp"

class ExtensionLoader : public BaseExtensionLoader
{
public:
    std::shared_ptr<BaseExtension> load_extension(std::string &name) override
    {
        auto filename = ExtensionLoader::resolve_name(name);
        auto handle = dlopen(filename.c_str(), RTLD_LAZY);
        if (!handle)
        {
            throw ProfContException("unable to open extension " + name);
        }
        auto *creator = (ExtensionCreator *) dlsym(handle, "extension_creator");
        auto *deleter = (ExtensionDeleter *) dlsym(handle, "extension_deleter");
        if (creator == nullptr || deleter == nullptr)
        {
            throw ProfContException("unable to load extension_creator, extension_deleter from extension " + name);
        }
        auto extension = std::shared_ptr<BaseExtension>(creator(), deleter);
        if (extension == nullptr)
        {
            throw ProfContException("unable to load extension object from extension " + name);
        }
        return extension;
    }

protected:
    static std::string resolve_name(std::string &name)
    {
        return "lib" + name + ".dylib";
    }
};


#endif //PROFCONT_EXTENSION_LOADER_HPP
