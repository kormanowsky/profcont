//
// Created by Михаил on 19.10.2022.
//

#include "extension_loader.hpp"
#include <iostream>

ExtensionLoader::ExtensionLoader()
{
    std::string path = std::getenv("PATH");
    std::string::size_type colon_pos = path.find(':');
    if (colon_pos == std::string::npos)
    {
        this->extension_paths.emplace_back(path);
    }
    else
    {
        std::string::size_type prev_colon_pos = -1;
        do
        {
            this->extension_paths.emplace_back(
                path.substr(prev_colon_pos + 1, colon_pos - prev_colon_pos - 1)
            );
            prev_colon_pos = colon_pos;
            colon_pos = path.find(':', colon_pos + 1);
        } while (colon_pos != std::string::npos);
        this->extension_paths.emplace_back(path.substr(prev_colon_pos + 1));
    }
}

std::shared_ptr<BaseExtension> ExtensionLoader::load_extension(std::string &name, std::string &arg)
{
    auto handle = this->open_handle(name);
    auto *creator = (ExtensionCreator *) dlsym(handle, "extension_creator");
    auto *deleter = (ExtensionDeleter *) dlsym(handle, "extension_deleter");
    if (creator == nullptr || deleter == nullptr)
    {
        throw ProfContException("unable to load extension_creator, extension_deleter from extension " + name);
    }
    auto extension = ExtensionLoader::make_extension(creator, deleter, arg);
    if (extension == nullptr)
    {
        throw ProfContException("unable to load extension object from extension " + name);
    }
    return extension;
}

std::shared_ptr<BaseExtension> ExtensionLoader::load_extension(std::string &name)
{
    std::string empty_arg;
    return this->load_extension(name, empty_arg);
}

void ExtensionLoader::unload_extension(std::string &name)
{
    if (this->handles.count(name))
    {
        dlclose(this->handles[name]);
        this->handles.erase(name);
    }
}

std::string ExtensionLoader::resolve_name(std::string &name)
{
    std::string filename;
#if __APPLE__
    filename = "lib" + name + ".dylib";
#else
    filename = "lib" + name + ".so";
#endif
    for (auto &path: this->extension_paths)
    {
        auto lib_path = std::filesystem::path(path).append(filename);
        if (exists(lib_path))
        {
            return lib_path.string();
        }
    }
    return "";
}

void *ExtensionLoader::open_handle(std::string &name)
{
    if (this->handles.count(name))
    {
        return this->handles[name];
    }
    auto filename = this->resolve_name(name);
    auto handle = dlopen(filename.c_str(), RTLD_LAZY);
    if (!handle)
    {
        throw ProfContException("unable to open extension " + name);
    }
    this->handles[name] = handle;
    return handle;
}

std::shared_ptr<BaseExtension> ExtensionLoader::make_extension(
    ExtensionCreator *creator, ExtensionDeleter *deleter, std::string &arg)
{
    return {creator(arg), deleter};
}

ExtensionLoader::~ExtensionLoader()
{
    for (auto &item: this->handles)
    {
        dlclose(item.second);
    }
}