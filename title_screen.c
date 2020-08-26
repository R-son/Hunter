/*
** EPITECH PROJECT, 2019
** title_screen
** File description:
** Manages title screen
*/

#include "include/my.h"

void destroy(struct game title, sfRenderWindow *w)
{
    sfSprite_destroy(title.sprite);
    sfTexture_destroy(title.t);
    sfMusic_destroy(title.music);
}

void display_title(struct game title)
{
    sfVector2f Boo;
    sfVector2i test;

    Boo.x = 0;
    Boo.y = 770;
    test = sfMouse_getPositionRenderWindow(title.w);
    sfRenderWindow_display(title.w);
    sfSprite_setPosition(title.Start, Boo);
    sfRenderWindow_drawSprite(title.w, title.sprite, NULL);
    sfRenderWindow_drawSprite(title.w, title.Start, NULL);
    sfSprite_setTextureRect(title.Start, title.rect);
    if ((Boo.x <= test.x && test.x <= Boo.x + 1023) && 
        (Boo.y <= test.y && test.y <= Boo.y + 264)) {
            title.rect.top += 264;
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfMusic_stop(title.music);
                sfRenderWindow_clear(title.w, sfBlack);
                launch(title.w);
            }
    }
    sfSprite_setTextureRect(title.Start, title.rect);
}

struct game try(void)
{
    struct game ti;
    
    sfVideoMode m = {1920, 1080, 32};
    ti.w = sfRenderWindow_create(m, "SFML Window", sfDefaultStyle, NULL);
    ti.t = sfTexture_createFromFile("ressources/Title.png", NULL);
    ti.aim = sfTexture_createFromFile("ressources/Start.png", NULL);
    ti.sprite = sfSprite_create();
    ti.Start = sfSprite_create();
    sfSprite_setTexture(ti.Start, ti.aim, sfTrue);
    sfSprite_setTexture(ti.sprite, ti.t, sfTrue);
    ti.rect.top = 0;
    ti.rect.left = 0;
    ti.rect.width = 1023;
    ti.rect.height = 264;
    sfSprite_setTextureRect(ti.Start, ti.rect);
    ti.music = sfMusic_createFromFile("ressources/Title.ogg");
    return ti;
}

void title(void)
{
    struct game ti;

    ti = try();
    sfMusic_play(ti.music);
    while (sfRenderWindow_isOpen(ti.w)) {
        sfMusic_setLoop(ti.music, sfTrue);
        display_title(ti);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(ti.w);
    }
    destroy(ti, ti.w);
}
