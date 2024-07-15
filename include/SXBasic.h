
#ifndef SXBASIC_H
#define SXBASIC_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

#define sx_namespace_begin namespace sx {
#define sx_namespace_end }

#define DISABLE_COPY_AND_MOVE(class_name) \
    class_name(const class_name &)=delete; \
    class_name(const class_name &&)=delete; \
    class_name & operator=(const class_name &)=delete; \
    class_name & operator=(const class_name &&)=delete;

extern "C" {
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
}

#endif

