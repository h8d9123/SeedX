/*
@brief a label to show some text.
@author KiritoOvO
@time 2024-07-14
*/

#ifndef SXLABEL_H
#define SXLABEL_H
#include "SXCommon.h"
#include "SXWidget.h"
sx_namespace_begin

#define SXLABEL_DEFAULT_WIDTH 150
#define SXLABEL_DEFAULT_HEIGHT 20

class SXLabel : public SXWidget {
public:
    SXLabel(SXWidget* parent);
    virtual ~SXLabel() {};
    void SetText(const std::string &text);
    void Show() override;
private:
    void PreRender();
private:
    std::string text_;
    std::unique_ptr<SXTexture>texture_;
    Rect text_rect_;
};

sx_namespace_end


#endif