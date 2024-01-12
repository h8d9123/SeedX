#include "SXShape.h"
sx_namespace_begin

Rect::Rect(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_)
{
}

bool Rect::IsEmpty()
{
    return SDL_RectEmpty(reinterpret_cast<SDL_Rect *>(this));
}

bool Rect::IsEqual(const Rect &other)
{
    return SDL_RectEquals(reinterpret_cast<SDL_Rect *>(this),
                          reinterpret_cast<const SDL_Rect *>(&other));
}

bool Rect::Contains(const Point &p)
{
    return SDL_PointInRect(reinterpret_cast<const SDL_Point *>(&p),
                           reinterpret_cast<SDL_Rect *>(this));
}

bool Rect::Contains(int x, int y)
{
    Point p{x, y};
    return Contains(p);
}

bool Rect::Contains(const Rect &other)
{
    const auto &r = other;
    return (Contains(r.x, r.y) &&
            Contains(r.x + r.w, r.y + r.h));
}

bool Rect::Intersect(const Rect &other)
{
    return SDL_HasIntersection(reinterpret_cast<SDL_Rect *>(this),
                               reinterpret_cast<const SDL_Rect *>(&other));
}

bool Rect::Intersect(const Rect &other, Rect &result)
{
    return SDL_IntersectRect(reinterpret_cast<SDL_Rect *>(this),
                             reinterpret_cast<const SDL_Rect *>(&other),
                             reinterpret_cast<SDL_Rect *>(&result));
}

bool Rect::Intersect(const LineSegment &other, LineSegment &result)
{
    result = other;
    return SDL_IntersectRectAndLine(reinterpret_cast<SDL_Rect *>(this),
                                    &result.p1.x, &result.p1.y,
                                    &result.p2.x, &result.p2.y);
}
void Rect::Union(const Rect &other, Rect &result)
{
    SDL_UnionRect(reinterpret_cast<SDL_Rect *>(this),
                  reinterpret_cast<const SDL_Rect *>(&other),
                  reinterpret_cast<SDL_Rect *>(&result));
}

sx_namespace_end