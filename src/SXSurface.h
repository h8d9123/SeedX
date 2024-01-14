#ifndef SXSURFACE_H
#define SXSURFACE_H
#include "SXBasic.h"
#include <iostream>

sx_namespace_begin

class SXSurface
{
public:
    virtual void* Get() { return nullptr;};
};

class SDLSurface : public SXSurface
{
public:
    SDLSurface(const std::string & file);
    virtual void* Get() override {return surface;}
    virtual ~SDLSurface();
public:
    SDL_Surface *surface;

};

sx_namespace_end

#endif