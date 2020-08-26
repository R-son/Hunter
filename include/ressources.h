/*
** EPITECH PROJECT, 2019
** ressources
** File description:
** Contains Structures for ressources
*/



#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Export.h>

#ifndef RES_H_
#define RES_H_

struct game
{
    sfRenderWindow *w;
    sfTexture *t;
    sfTexture *t2;
    sfTexture *t3;
    sfTexture *aim;
    sfSprite *sprite;
    sfSprite *Target;
    sfMusic *music;
    sfEvent *event;
    sfIntRect rect;
    sfIntRect rect2;
    sfSprite *Quit;
    sfSprite *Start;
    sfClock *Temps;
    sfTime passed;
};

struct enemy
{
    sfTexture *ghost;
    sfSprite *boo;
    sfVector2f boo_pos;
    float boo_x;
    float boo_y;
};

struct shot
{
    sfVector2i position;
};

struct stats
{
    int life;
    int level;
    int points;
    double speed;
    sfFont *font1;
    sfText *score;
    sfFont *font2;
    sfText *lvl;
    sfFont *font3;
    sfText *health;
    struct game play;
};

#endif /*RES_H_*/
