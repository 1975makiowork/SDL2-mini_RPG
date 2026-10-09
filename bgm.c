// bgm.c
#include <stdio.h>
#include "bgm.h"

static Mix_Music *bgm_list[10] = {NULL};
static BGMType current_bgm = -1;
static BGMType area_bgm = BGM_FIELD;

static Mix_Chunk *se_list[SE_COUNT] = {NULL};

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

int init_se(void)
{
    se_list[SE_CURSOR] =
        Mix_LoadWAV("se/cursor.ogg");

    se_list[SE_CONFIRM] =
        Mix_LoadWAV("se/confirm.ogg");

    se_list[SE_CANSEL] =
        Mix_LoadWAV("se/cansel.ogg");

    se_list[SE_MENU] =
        Mix_LoadWAV("se/menu.ogg");

    se_list[SE_STAIRS] =
        Mix_LoadWAV("se/stairs.ogg");

    se_list[SE_CHEST] =
        Mix_LoadWAV("se/chest.ogg");

    se_list[SE_BOMB] =
        Mix_LoadWAV("se/bomb.ogg");

    se_list[SE_ROPE] =
        Mix_LoadWAV("se/rope.ogg");

    se_list[SE_FIRE] =
        Mix_LoadWAV("se/fire.ogg");

    se_list[SE_ICE] =
        Mix_LoadWAV("se/ice.ogg");

    se_list[SE_THUNDER] =
        Mix_LoadWAV("se/thunder.ogg");

    se_list[SE_HEAL] =
        Mix_LoadWAV("se/heal.ogg");

    se_list[SE_SLASH] =
        Mix_LoadWAV("se/slash.ogg");

    se_list[SE_ENEMY_ATTACK] =
        Mix_LoadWAV("se/enemy_attack.ogg");

    se_list[SE_TACKLE] =
        Mix_LoadWAV("se/tackle.ogg");

    se_list[SE_DRAIN] =
        Mix_LoadWAV("se/drain.ogg");

    se_list[SE_BONE] =
        Mix_LoadWAV("se/bone.ogg");

    se_list[SE_QUEKE] =
        Mix_LoadWAV("se/queke.ogg");

    se_list[SE_STAB] =
        Mix_LoadWAV("se/stab.ogg");

    se_list[SE_TIGHT] =
        Mix_LoadWAV("se/tight.ogg");

    se_list[SE_ESCAPE] =
        Mix_LoadWAV("se/escape.ogg");

    se_list[SE_STRONG_SLASH] =
        Mix_LoadWAV("se/strong_slash.ogg");

    se_list[SE_DRAGON_BREATH] =
        Mix_LoadWAV("se/dragon_breath.ogg");

    se_list[SE_CHAGE_BREATH] =
        Mix_LoadWAV("se/chage_breath.ogg");

    for(int i = 0; i < SE_COUNT; i++)
    {
        if(se_list[i] == NULL)
        {
            fprintf(
                stderr,
                "SE load error: %d: %s\n",
                i,
                Mix_GetError()
            );

        return 0;
        }
    }

    return 1;
}

void play_se(SEType type)
{
    if(type < 0 || type >= SE_COUNT)
    {
        return;
    }

    if(se_list[type] == NULL)
    {
        return;
    }

    Mix_PlayChannel(-1, se_list[type], 0);
}

void quit_se(void)
{
    for(int i = 0; i < SE_COUNT; i++)
    {
        if(se_list[i] != NULL)
        {
            Mix_FreeChunk(se_list[i]);
            se_list[i] = NULL;
        }
    }
}

