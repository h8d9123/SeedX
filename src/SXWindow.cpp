#include "SXWindow.h"
sx_namespace_begin

Window::Window(const std::string &title, int x, int y, int w, int h, uint32_t flags)
{
    window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}
sx_namespace_end