/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Core
*/

#include <dlfcn.h>
#include "../include/Core.hpp"

Core::Core()
{}

Core::~Core()
{}

int Core::Game(std::string name)
{
    getALlLibrairi();

    /*
    this->lib.libone = getLibrary(name);

    if (!verifIfIsLibrary(this->lib.libone)) {
        return (84);
    }
    void *createLibrari = dlsym(this->lib.libone, "createLib");
    auto  librari = ((LIB::ILibrari *(*)()) createLibrari)();
    std::shared_ptr<LIB::ILibrari> Ilib(librari, &destructorlib);
    this->library = std::move(Ilib);
    */
    return (0);
}

static int explore( const char *fpath,
                    const struct stat *sb,
                    int typeflag )
{
    std::cout << "coucou" << std::endl;
    if (typeflag == FTW_F) {
        if (fnmatch("*.so", fpath, FNM_CASEFOLD) == 0) {
            std::cout << "found txt file: " << fpath << std::endl;
        }
    }
    return 0;
}


void Core::getALlLibrairi()
{
    ftw(".", explore, 1);
    /*
    std::vector<std::string> file;

    DIR *dir = opendir("./");

    std::cout << "segfault " << std::endl;

    if (dir == nullptr) {
        this->exit = 84;
        return;
    }

    struct dirent *diread = readdir(dir);

    std::cout << "segfault " << std::endl;
    std::string filename = nullptr;

    while (diread != nullptr) {
        filename = diread->d_name;
        if (filename != "." && filename != ".." && filename.substr(filename.find('.') + 1, filename.length()) == "so") {
            file.push_back(filename);
            std::cout << filename << std::endl;
            diread = readdir(dir);
        }
        closedir(dir);
    }
    */
}

void destructorlib(LIB::ILibrari *lib)
{
    (void)lib;
}

bool Core::verifIfIsLibrary(void *lib)
{
   return (dlsym(lib, "createLib") != nullptr && dlsym(lib, "destroyLib") != nullptr);
}

void *Core::getLibrary(std::string &name)
{
    void *library = dlopen(name.c_str(), RTLD_NOW);

    if (library == nullptr) {
        this->exit = 64;
        return (nullptr);
    }
    dlerror();
    return (library);
}

void Core::closeLibrary()
{
}

int Core::getExit() const
{
    return (this->exit);
}

void Core::helper()
{
    std::cout << "./arcade lib.so" << std::endl;
    std::cout << "Description:\nUse a library to start a programme must be in directory lib/" << std::endl;
}
