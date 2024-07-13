#include "SXBMPSurface.h"
#include "SXLog.h"
sx_namespace_begin

SXBMPSurface::SXBMPSurface(const std::string & file)
{
    surface_ = SDL_LoadBMP(file.c_str());
    if (surface_ == nullptr) {
        SXLogError("Faile to create surface %s\n", SXGetError());
    }
    // todo:use sdl_image load file
    // IMG_Load(file.c_str(), 1);
}

SXBMPSurface::~SXBMPSurface()
{
    if (surface_) {
        SDL_FreeSurface(surface_);
        surface_ = NULL;
    } 
}

sx_namespace_end