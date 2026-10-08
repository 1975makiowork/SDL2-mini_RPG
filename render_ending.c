//render_ending.c
#include "render.h"
#include "ending.h"

#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 560

void draw_ending(
    SDL_Renderer *renderer,
    TTF_Font *font,
    SDL_Texture *ending_texture
)
{
    SDL_Rect src = {
        110,
        0,
        1316,
        1024
    };

    SDL_Rect dst = {
        0,
        0,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    };

    SDL_RenderCopy(
        renderer,
        ending_texture,
        &src,
        &dst
    );

    SDL_SetRenderDrawBlendMode(
        renderer,
        SDL_BLENDMODE_BLEND
    );

    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        110
    );

    SDL_Rect overlay = {
        0,
        0,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    };

    SDL_RenderFillRect(
        renderer,
        &overlay
    );

    static const char *ending_text[] = {

        "あなたは龍神の試練を乗り越え",

        "",

        "勇者の称号を手にしました。",

        "",

        "島にとどまり町の平穏を見守る生涯を送るか",

        "",

        "島を出てまだ見ぬ人々や文化と出会い",

        "またそれらを脅かす脅威があれば撃退する",

        "新たな冒険の旅へ出るか……",

        "",

        "しばらく考えましたが",

        "あなたは冒険の旅に出る決心をします。",

        "",

        "あなたの新たな旅路に幸あらんことを＿",
    };

    const int line_count =
        sizeof(ending_text) / sizeof(ending_text[0]);

    int line_height = 40;

    float scroll_y =
        get_ending_scroll_y();

    for(int i = 0; i < line_count; i++)
    {
        if(ending_text[i][0] == '\0')
        {
                continue;
        }

        int y =
            (int)scroll_y + i *line_height;

        if(y < -40 || y > SCREEN_HEIGHT)
        {
            continue;
        }

        int text_width = 0;
        int text_height = 0;

        if(TTF_SizeUTF8(
            font,
            ending_text[i],
            &text_width,
            &text_height
        ) != 0)
        {
            continue;
        }

        int x =
            (SCREEN_WIDTH - text_width) / 2;

        draw_text(
            renderer,
            font,
            ending_text[i],
            x,
            y
        );
    }

    if(is_ending_the_end())
    {
        const char *text = "THE END";

        int text_width = 0;
        int text_height = 0;

        TTF_SizeUTF8(
            font,
            text,
            &text_width,
            &text_height
        );

        int x =
            (SCREEN_WIDTH - text_width) / 2;

        int y =
            (SCREEN_HEIGHT - text_height) / 2;

        draw_text(
            renderer,
            font,
            text,
            x,
            y
        );
    }
}

