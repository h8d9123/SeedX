/*
@brief show text in sdl
@author KiritoOvO
@time 2024-07-13
*/
#ifndef SXTEXTSURFACE_H
#define SXTEXTSURFACE_H

#include "SXBasic.h"
#include "SXSurface.h"

sx_namespace_begin

class SXTextSurface : public SXSurface {
public:
    SXTextSurface(const std::string &text);
    virtual ~SXTextSurface();
private:
    TTF_Font* font_;
    std::string text_;
};
sx_namespace_end

#endif