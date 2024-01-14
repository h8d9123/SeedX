#include "SXSurface.h"

sx_namespace_begin

SXSurface::SXSurface(const std::string & file)
{
    surface = SDL_LoadBMP(file.c_str());
    // todo:use sdl_image load file
    // IMG_Load(file.c_str(), 1);
}

SXSurface::~SXSurface()
{
    SDL_FreeSurface(surface);
}

sx_namespace_end