// temple.c
#include <stdio.h>
#include <stdbool.h>

#include "temple.h"
#include "battle.h"
#include "magic.h"
#include "enemy.h"
#include "message_ui.h"

char temple_map[11][10] = {

    "MMMMMMMMM",
    "MMMMGMMMM",
    "MMMGGGMMM",
    "MMGGDGGMM",
    "MGGGGGGGM",
    "MGGGGGGGM",
    "MGNGGGGGM",
    "MMGGGGGMM",
    "MMMGGGMMM",
    "MMMMOMMMM",
    "MMMMMMMMM"
};

char get_temple_tile(int x, int y)
{
    return temple_map[y][x];
}

void temple_npc_event(void)
{
    show_message("龍神様は宝玉を持つ者に姿を表すという…");
}

void handle_temple_event(
    char tile,
    bool *in_temple,
    Player *player,
    int new_x,
    int new_y,
    BattleMode *battle_mode,
    int *battle_cursor,
    int *magic_cursor,
    int *use_item_cursor,
    Enemy *enemy,
    SDL_Texture **current_enemy_texture,
    SDL_Texture *dragon_texture
)
{
    if(tile == 'O')
    {
        *in_temple = false;

        player->x = 4;
        player->y = 11;

        show_message("神殿を出た！");
    }

    if(tile == 'N')
    {
        temple_npc_event();
    }

    if(tile == 'D')
    {
        if(player->dragon_defeated)
        {
            show_message("竜神はどこかへ去ったようだ");
        }
        else if(player->inventory.dragon_jewel > 0)
        {
            start_boss_battle(
                battle_mode,
                battle_cursor,
                magic_cursor,
                use_item_cursor,
                enemy,
                current_enemy_texture,
                dragon_texture,
                player,
                new_x,
                new_y
            );
        }
        else
        {
            show_message("巨大な龍の石像がある");
        }
    }
}
