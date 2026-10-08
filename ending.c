// ending.c
#include "ending.h"

#include <SDL2/SDL.h>

#define ENDING_START_Y 600.0f
#define ENDING_SCROLL_SPEED 20.0f
#define ENDING_WAIT_TIME 1000

typedef enum
{
    ENDING_SCROLL,
    ENDING_WAIT,
    ENDING_THE_END
} EndingPhase;

static float ending_scroll_y = ENDING_START_Y;
static Uint32 last_time = 0;

static EndingPhase ending_phase = ENDING_SCROLL;
static Uint32 ending_wait_start = 0;

void init_ending(void)
{
    ending_scroll_y = ENDING_START_Y;
    ending_phase = ENDING_SCROLL;
    ending_wait_start = 0;
    last_time = SDL_GetTicks();
}

void update_ending(void)
{
    Uint32 current_time = SDL_GetTicks();

    float delta_time =
        (current_time - last_time) / 1000.0f;

    last_time = current_time;

    if(ending_phase == ENDING_SCROLL)
    {
        ending_scroll_y -=
            ENDING_SCROLL_SPEED * delta_time;

        if(ending_scroll_y < -700.0f)
        {
            ending_scroll_y = -700.0f;
            ending_phase = ENDING_WAIT;
            ending_wait_start = current_time;
        }
    }
    else if(ending_phase == ENDING_WAIT)
    {
        if(current_time - ending_wait_start
            >= ENDING_WAIT_TIME)
        {
            ending_phase = ENDING_THE_END;
        }
    }
}

float get_ending_scroll_y(void)
{
    return ending_scroll_y;
}

bool is_ending_the_end(void)
{
    return ending_phase == ENDING_THE_END;
}

void handle_ending_input(
    SDL_Event *event,
    GameScreen *screen
)
{
    if(!is_ending_the_end())
    {
        return;
    }

    if(event->type == SDL_KEYDOWN)
    {
        *screen = SCREEN_TITLE;
    }
}

