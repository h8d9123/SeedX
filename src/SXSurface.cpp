#include "SXSurface.h"

sx_namespace_begin

SDLSurface::SDLSurface(const std::string & file)
{
    surface = SDL_LoadBMP(file.c_str());
    // todo:use sdl_image load file
    // IMG_Load(file.c_str(), 1);
}

SDLSurface::~SDLSurface()
{
    SDL_FreeSurface(surface);
}

sx_namespace_end