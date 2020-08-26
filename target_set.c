/*
** EPITECH PROJECT, 2019
** target_set
** File description:
** Set the targetsposition
*/

#include "include/my.h"
#include <stdlib.h>
#include <time.h>

sfVector2f target_set(sfVector2f Target_pos, sfVector2i position)
{
    Target_pos.x = position.x - 89;
    Target_pos.y = position.y - 89;
    return Target_pos;
}

struct stats set_stats(struct stats data)
{
    data.life = 3;
    data.level = 1;
    data.points = 0;
    data.speed = 0.5;
    return data;
}

struct stats sho(struct game p, struct enemy g, sfVector2i pos, struct stats d)
{
    sfVector2f Boo;
    sfEvent event;

    srand (time(NULL));
    Boo = (sfVector2f){.x = -178, .y = rand() % 880};
    if ((g.boo_pos.x <= pos.x && pos.x <= g.boo_pos.x + 178) &&
    (pos.y >= g.boo_pos.y && pos.y <= g.boo_pos.y + 178)) {
        sfSprite_setPosition(p.Quit, Boo);
        d.points += 50;
        if (d.points % 500 == 0 && d.points != 0) {
            d.speed += 0.1;
            d.level += 1;
        }
    }
    return d;
}

struct game t(struct stats d, struct game play, sfVector2f left, sfVector2f T)
{
    float tiempo = sfTime_asSeconds(play.passed);
    int a = 0;

    if (tiempo >= 1) {
        sfClock_restart (play.Temps);
        a = d.play.rect.left + 178;
        d.play.rect.left = (d.play.rect.left < 356) ? a : 0;
        sfSprite_setTextureRect(play.Quit, d.play.rect);
    }
    sfSprite_setPosition(play.Target, T);
    sfRenderWindow_display(play.w);
    sfSprite_move(play.Quit, left);
    sfRenderWindow_drawSprite(play.w, play.sprite, NULL);
    sfRenderWindow_drawSprite(play.w, play.Quit, NULL);
    sfRenderWindow_drawSprite(play.w, play.Target, NULL);
    return d.play;
}

void interface(struct stats data)
{
    
}