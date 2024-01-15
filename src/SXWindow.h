#ifndef SXWINDOW_H
#define SXWINDOW_H
#include "SXBasic.h"
#include <iostream>

sx_namespace_begin
/**
 * @brief SDL_video.h
*/
class SXWindow
{
public:
    SXWindow(const std::string & title, int x, int y, int w, int h, uint32_t flags);
    virtual ~SXWindow();
    void* Get() {return window;}
    uint32_t GetWindowId();
    void SetWindowTitle(std::string & title);
    std::string GetWindowTitle();
    void SetWindowPosition(int x, int y);
    void GetWindowPosition(int &x, int &y);
    void SetWindowSize(int w, int h);
    void GetWindowSize(int &w, int &h);
    void SetWindowMinimumSize(int w, int h);
    void GetWindowMinimumSize(int &w, int &h);
    void SetWindowMaximumSize(int w, int h);
    void GetWindowMaximumSize(int &w, int &h);
    void SetWindowResizable(bool reisizable);
    void SetWindowAlwayOnTop(bool on_top);
    void ShowWindow();
    void HideWindow();
    void RaiseWindow();
    void MaximizeWindow();
    void MinimizeWindow();
    void RestoreWindow();
    void SetFullscreen(uint32_t flags);

public:
    DISABLE_COPY_AND_MOVE(SXWindow)
    
private:
    SDL_Window *window;
};

sx_namespace_end

#endif