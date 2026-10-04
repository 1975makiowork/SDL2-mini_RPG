// bgm.c
#include <stdio.h>
#include "bgm.h"

static Mix_Music *bgm_list[10] = {NULL};
static BGMType current_bgm = -1;
static BGMType area_bgm = BGM_FIELD;

int init_bgm(void)
{
    bgm_list[BGM_TITLE] =
        Mix_LoadMUS("bgm/title.ogg");

    bgm_list[BGM_FIELD] =
        Mix_LoadMUS("bgm/field.ogg");

    bgm_list[BGM_TOWN] =
        Mix_LoadMUS("bgm/town.ogg");

    bgm_list[BGM_CAVE] =
        Mix_LoadMUS("bgm/cave.ogg");

    bgm_list[BGM_CAVE_B1] =
        Mix_LoadMUS("bgm/cave_b1.ogg");

    bgm_list[BGM_CAVE_B2] =
        Mix_LoadMUS("bgm/cave_b2.ogg");

    bgm_list[BGM_TEMPLE] =
        Mix_LoadMUS("bgm/temple.ogg");

    bgm_list[BGM_BATTLE] =
        Mix_LoadMUS("bgm/battle.ogg");

    bgm_list[BGM_BOSS] =
        Mix_LoadMUS("bgm/boss.ogg");

    bgm_list[BGM_GAMEOVER] =
        Mix_LoadMUS("bgm/gameover.ogg");

    for (int i = 0; i < 10; i++)
    {
        if (bgm_list[i] == NULL)
        {
            fprintf(stderr,
                    "BGM load error: %d: %s\n",
                    i,
                    Mix_GetError());

            return 0;
        }
    }

    return 1;
}

void play_bgm(BGMType type)
{
    if (type == current_bgm)
    {
        return;
    }

    if (bgm_list[type] == NULL)
    {
        return;
    }

    Mix_PlayMusic(bgm_list[type], -1);
    current_bgm = type;
}

void stop_bgm(void)
{
    Mix_HaltMusic();
    current_bgm = -1;
}

void quit_bgm(void)
{
    Mix_HaltMusic();

    for (int i = 0; i < 10; i++)
    {
        if (bgm_list[i] != NULL)
        {
            Mix_FreeMusic(bgm_list[i]);
            bgm_list[i] = NULL;
        }
    }

    current_bgm = -1;
}

void set_area_bgm(BGMType type)
{
    area_bgm = type;
    play_bgm(area_bgm);
}

void end_battle_bgm(void)
{
    play_bgm(area_bgm);
}
