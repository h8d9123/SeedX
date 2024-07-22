#ifndef SXWIDGET_H
#define SXWIDGET_H

#include "SXCommon.h"

sx_namespace_begin

class SXWidget {
public:
    SXWidget(SXWidget* parent);
    virtual ~SXWidget();
    SXRender* GetRenderer();
    SXWidget* GetParent() {return parent_;};
    Point Position() {return position_;};
    int32_t& x() {return position_.x;}
    int32_t& y() {return position_.y;}
    int32_t& w() {return w_;}
    int32_t& h() {return h_;}
    virtual void Show();

protected:
    bool addChild(SXWidget* child);
private:
    std::unique_ptr<SXWindow> top_window_;
    SXWidget *parent_;
    std::list<SXWidget*> children;
    int32_t w_, h_;
    Point position_;

    DISABLE_COPY_AND_MOVE(SXWidget)
};

sx_namespace_end

#endif