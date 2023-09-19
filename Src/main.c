//
// Created by clovis on 18/09/23.
//

#include <stdio.h>

#include <emscripten.h>
#include <SDL/SDL.h>

static void mainloop();

SDL_Window *win;
SDL_Renderer *ren;

int main()
{
    printf("Hello world!\n");

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Fail: %s\n", SDL_GetError());
    }
    else
    {
        printf("SDL initialized\n");
    }

    printf("l 22\n");

    win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (win == NULL)
    {
        printf("Fail: %s\n", SDL_GetError());
    }
    else
    {
        printf("Window created\n");
    }

    ren = SDL_CreateRenderer(win, -1, 0);

    if (ren == NULL)
    {
        printf("Fail: %s\n", SDL_GetError());
    }
    else
    {
        printf("Renderer created\n");
    }

    emscripten_set_main_loop(mainloop, 0, 1);

    return 0;
}

static void mainloop()
{
    int quit = 0;
    int i = 0;

    SDL_Rect testRect = {100, 100, 100, 100};
    SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
    SDL_RenderFillRect(ren, &testRect);
    SDL_RenderPresent(ren);

    SDL_Delay(10);

    i++;

    if (i == 100)
    {
        quit = 1;
    }

    if (quit)
    {
        printf("Quitting\n");

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();

        exit(0);
    }
}