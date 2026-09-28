#include "render.h"
#include "map.h"
#include "cave.h"
#include "cave_b1.h"
#include "cave_b2.h"
#include "temple.h"

#define TILE_SIZE 32

typedef struct
{
    int x;
    int y;
} ChestPosition;

static const ChestPosition field_chests[] = {
    {1, 2}
};

static const ChestPosition cave_chests[] = {
    {18, 5},
    {1, 8},
    {3, 8}
};

static const ChestPosition cave_b1_chests[] = {
    {5, 5},
    {11, 5},
    {17, 11}
};

static const ChestPosition cave_b2_chests[] = {
    {3, 3},
    {10, 3},
    {12, 7},
    {18, 13}
};

static void draw_chest_at(
    SDL_Renderer *renderer,
    SDL_Texture *texture,
    int x,
    int y
)
{
    SDL_Rect dst = {
        x * TILE_SIZE,
        y * TILE_SIZE,
        TILE_SIZE,
        TILE_SIZE
    };

    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void draw_tile_map(
    SDL_Renderer *renderer,
    const char *map,
    int stride,
    int draw_width,
    int height,
    const TileColor *colors,
    int color_count
)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < draw_width; x++)
        {
            char c = map[y * stride + x];

            TileColor found = {0, 255, 0, 255, 255};
            for (int i = 0; i < color_count; i++)
            {
                if (colors[i].tile == c)
                {
                    found = colors[i];
                    break;
                }
            }

            SDL_Rect rect = {
                x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE
            };

            SDL_SetRenderDrawColor(renderer, found.r, found.g, found.b, found.a);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void draw_map(SDL_Renderer *renderer, SDL_Texture *field_map_texture)
{
    SDL_Rect dst = {
        0, 0,
        640, 480
    };

    SDL_RenderCopy(renderer, field_map_texture, NULL, &dst);
}

void draw_town_map(SDL_Renderer *renderer, SDL_Texture *town_map_texture)
{
    SDL_Rect dst = {
        0, 0,
        224, 256
    };

    SDL_RenderCopy(renderer, town_map_texture, NULL, &dst);
}

void draw_cave_map(SDL_Renderer *renderer, SDL_Texture *cave_map_texture)
{
    SDL_Rect dst = {
        0, 0,
        640, 480
    };

    SDL_RenderCopy(renderer, cave_map_texture, NULL, &dst);
}

void draw_cave_b1_map(SDL_Renderer *renderer, SDL_Texture *cave_b1_map_texture)
{
    SDL_Rect dst = {
        0, 0,
        640, 480
    };

    SDL_RenderCopy(renderer, cave_b1_map_texture, NULL, &dst);
}

void draw_cave_b2_map(SDL_Renderer *renderer, SDL_Texture *cave_b2_map_texture)
{
    SDL_Rect dst = {
        0, 0,
        640, 480
    };

    SDL_RenderCopy(renderer, cave_b2_map_texture, NULL, &dst);
}

void draw_temple_map(SDL_Renderer *renderer, SDL_Texture *temple_map_texture)
{
    SDL_Rect dst = {
        0, 0,
        288, 352
    };

    SDL_RenderCopy(renderer, temple_map_texture, NULL, &dst);
}

void draw_field_chests(
    SDL_Renderer *renderer,
    char map[15][21],
    SDL_Texture *chest_closed_texture,
    SDL_Texture *chest_open_texture
)
{
    int count = sizeof(field_chests) / sizeof(field_chests[0]);

    for(int i = 0; i < count; i++)
    {
        int x = field_chests[i].x;
        int y = field_chests[i].y;

        if(map[y][x] == 'C')
        {
            draw_chest_at(
                renderer,
                chest_closed_texture,
                x,
                y
            );
        }
        else
        {
            draw_chest_at(
                renderer,
                chest_open_texture,
                x,
                y
            );
        }
    }
}

void draw_cave_chests(
    SDL_Renderer *renderer,
    char map[15][21],
    SDL_Texture *chest_closed_texture,
    SDL_Texture *chest_open_texture
)
{
    int count = sizeof(cave_chests) / sizeof(cave_chests[0]);

    for(int i = 0; i < count; i++)
    {
        int x = cave_chests[i].x;
        int y = cave_chests[i].y;

        if(map[y][x] == 'C')
        {
            draw_chest_at(
                renderer,
                chest_closed_texture,
                x,
                y
            );
        }
        else
        {
            draw_chest_at(
                renderer,
                chest_open_texture,
                x,
                y
            );
        }
    }
}

void draw_cave_b1_chests(
    SDL_Renderer *renderer,
    char map[15][21],
    SDL_Texture *chest_closed_texture,
    SDL_Texture *chest_open_texture
)
{
    int count = sizeof(cave_b1_chests) / sizeof(cave_b1_chests[0]);

    for(int i = 0; i < count; i++)
    {
        int x = cave_b1_chests[i].x;
        int y = cave_b1_chests[i].y;

        if(map[y][x] == 'C')
        {
            draw_chest_at(
                renderer,
                chest_closed_texture,
                x,
                y
            );
        }
        else
        {
            draw_chest_at(
                renderer,
                chest_open_texture,
                x,
                y
            );
        }
    }
}

void draw_cave_b2_chests(
    SDL_Renderer *renderer,
    char map[15][21],
    SDL_Texture *chest_closed_texture,
    SDL_Texture *chest_open_texture
)
{
    int count = sizeof(cave_b2_chests) / sizeof(cave_b2_chests[0]);

    for(int i = 0; i < count; i++)
    {
        int x = cave_b2_chests[i].x;
        int y = cave_b2_chests[i].y;

        if(map[y][x] == 'C')
        {
            draw_chest_at(
                renderer,
                chest_closed_texture,
                x,
                y
            );
        }
        else
        {
            draw_chest_at(
                renderer,
                chest_open_texture,
                x,
                y
            );
        }
    }
}

