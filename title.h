// title.h
#ifndef TITLE_H
#define TITLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game_screen.h"

void handle_title_input(
    SDL_Event *event,
    GameScreen *screen
);

void draw_title(
    SDL_Renderer *renderer,
    TTF_Font *font,
    SDL_Texture *title_texture
);

void handle_game_over_input(
    SDL_Event *event,
    GameScreen *screen
);

void draw_game_over(
    SDL_Renderer *renderer,
    TTF_Font *font,
    SDL_Texture *gameover_texture
);

#endif
