#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

using namespace std;

bool init();
bool loadMedia();
void close();

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gImage = NULL;

bool init() {
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Uninitiated. SDL_Error: " << SDL_GetError();
        success = false;
    }

    else {
        gWindow = SDL_CreateWindow("SDL ki Jai!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

        if (gWindow == NULL) {
            cout << "Window Uninitiated. SDL_Error: " << SDL_GetError();
            success = false;
        }

        else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        };
    };

    return success;
};

bool loadMedia() {
    bool success = true;

    gImage = SDL_LoadBMP("/home/ekansh/Code::Blocks/SDL Tutorials/SDL2/hello_world.bmp");

    if (gImage == NULL) {
        cout << "Error loading image. SDL_Error: " << SDL_GetError();
        success = false;
    };

    return success;
};

void close() {
    SDL_FreeSurface (gImage);
    gImage = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

int main(int argc, char* args[]) {
    if ( init() ) {
        loadMedia();

        bool quit = false;
        SDL_Event e;

        while (!quit) {
            while(SDL_PollEvent(&e) != 0) {
                if ((e).type == SDL_QUIT) {
                    quit = true;
                };
            };

            //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x6F, 0x52, 0x41));
            SDL_BlitSurface (gImage, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface (gWindow);
        };
    };
};
