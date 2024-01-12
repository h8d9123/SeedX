
#ifndef SXBASIC_H
#define SXBASIC_H

#define sx_namespace_begin namespace sx {
#define sx_namespace_end }

#define DISABLE_COPY_AND_MOVE(class_name) \
    class_name(const class_name &)=delete; \
    class_name(const class_name &&)=delete; \
    class_name & operator=(const class_name &)=delete; \
    class_name & operator=(const class_name &&)=delete;

#include "SDL2/SDL.h"
#endif

