#ifndef SXShape_H
#define SXShape_H

#include "SXBasic.h"

sx_namespace_begin
/*
@ brief color=ALPHA:R:G:B
*/
enum class GMTRGB: uint32_t {
    RED         =0xFFFF0000,
    GREEN       =0xFF00FF00,
    BLUE        =0xFF0000FF,
    BLACK       =0xFF000000,
    WHITE       =0xFFFFFFFF,
    YELLOW      =0xFFFFFF00,
    CYAN        =0xFF00FFFF,
    MAGENTA     =0xFFFF00FF,
    LIGHTGRAY   =0xFFD3D3D3,
    SILVER      =0xFFC0C0C0,
    DARKGRAY    =0xFFA9A9A9,
    GRAY        = 0xFF808080,
};

struct Color {
    Color():Color(0U) {}
    Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) :r(_r),g(_g), b(_b), a(_a) {}
    Color(uint32_t color) { 
        b = color & 0xff; 
        g = (color >> 8) & 0xff;
        r = (color >> 16) & 0xff;
        a = (color >> 24) & 0xff;
    }
    Color(GMTRGB color): Color((uint32_t)color){ }
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

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
    Rect():x(0),y(0),w(0),h(0){};
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

struct Circle {
    Circle(int x_, int y_, int r_) : x(x_), y(y_), r(r_) {};
    int x,y;
    int r;
};
sx_namespace_end

#endif