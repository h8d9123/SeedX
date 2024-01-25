#include <iostream>
#include "SDL2/SDL.h"
#include "SXCommon.h"
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

void drawBmp(SDLRender& renderer, SXTexture &texture)
{
    renderer.Copy(texture, nullptr, nullptr);
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
    // start sdl
    SDL_Init(SDL_INIT_EVERYTHING);

    SXWindow win("SeedX:Everything is possible!", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
    SDLRender renderer(win);

    SXSurface surface("hello.bmp");
    SXTexture texture(renderer, surface);
    
    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {

        while (SDL_PollEvent(&e))
        {
            drawBackGound(renderer);
            drawBmp(renderer, texture);
            drawLine(renderer);
            drawCircle(renderer);
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEMOTION:
                SDL_LogInfo(SDL_LOG_CATEGORY_TEST, "mouse_pos=(%d, %d)\n", e.motion.x, e.motion.y);
                drawRectFllowMouse(renderer, e.motion.x, e.motion.y);
                break;
            default:
                break;
            }
            renderer.Present();
        }
        
    }
    

    // quit sdl
    SDL_Quit();
    return 0;
}