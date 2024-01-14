#include <iostream>
#include "SDL2/SDL.h"
#include "SXCommon.h"
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

using namespace sx;

int main(int argc, char* argv[])
{
    // start sdl
    SDL_Init(SDL_INIT_EVERYTHING);

    SXWindow win("SeedX:Everything is possible!", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
    SDLRender renderer(win.GetSDLWindow());

    SXSurface surface("hello.bmp");
    SXTexture texture(renderer, surface);
    renderer.Copy(texture, nullptr, nullptr);
    renderer.SetDrawColor(0xff, 0x00, 0x00, 0xff);
    Rect r(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    renderer.DrawRect(r);
    Rect r2(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8);
    renderer.FillRect(r2);
    renderer.SetDrawColor(0x00, 0x00, 0xff, 0xff);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4)
    {
        renderer.DrawPoint(Point(SCREEN_WIDTH / 2, i));
    }

    
    renderer.Present();

    SDL_Delay(2000);


    // quit sdl
    SDL_Quit();
    return 0;
}