#include "SXRender.h"
sx_namespace_begin

SDLRender::SDLRender(SXWindow *win):renderer(nullptr)
{
    if (win) {
        renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(win->Get()), -1, SDL_RENDERER_SOFTWARE);
        if (renderer == nullptr) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "renderer is null!");
        }
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "win is null!");
    }
    
}

SDLRender::~SDLRender()
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}

int SDLRender::DrawPoint(const Point &p)
{
    return SDL_RenderDrawPoint(renderer, p.x, p.y);
}

int SDLRender::DrawPoint(int x, int y)
{
    return SDL_RenderDrawPoint(renderer, x, y);
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

int SDLRender::DrawCircle(const Circle & circle)
{
    // https://en.wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example
    int cx = circle.x;
    int cy = circle.y;
    int r = circle.r;

    int x = r - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (circle.r << 1);
    int ret = 0;
    while (x >= y)
    {
        ret += DrawPoint(cx + x, cy + y);
        ret += DrawPoint(cx + y, cy + x);
        ret += DrawPoint(cx - y, cy + x);
        ret += DrawPoint(cx - x, cy + y);
        ret += DrawPoint(cx - x, cy - y);
        ret += DrawPoint(cx - y, cy - x);
        ret += DrawPoint(cx + y, cy - x);
        ret += DrawPoint(cx + x, cy - y);
        if (ret != 0)
        {
            return ret;
        }
        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        else
        {
            x--;
            dx += 2;
            err += dx - (r << 1);
        }
    }
    return ret;
}
sx_namespace_end