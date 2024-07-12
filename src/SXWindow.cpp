#include "SXWindow.h"
#include "SXRender.h"
sx_namespace_begin

SXWindow::SXWindow(const std::string &title, int x, int y, int w, int h, uint32_t flags):render_(nullptr)
{
    isShown_ = false;
    window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if (window_ != nullptr) {
        render_ = new SDLRender(this);
        if (render_ == nullptr) {
            SXLogError("%s", SDL_GetError());
        } else {
            isShown_ = true;
        }
    } else {
        SXLogError("%s", SDL_GetError());
    }
}

SXWindow::~SXWindow()
{
    if (render_) {
        delete render_;
        render_ = nullptr;
    }
    SDL_DestroyWindow(window_);

}

uint32_t SXWindow::GetWindowId()
{
    return SDL_GetWindowID(window_);
}

void SXWindow::SetWindowTitle(std::string &title)
{
    SDL_SetWindowTitle(window_, title.c_str());
}

std::string SXWindow::GetWindowTitle()
{
    return std::string(SDL_GetWindowTitle(window_));
}

void SXWindow::SetWindowPosition(int x, int y)
{
    SDL_SetWindowPosition(window_, x, y);
}

void SXWindow::GetWindowPosition(int &x, int & y)
{
    SDL_GetWindowPosition(window_, &x, &y);
}

void SXWindow::SetWindowSize(int w, int h)
{
    SDL_SetWindowSize(window_, w, h);
}

void SXWindow::GetWindowSize(int &w, int & h)
{
    SDL_GetWindowSize(window_, &w, &h);
}

void SXWindow::SetWindowMinimumSize(int w, int h)
{
    SDL_SetWindowMinimumSize(window_, w, h);
}

void SXWindow::GetWindowMinimumSize(int &w, int & h)
{
    SDL_GetWindowMinimumSize(window_, &w, &h);
}

void SXWindow::SetWindowMaximumSize(int w, int h)
{
    SDL_SetWindowMaximumSize(window_, w, h);
}

void SXWindow::GetWindowMaximumSize(int &w, int & h)
{
    SDL_GetWindowMaximumSize(window_, &w, &h);
}

void SXWindow::SetWindowResizable(bool reisizable)
{
    SDL_SetWindowResizable(window_, static_cast<SDL_bool>(reisizable));
}

void SXWindow::SetWindowAlwayOnTop(bool on_top)
{
    // SDL_SetWindowAlwaysOnTop(window_, static_cast<SDL_bool>(on_top));
}

void SXWindow::ShowWindow()
{
    SDL_ShowWindow(window_);
}

void SXWindow::HideWindow()
{
    SDL_HideWindow(window_);
}

void SXWindow::RaiseWindow()
{
    SDL_RaiseWindow(window_);
}

void SXWindow::MaximizeWindow()
{
    SDL_MaximizeWindow(window_);
}

void SXWindow::MinimizeWindow()
{
    SDL_MinimizeWindow(window_);
}

void SXWindow::RestoreWindow()
{
    SDL_RestoreWindow(window_);
}

void SXWindow::SetFullscreen(uint32_t flags)
{
    SDL_SetWindowFullscreen(window_, flags);
}

void SXWindow::HandleEvent(SDL_Event &e)
{
    if (e.type == SDL_WINDOWEVENT  && e.window.windowID == GetWindowId()) {
        switch (e.window.event)
        {
        case SDL_WINDOWEVENT_SHOWN:
            isShown_ = true;
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            isShown_ = false;
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            width_ = e.window.data1;
            height_ = e.window.data2;
            render_->Present();
            break;
        case SDL_WINDOWEVENT_ENTER:
            hasMouseFocus_ = true;
            break;
        case SDL_WINDOWEVENT_LEAVE:
            hasMouseFocus_ = false;
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            hasKeyBoardFocus_ = true;
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            hasKeyBoardFocus_ = false;
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            isMinimized_ = true;
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
            isMinimized_= false;
            break;
        case SDL_WINDOWEVENT_RESTORED:
            isMinimized_ = false;
        case SDL_WINDOWEVENT_CLOSE:
            HideWindow();
            break;
        default:
            break;
        }
        SXLogVerbose("Window=%u event=%u!\n", e.window.windowID, e.window.event);
    }
}
void SXWindow::Focus()
{
    if (!isShown_) {
        ShowWindow();
    }
    RaiseWindow();
}

void SXWindow::RenderPresent()
{
    if (!isMinimized_) {
        render_->Present();
    }
}

sx_namespace_end