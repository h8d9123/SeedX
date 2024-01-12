#ifndef SXShape_H
#define SXShape_H

#include "SXBasic.h"

sx_namespace_begin

struct Point
{
    Point(int x_, int y_) : x(x_), y(y_){};
    int x, y;
};

struct LineSegment
{
    Point p1;
    Point p2;
};

struct Rect
{
    Rect(int x, int y, int w, int h);
    bool IsEmpty();
    bool IsEqual(const Rect &other);
    bool Contains(const Point &p);
    bool Contains(const Rect &other);
    bool Contains(int x, int y);
    bool Intersect(const Rect &other);
    bool Intersect(const Rect &other, Rect &result);
    bool Intersect(const LineSegment &other, LineSegment &result);
    void Union(const Rect &other, Rect &result);

    Point GetLeftTop() { return Point{x, y}; }
    Point GetRightDown() { return Point{x + w, y + h}; }
    void SetLeftTop(Point &p)
    {
        x = p.x;
        y = p.y;
    }
    void SetRightDown(Point &p)
    {
        w = p.x - x;
        h = p.y - y;
    }
    // operator SDL_Rect() const { return *reinterpret_cast<const SDL_Rect*>(this);}

    int x, y;
    int w, h;
};

sx_namespace_end

#endif