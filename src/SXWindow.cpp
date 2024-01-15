#include "SXWindow.h"
sx_namespace_begin

SXWindow::SXWindow(const std::string &title, int x, int y, int w, int h, uint32_t flags)
{
    window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
}

SXWindow::~SXWindow()
{
    SDL_DestroyWindow(window);
}

uint32_t SXWindow::GetWindowId()
{
    return SDL_GetWindowID(window);
}

void SXWindow::SetWindowTitle(std::string &title)
{
    SDL_SetWindowTitle(window, title.c_str());
}

std::string SXWindow::GetWindowTitle()
{
    return std::string(SDL_GetWindowTitle(window));
}

void SXWindow::SetWindowPosition(int x, int y)
{
    SDL_SetWindowPosition(window, x, y);
}

void SXWindow::GetWindowPosition(int &x, int & y)
{
    SDL_GetWindowPosition(window, &x, &y);
}

void SXWindow::SetWindowSize(int w, int h)
{
    SDL_SetWindowSize(window, w, h);
}

void SXWindow::GetWindowSize(int &w, int & h)
{
    SDL_GetWindowSize(window, &w, &h);
}

void SXWindow::SetWindowMinimumSize(int w, int h)
{
    SDL_SetWindowMinimumSize(window, w, h);
}

void SXWindow::GetWindowMinimumSize(int &w, int & h)
{
    SDL_GetWindowMinimumSize(window, &w, &h);
}

void SXWindow::SetWindowMaximumSize(int w, int h)
{
    SDL_SetWindowMaximumSize(window, w, h);
}

void SXWindow::GetWindowMaximumSize(int &w, int & h)
{
    SDL_GetWindowMaximumSize(window, &w, &h);
}

void SXWindow::SetWindowResizable(bool reisizable)
{
    SDL_SetWindowResizable(window, static_cast<SDL_bool>(reisizable));
}

void SXWindow::SetWindowAlwayOnTop(bool on_top)
{
    SDL_SetWindowAlwaysOnTop(window, static_cast<SDL_bool>(on_top));
}

void SXWindow::ShowWindow()
{
    SDL_ShowWindow(window);
}

void SXWindow::HideWindow()
{
    SDL_HideWindow(window);
}

void SXWindow::RaiseWindow()
{
    SDL_RaiseWindow(window);
}

void SXWindow::MaximizeWindow()
{
    SDL_MaximizeWindow(window);
}

void SXWindow::MinimizeWindow()
{
    SDL_MinimizeWindow(window);
}

void SXWindow::RestoreWindow()
{
    SDL_RestoreWindow(window);
}

void SXWindow::SetFullscreen(uint32_t flags)
{
    SDL_SetWindowFullscreen(window, flags);
}

sx_namespace_end