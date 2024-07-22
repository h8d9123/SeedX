#include "SXLabel.h"
sx_namespace_begin

SXLabel::SXLabel(SXWidget* parent):SXWidget(parent),texture_(nullptr)
{
    w() = SXLABEL_DEFAULT_WIDTH;
    h() = SXLABEL_DEFAULT_HEIGHT;
}

void SXLabel::SetText(const std::string &text)
{
    text_ = text;
    PreRender();
}

void SXLabel::PreRender()
{
    if (!GetParent()) {
        SXLogError("parent_ is nullptr!\n");
        return;
    }
    auto renderer = GetParent()->GetRenderer();
    if (!renderer) {
        SXLogError("renderer is nullptr!\n");
        return;
    }
    SXTextSurface text_surface(text_);
    texture_.reset(new SXTexture(*renderer, text_surface));
    text_surface.GetClipRect(text_rect_);
}

void SXLabel::Show()
{
    if (!GetParent()) {
        SXLogError("parent_ is nullptr!\n");
        return;
    }
    Rect r{x(), y(), w(), h()};
    auto renderer = GetParent()->GetRenderer();
    Color old;
    renderer->SetDrawColor(Color(GMTRGB::LIGHTGRAY));
    renderer->FillRect(r);
    
    if (texture_) {
        Rect text_dst_rect {x(), y(), text_rect_.w, text_rect_.h};
        renderer->Copy(*texture_, NULL, &text_dst_rect);
    }
        
}


sx_namespace_end