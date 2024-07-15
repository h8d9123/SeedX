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
    renderer->Clear();
    uint8_t r,g,b,a;
    renderer->GetDrawColor(r, g, b, a);
    renderer->SetDrawColor(0xff, 0xff, 0xff, 0xff);
    Rect rect{0, 0, 800,600};
    renderer->FillRect(rect);
    renderer->SetDrawColor(r, g, b, a);
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

SXLabel::SXLabel(SXWidget* parent):SXWidget(parent)
{

}

void SXLabel::SetText(const std::string &text)
{
    text_ = text;
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
    Rect border;
    text_surface.GetClipRect(border);
    w() = border.w;
    h() = border.h;
}

void SXLabel::Show()
{
    if (!GetParent()) {
        SXLogError("parent_ is nullptr!\n");
        return;
    }
    PreRender();
    Rect r{x(), y(), w(), h()};
    auto renderer = GetParent()->GetRenderer();

    renderer->Copy(*texture_, NULL, &r);
}


sx_namespace_end