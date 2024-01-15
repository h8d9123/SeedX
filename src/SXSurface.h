#ifndef SXSURFACE_H
#define SXSURFACE_H
#include "SXBasic.h"
#include <iostream>

sx_namespace_begin

class SXSurface
{
public:
    SXSurface(const std::string & file);
    virtual void* Get() {return surface;}
    virtual ~SXSurface();
public:
    SDL_Surface *surface;

};

sx_namespace_end

#endif