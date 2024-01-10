#include "SXShape.h"
sx_namespace_begin

Rect::Rect(int x, int y, int w, int h):rect_{x, y, w, h}
{
}

bool Rect::IsEmpty()
{
    return SDL_RectEmpty(&rect_);
}

bool Rect::IsEqual(const Rect &other)
{
    return SDL_RectEquals(&rect_, &other.rect_);
}

bool Rect::Contains(const Point & p)
{
    return SDL_PointInRect(&p, &rect_);
}

bool Rect::Contains(int x, int y)
{
    Point p{x, y};
    return Contains(p);
}

bool Rect::Contains(const Rect &other)
{
    const auto& r = other.rect_;
    return (Contains(r.x, r.y) && 
            Contains(r.x + r.w, r.y + r.h));
}

bool Rect::Intersect(const Rect& other)
{
    return SDL_HasIntersection(&rect_, &other.rect_);
}

bool Rect::Intersect(const Rect &other, Rect& result)
{
    return SDL_IntersectRect(&rect_, &other.rect_, &result.rect_);
}

bool Rect::Intersect(const LineSegment &other, LineSegment &result)
{
    result = other;
    return SDL_IntersectRectAndLine(&rect_, 
        &result.p1.x, &result.p1.y,
        &result.p2.x, &result.p2.y);
}
void Rect::Union(const Rect &other, Rect& result)
{
    SDL_UnionRect(&rect_, &other.rect_, &result.rect_);
}
sx_namespace_end