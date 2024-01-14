#ifndef SXRENDE_H
#define SXRENDE_H

#include "SXCommon.h"

sx_namespace_begin
class SXTexture;
class SXRender
{
public:
    virtual int DrawPoint(const Point &p) = 0;
    virtual int DrawLine(const LineSegment &seg) = 0;
    virtual int DrawRect(const Rect &rect) = 0;
    virtual int FillRect(const Rect &rect) = 0;
    virtual int Clear() = 0;
    virtual void Present() = 0;
    virtual int SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;
    virtual int GetDrawColor(uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) = 0;
    virtual void* Get() { return nullptr;}
    virtual int Copy(SXTexture& texture, const Rect *src, const Rect *dst)=0;
};

class SDLRender : public SXRender
{
public:
    SDLRender(SXWindow &window);
    virtual ~SDLRender();
    virtual int DrawPoint(const Point &p) override;
    virtual int DrawLine(const LineSegment &seg) override;
    virtual int DrawRect(const Rect &rect) override;
    virtual int FillRect(const Rect &rect) override;
    virtual int Clear() override;
    virtual void Present() override;
    virtual int SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;
    virtual int GetDrawColor(uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) override;
    void* Get() override {return renderer;}
    virtual int Copy(SXTexture& texture, const Rect *src, const Rect *dst) override;
    DISABLE_COPY_AND_MOVE(SDLRender)

private:
    SDL_Renderer *renderer;
};

// todo: add other render?
sx_namespace_end

#endif