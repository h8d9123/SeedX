#include "SDL2/SDL.h"
#include "SXShape.h"
int main(int argc, char* argv[])
{
    // start sdl
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    win = SDL_CreateWindow("SeedX:Everything is possible!", 0,0,480,800, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *HelloTex = NULL;
    SDL_Surface *Surface = NULL;

    Surface = SDL_LoadBMP("hello.bmp");
    HelloTex = SDL_CreateTextureFromSurface(renderer, Surface);
    SDL_FreeSurface(Surface);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, HelloTex, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    SDL_DestroyTexture(HelloTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    // quit sdl
    SDL_Quit();
    return 0;
}