#include "SXText.h"
#include "SXLog.h"

sx_namespace_begin
SXText::SXText(const std::string &text):text_(text)
{
    SDL_Color textColor={0, 0, 0, 0xff};
    font_= TTF_OpenFont( "./SimSun.ttf", 25 );
    if (font_ == nullptr) {
        SXLogError("Fail to create font %s\n", SXGetError());
    }
    surface_ = TTF_RenderText_Solid(font_, text_.c_str(), textColor);
    if (surface_ == nullptr) {
        SXLogError("Fail to render text %s\n", SXGetError());
    }
    TTF_CloseFont(font_);
}

SXText::~SXText()
{
    if (surface_) {
        SDL_FreeSurface(surface_);
        surface_ = NULL;
    }
}
sx_namespace_end
