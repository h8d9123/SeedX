#ifndef SXTEXTURE_H
#define SXTEXTURE_H

#include "SXCommon.h"

sx_namespace_begin
class SXRender;
class SXTexture
{
public:
    SXTexture(SXRender &renderer, uint32_t format, int access, int w, int h);
    SXTexture(SXRender &renderer, SXSurface &surface);
    virtual ~SXTexture();
    void* Get() {return texture;}
private:
    SDL_Texture* texture;
};
sx_namespace_end

#endif
