#include "SXTexture.h"
sx_namespace_begin

SXTexture::SXTexture(SXRender &renderer, uint32_t format, int access, int w, int h)
{
    texture = SDL_CreateTexture(static_cast<SDL_Renderer*>(renderer.Get()), format, access, w, h);
}

SXTexture::SXTexture(SXRender &renderer, SXSurface &surface)
{
    texture = SDL_CreateTextureFromSurface(
        static_cast<SDL_Renderer*> (renderer.Get()),
        static_cast<SDL_Surface*> (surface.Get()));
}

SXTexture::~SXTexture()
{
    SDL_DestroyTexture(texture);
}

sx_namespace_end
