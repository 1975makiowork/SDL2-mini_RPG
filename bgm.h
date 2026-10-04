// bgm.h
#ifndef BGM_H
#define BGM_H

#include <SDL2/SDL_mixer.h>

typedef enum
{
    BGM_TITLE,
    BGM_FIELD,
    BGM_TOWN,
    BGM_CAVE,
    BGM_CAVE_B1,
    BGM_CAVE_B2,
    BGM_TEMPLE,
    BGM_BATTLE,
    BGM_BOSS,
    BGM_GAMEOVER
} BGMType;

int init_bgm(void);
void play_bgm(BGMType type);
void stop_bgm(void);
void quit_bgm(void);
void set_area_bgm(BGMType type);
void end_battle_bgm(void);

#endif
