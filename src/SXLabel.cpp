#include "SXLabel.h"
sx_namespace_begin

SXWidget::SXWidget(SXWidget* parent):position_(0,0)
{
    if (parent == nullptr) {
        top_window_.reset(new SXWindow("Test", 0,0,800, 600, SDL_WINDOW_SHOWN));
        parent_ = this;
        top_window_->GetWindowSize(w(), h());
    } else {
        parent_ = parent;
        parent->addChild(this);
    }
}

SXWidget::~SXWidget()
{
    for (auto w : children) {
        delete w;
    }
}

void SXWidget::Show()
{  
    auto renderer = GetRenderer();
    renderer->SetDrawColor(Color(GMTRGB::WHITE));
    renderer->Clear();
    if (top_window_) {
        // todo set topwindow show
    }
    
    for (auto w : children) {
        w->Show();
    };

    if (top_window_) {
        top_window_->ShowWindow();
        top_window_->RenderPresent();
    }
}

SXRender* SXWidget::GetRenderer()
{
    if (parent_ != this) {
        return parent_->GetRenderer();
    } else {
        return top_window_->GetRender();
    }
}
bool SXWidget::addChild(SXWidget* child) {
    if (!child) {
        return false;
    }
    auto iter = std::find(children.begin(), children.end(), child);
    if (iter == children.end()) {
        children.push_back(child);
    }
    return true;
}

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