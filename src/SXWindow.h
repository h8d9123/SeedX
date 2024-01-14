#ifndef SXWINDOW_H
#define SXWINDOW_H
#include "SXBasic.h"
#include <iostream>

sx_namespace_begin

class SXWindow
{
public:
    SXWindow(const std::string & title, int x, int y, int w, int h, uint32_t flags);
    virtual ~SXWindow();
    
    // del?
    void* Get() {return window;}
    DISABLE_COPY_AND_MOVE(SXWindow)
private:
    SDL_Window *window;
};

sx_namespace_end

#endif