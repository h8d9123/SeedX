#include "SXTextSurface.h"
#include "SXLog.h"

sx_namespace_begin
SXTextSurface::SXTextSurface(const std::string &text):text_(text)
{
    surface_ = nullptr;
    SDL_Color textColor={0, 0, 0, 0xff};
    auto font= TTF_OpenFont( "./SimSun.ttf", 16 );
    if (font == nullptr) {
        SXLogError("Fail to create font %s\n", SXGetError());
        return;
    }
    surface_ = TTF_RenderText_Solid(font, text_.c_str(), textColor);
    if (surface_ == nullptr) {
        SXLogError("Fail to render text %s\n", SXGetError());
        return;
    }
    TTF_CloseFont(font);
}

SXTextSurface::SXTextSurface(const std::string &text, uint32_t font_size, const Color&  color):text_(text)
{
    surface_ = nullptr;
    auto font= TTF_OpenFont( "./SimSun.ttf", font_size);
    if (font == nullptr) {
        SXLogError("Fail to create font %s\n", SXGetError());
        return;
    }
    SDL_Color sdl_color {color.r, color.g, color.b, color.a}; 
    surface_ = TTF_RenderText_Solid(font, text_.c_str(), sdl_color);
    if (surface_ == nullptr) {
        SXLogError("Fail to render text %s\n", SXGetError());
        return;
    }
    TTF_CloseFont(font);
}

SXTextSurface::~SXTextSurface()
{
    if (surface_) {
        SDL_FreeSurface(surface_);
        surface_ = NULL;
    }
}
sx_namespace_end
