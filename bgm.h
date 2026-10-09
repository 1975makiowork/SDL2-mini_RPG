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

typedef enum
{
    SE_CURSOR,
    SE_CONFIRM,
    SE_CANSEL,
    SE_MENU,
    SE_STAIRS,
    SE_CHEST,
    SE_BOMB,
    SE_ROPE,
    SE_SLASH,
    SE_FIRE,
    SE_ICE,
    SE_THUNDER,
    SE_HEAL,
    SE_ENEMY_ATTACK,
    SE_TACKLE,
    SE_DRAIN,
    SE_BONE,
    SE_QUEKE,
    SE_STAB,
    SE_ESCAPE,
    SE_TIGHT,
    SE_STRONG_SLASH,
    SE_DRAGON_BREATH,
    SE_CHAGE_BREATH,
    SE_COUNT
} SEType;

int init_se(void);
void play_se(SEType type);
void quit_se(void);

#endif
