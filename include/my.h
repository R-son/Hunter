/*
** EPITECH PROJECT, 2019
** my
** File description:
** Contains prototypes
*/

#include <SFML/Audio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include "ressources.h"
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Network.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
void title(void);
void game_over(sfRenderWindow *w);
void launch(sfRenderWindow *w);
void destroy(struct game title, sfRenderWindow *w);
sfVector2f target_set(sfVector2f Target_pos, sfVector2i position);
struct stats set_stats(struct stats data);
struct stats sho(struct game p, struct enemy g, sfVector2i pos, struct stats d);
struct game t(struct stats d, struct game play, sfVector2f left, sfVector2f T);
