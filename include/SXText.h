/*
@brief show text in sdl
@author KiritoOvO
@time 2024-07-13
*/
#ifndef SXTEXT_H
#define SXTEXT_H

#include "SXBasic.h"
#include "SXSurface.h"

sx_namespace_begin

class SXText : public SXSurface {
public:
    SXText(const std::string &text);
    virtual ~SXText();
private:
    TTF_Font* font_;
    std::string text_;
};
sx_namespace_end

#endif