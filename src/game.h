/*
** EPITECH PROJECT, 2024
** game
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <gb/gb.h>
    #include "scene1.h"
    #include "logo.h"
    #include "dial.h"
    #include "eric.h"
    #include <stdio.h>


typedef struct game_s {
    int state;
    int x;
    int y;
} game_t;

void fade_to_white();
void performantdelay(UINT8 nloops);
void white_to_new();
void start_menu(int *select, game_t *game);
int chap1(game_t *game);

#endif /* !GAME_H_ */
