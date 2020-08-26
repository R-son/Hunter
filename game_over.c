/*
** EPITECH PROJECT, 2019
** game_over
** File description:
** Displays game over screen
*/

#include "include/my.h"

void display_over(struct game over, sfVector2f C, sfVector2f Q)
{
    sfVector2i test = sfMouse_getPositionRenderWindow(over.w);

    sfSprite_setPosition(over.Start, C);
    sfSprite_setPosition(over.Quit, Q);
    if ((C.x <= test.x && test.x <= C.x + 492) && 
        (C.y <= test.y && test.y <= C.y + 99)) {
            over.rect.top += 99;
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfMusic_stop(over.music);
                sfRenderWindow_clear(over.w, sfBlack);
                launch(over.w);
            }
    }
    if ((Q.x <= test.x && test.x <= Q.x + 260) && 
        (Q.y <= test.y && test.y <= Q.y + 99)) {
            over.rect2.top += 99;
            if (sfMouse_isButtonPressed(sfMouseLeft))
                sfRenderWindow_close(over.w);
    }
    sfSprite_setTextureRect(over.Start, over.rect);
    sfSprite_setTextureRect(over.Quit, over.rect2);
}

struct game end(sfRenderWindow *w)
{
    struct game over;

    over.w = w;
    over.t = sfTexture_createFromFile("ressources/game_over.png", NULL);
    over.sprite = sfSprite_create();
    sfSprite_setTexture(over.sprite, over.t, sfTrue);
    over.music = sfMusic_createFromFile("ressources/Game_over.ogg");
    sfMusic_play(over.music);
    over.rect.top = 0;
    over.rect.left = 0;
    over.rect.height = 99;
    over.rect.width = 492;
    over.rect2.top = 0;
    over.rect2.left = 0;
    over.rect2.height = 99;
    over.rect2.width = 260;
    return over;
}

struct game end2(struct game over)
{
    over.t2 = sfTexture_createFromFile("ressources/Continue.png", NULL);
    over.Start = sfSprite_create();
    over.t3 = sfTexture_createFromFile("ressources/Quit.png", NULL);
    over.Quit = sfSprite_create();
    sfSprite_setTexture(over.Start, over.t2, sfTrue);
    sfSprite_setTexture(over.Quit, over.t3, sfTrue);
    return over;
}

void game_over(sfRenderWindow *w)
{
    struct game over = end(w);
    sfVector2f C = {.x = 10, .y = 500};
    sfVector2f Q = {.x = 1650, .y = 500};

    over = end2(over);
    while (sfRenderWindow_isOpen(over.w)) {
        sfRenderWindow_setMouseCursorVisible(over.w, sfTrue);
        sfRenderWindow_display(over.w);
        sfMusic_setLoop(over.music, sfTrue);
        sfRenderWindow_drawSprite(over.w, over.sprite, NULL);
        sfRenderWindow_drawSprite(over.w, over.Start, NULL);
        sfRenderWindow_drawSprite(over.w, over.Quit, NULL);
        sfSprite_setTextureRect(over.Start, over.rect);
        sfSprite_setTextureRect(over.Quit, over.rect2);
        display_over(over, C, Q);
    }
    destroy(over, over.w);
}
