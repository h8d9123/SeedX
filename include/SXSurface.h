#ifndef SXSURFACE_H
#define SXSURFACE_H

#include "SXBasic.h"
#include <iostream>

sx_namespace_begin

class SXSurface
{
public:
    virtual void* Get() {return surface_;}
protected:
    SDL_Surface *surface_;
};


sx_namespace_end

#endif