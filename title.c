#include "title.h"
#include "render.h"

void handle_title_input(
    SDL_Event *event,
    GameScreen *screen
)
{
    if(event->key.keysym.sym == SDLK_RETURN)
    {
        *screen = SCREEN_PLAYING;
    }
}

void draw_title(
    SDL_Renderer *renderer,
    TTF_Font *font,
    SDL_Texture *title_texture
)
{
    SDL_SetRenderDrawColor(renderer, 10, 10, 40, 255);
    SDL_RenderClear(renderer);

    SDL_Rect dst = {
        0,
        10,
        720,
        540
    };

    SDL_RenderCopy(
        renderer,
        title_texture,
        NULL,
        &dst
    );

    draw_text(renderer, font, "Mini RPG", 300, 100);
    draw_text(renderer, font, "Enterで　はじめから", 240, 400);
}

void handle_game_over_input(
    SDL_Event *event,
    GameScreen *screen
)
{
    if(event->key.keysym.sym == SDLK_RETURN)
    {
        *screen = SCREEN_TITLE;
    }
}

void draw_game_over(
    SDL_Renderer *renderer,
    TTF_Font *font,
    SDL_Texture *gameover_texture
)
{
    SDL_SetRenderDrawColor(renderer, 40, 10, 10, 255);
    SDL_RenderClear(renderer);

    SDL_Rect dst = {
        0,
        10,
        720,
        540
    };

    SDL_RenderCopy(
        renderer,
        gameover_texture,
        NULL,
        &dst
    );

    draw_text(renderer, font, "GAME OVER", 280, 250);
    draw_text(renderer, font, "Enterで　タイトルへ", 240, 350);
}
