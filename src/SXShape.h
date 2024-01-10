#include "SXBasic.h"

sx_namespace_begin

using Point = SDL_Point;

struct LineSegment
{
    Point p1;
    Point p2;
};

class Rect
{
public:
    Rect(int x, int y, int w, int h);
    bool IsEmpty();
    bool IsEqual(const Rect &other);
    bool Contains(const Point &p);
    bool Contains(const Rect &other);
    bool Contains(int x, int y);
    bool Intersect(const Rect &other);
    bool Intersect(const Rect &other, Rect& result);
    bool Intersect(const LineSegment &other, LineSegment &result);
    void Union(const Rect &other, Rect& result);
protected:
    SDL_Rect rect_;
};

sx_namespace_end