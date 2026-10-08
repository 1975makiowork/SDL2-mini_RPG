// ending.h
#ifndef ENDING_H
#define ENDING_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "title.h"

void init_ending(void);

void update_ending(void);

float get_ending_scroll_y(void);

bool is_ending_the_end(void);

void draw_ending(
    SDL_Renderer *renderer,
    TTF_Font *font,
    SDL_Texture *ending_texture
);

void handle_ending_input(
    SDL_Event *event,
    GameScreen *screen
);

#endif
