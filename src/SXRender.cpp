#include "SXRender.h"
sx_namespace_begin

SDLRender::SDLRender(SDL_Window *win) : window(win)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDLRender::~SDLRender()
{
    SDL_DestroyRenderer(renderer);
}

int SDLRender::DrawPoint(const Point &p)
{
    return SDL_RenderDrawPoint(renderer, p.x, p.y);
}

int SDLRender::DrawLine(const LineSegment &seg)
{
    return SDL_RenderDrawLine(renderer, seg.p1.x, seg.p1.y, seg.p2.x, seg.p2.y);
}

int SDLRender::DrawRect(const Rect &rect)
{
    return SDL_RenderDrawRect(renderer, reinterpret_cast<const SDL_Rect *>(&rect));
}

int SDLRender::FillRect(const Rect &rect)
{
    return SDL_RenderFillRect(renderer, reinterpret_cast<const SDL_Rect *>(&rect));
}

int SDLRender::Clear()
{
    return SDL_RenderClear(renderer);
}
void SDLRender::Present()
{
    SDL_RenderPresent(renderer);
}

int SDLRender::SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

int SDLRender::GetDrawColor(uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a)
{
    return SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
}

int SDLRender::Copy(SXTexture &texture, const Rect *src, const Rect *dst)
{
    return SDL_RenderCopy(renderer, static_cast<SDL_Texture*>(texture.Get()), 
        reinterpret_cast<const SDL_Rect *>(src), 
        reinterpret_cast<const SDL_Rect *>(dst));
}
sx_namespace_end