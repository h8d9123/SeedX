#ifndef SXSURFACE_H
#define SXSURFACE_H

#include "SXBasic.h"
#include <iostream>
#include "SXShape.h"

sx_namespace_begin

class SXSurface
{
public:
    void* Get() {return surface_;}
    bool SetClipRect(const Rect &rect);
    void GetClipRect(Rect& rect);
protected:
    SDL_Surface *surface_;
};


sx_namespace_end

#endif