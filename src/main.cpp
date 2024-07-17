#include <iostream>
#include <vector>
#include <algorithm>

#include "SXCommon.h"
#include "SXLabel.h"


#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

using namespace sx;

void drawBackGound(SDLRender& renderer)
{
    renderer.Clear();
    renderer.SetDrawColor(0xff, 0xff, 0xff, 0xff);
    Rect r{0, 0, SCREEN_WIDTH,SCREEN_HEIGHT};
    renderer.FillRect(r);
}

void drawRectFllowMouse(SDLRender& renderer, int x, int y)
{
    renderer.SetDrawColor(0xff, 0x00, 0x00, 0xff);
    Rect r(x, y, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8);
    renderer.FillRect(r);
}

void drawLine(SDLRender& renderer)
{
    renderer.SetDrawColor(0x00, 0x00, 0xff, 0xff);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4)
    {
        renderer.DrawPoint(Point(SCREEN_WIDTH / 2, i));
    }
}

void drawCircle(SDLRender& renderer)
{
    Circle c{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20};
    renderer.SetDrawColor(0x00, 0x23, 0xff, 0xff);
    renderer.DrawCircle(c);
}

int main(int argc, char* argv[])
{
    SXLogSetPriority(SDL_LOG_PRIORITY_VERBOSE);
    // start sdl
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SXLogError("SDL_Init fail %s!\n", SDL_GetError());
    }
    if (TTF_Init() < 0) {
        SXLogError("TTF_Init fail! %s\n", SDL_GetError());
    }
    
    SXWidget top_window(nullptr);
    SXLabel* label= new SXLabel(&top_window);
    label->SetText("hello world");

    SXLabel* label2= new SXLabel(&top_window);
    label2->x() = 0;
    label2->y() = 25;
    label2->SetText("second label");

    SXWindow win("SeedX:Everything is possible!", 0,0,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // SXWindow win1("SeedX:Everything is possible!", 10,0,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
    std::vector<SXWindow*> winManger;
    winManger.push_back(&win);
    // winManger.push_back(&win1);

    SDLRender* renderer = win.GetRender();

    SXBMPSurface surface("hello.bmp");
    SXTexture texture(*renderer, surface);
    
    SXTextSurface text("Hello"); 
    SXTexture texture2(*renderer, text);
    
    Rect text_pos;
    text.GetClipRect(text_pos);
    text_pos.x = 200;
    text_pos.y = 200;
    
    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {

        while (SDL_PollEvent(&e))
        {
            // win.HandleEvent(e);
            // win1.HandleEvent(e);
            // win2.HandleEvent(e);
            drawBackGound(*renderer);
            renderer->Copy(texture, NULL, NULL);
            renderer->Copy(texture2, NULL, &text_pos);
            // renderer->Copy(texture2, NULL, &text_pos);
            // drawLine(renderer);
            // drawCircle(renderer);
            switch (e.type)
            {
            case SDL_QUIT:
                SDL_LogInfo(SDL_LOG_CATEGORY_TEST, "quit!\n");
                quit = true;
                break;
            // case SDL_MOUSEMOTION:
            //     SDL_LogInfo(SDL_LOG_CATEGORY_TEST, "mouse_pos=(%d, %d)\n", e.motion.x, e.motion.y);
            //     drawRectFllowMouse(*renderer, e.motion.x, e.motion.y);
            //     break;
            default:
                break;
            }
            top_window.Show();
            win.ShowWindow();
            win.Focus();
            win.RenderPresent();
            if(std::all_of(winManger.begin(), winManger.end(), [](SXWindow* w) { return !w->isShown(); })) {
                quit = true;
                break;
            }
        }
        
    }
    
    // quit sdl
    SDL_Quit();
    return 0;
}