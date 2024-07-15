#include "SXSurface.h"
#include "SXLog.h"
sx_namespace_begin

bool SXSurface::SetClipRect(const Rect &rect)
{
    return SDL_SetClipRect(surface_, reinterpret_cast<const SDL_Rect *>(&rect));
}

void SXSurface::GetClipRect(Rect& rect)
{
    SDL_GetClipRect(surface_, reinterpret_cast<SDL_Rect *>(&rect));
}

sx_namespace_end