#ifndef SXRENDE_H
#define SXRENDE_H

#include "SXBasic.h"
#include "SXShape.h"

sx_namespace_begin
#define RectXYWH(r) r.x, r.y, r.w, r,h
class SXRender
{
public:
    virtual int DrawPoint(const Point& p) = 0;
    virtual int DrawLine(const LineSegment &seg) = 0;
    virtual int DrawRect(const Rect &rect) = 0;
    virtual int Clear() = 0;
    virtual void Present() = 0;
    virtual int SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;
};

class SDLRender : public SXRender
{
public:
    SDLRender(SDL_Window* window);
    ~SDLRender();
    virtual int DrawPoint(const Point& p) override;
    virtual int DrawLine(const LineSegment &seg) override;
    virtual int DrawRect(const Rect &rect) override;
    virtual int Clear() override;
    virtual void Present() override;
    virtual int SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;

private:
    SDL_Renderer *renderer;
    SDL_Window * window;
};
sx_namespace_end

#endif