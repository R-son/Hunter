/*
** EPITECH PROJECT, 2019
** launch_game
** File description:
** Launches the game
*/

#include "include/my.h"
#include <stdlib.h>
#include <time.h>

struct stats begin(struct stats status)
{
    status.life = 3;
    status.level = 1;
    status.points = 0;
    status.speed = 0.5;
}

struct stats display_game(struct stats data, struct game play, sfVector2f Boo)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(play.w);
    sfVector2f Target_pos = target_set(Target_pos, position);
    struct enemy ghost = {.boo_pos = sfSprite_getPosition(play.Quit)};
    sfVector2f left = {.x = data.speed, .y = 0};

    play.passed = sfClock_getElapsedTime(play.Temps);
    data.play = t(data, play, left, Target_pos);
    if (ghost.boo_pos.x > 2000) {
        srand (time(NULL));
        Boo = (sfVector2f){.x = -178, .y = rand() % 880};
        sfSprite_setPosition(play.Quit, Boo);
        data.life -= 1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        data = sho(play, ghost, position, data);
    return data;
}

struct game set(sfRenderWindow *w)
{
    struct game play;
    play.rect = (sfIntRect){0, 0, 178, 178};

    play.w = w;
    play.t = sfTexture_createFromFile("ressources/ground.png", NULL);
    play.sprite = sfSprite_create();
    sfSprite_setTexture(play.sprite, play.t, sfTrue);
    play.aim = sfTexture_createFromFile("ressources/Target.png", NULL);
    play.Target = sfSprite_create();
    sfSprite_setTexture(play.Target, play.aim, sfTrue);
    play.t2 = sfTexture_createFromFile("ressources/Boo.png", NULL);
    play.Quit = sfSprite_create();
    sfSprite_setTexture(play.Quit, play.t2, sfTrue);
    sfSprite_setTextureRect(play.Quit, play.rect);
    play.music = sfMusic_createFromFile("ressources/game.ogg");
    sfMusic_play(play.music);
    play.Temps = sfClock_create();
    return play;
}

void launch(sfRenderWindow *w)
{
    struct stats data = set_stats(data);
    sfVector2f Boo;

    data.play = set(w);   
    srand (time(NULL));
    Boo = (sfVector2f){.x = -178, .y = rand() % 880};
    sfSprite_setPosition(data.play.Quit, Boo);
    while (sfRenderWindow_isOpen(data.play.w)) {
        sfRenderWindow_setMouseCursorVisible(data.play.w, sfFalse);
        sfMusic_setLoop(data.play.music, sfTrue);
        data = display_game(data, data.play, Boo);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(data.play.w);
        if (data.life == 0) {
            sfMusic_stop(data.play.music);
            sfRenderWindow_clear(data.play.w, sfBlack);
            game_over(data.play.w);
        }
    }
    destroy(data.play, w);
}