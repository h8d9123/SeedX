#ifndef SXWINDOW_H
#define SXWINDOW_H
#include "SXBasic.h"
#include <iostream>

sx_namespace_begin

class Window
{
public:
    Window(const std::string & title, int x, int y, int w, int h, uint32_t flags);
    virtual ~Window();
    
    // del?
    SDL_Window * GetSDLWindow() {return window;}
    DISABLE_COPY_AND_MOVE(Window)
private:
    SDL_Window *window;
};

sx_namespace_end

#endif