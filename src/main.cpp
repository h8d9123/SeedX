#include <iostream>
#include "SDL2/SDL.h"
#include "SXShape.h"
#include "SXRender.h"
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

using namespace sx;

int main(int argc, char* argv[])
{
    // start sdl
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = NULL;
    win = SDL_CreateWindow("SeedX:Everything is possible!", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT, 0);

    SDLRender renderer(win);

    renderer.SetDrawColor(0xff, 0x00, 0x00, 0xff);
    Rect r(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
    renderer.DrawRect(r);
    renderer.SetDrawColor(0xff, 0x00, 0xff, 0xff);
    for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
    {
        renderer.DrawPoint(Point(SCREEN_WIDTH / 2, i));
    }
    renderer.Present();
    // SDL_Texture *HelloTex = NULL;
    // SDL_Surface *Surface = NULL;

    // Surface = SDL_LoadBMP("hello.bmp");
    // HelloTex = SDL_CreateTextureFromSurface(renderer, Surface);
    // SDL_FreeSurface(Surface);
    // SDL_RenderClear(renderer);
    // SDL_RenderCopy(renderer, HelloTex, NULL, NULL);

    SDL_Delay(2000);
    // SDL_DestroyTexture(HelloTex);

    SDL_DestroyWindow(win);
    // quit sdl
    SDL_Quit();
    return 0;
}