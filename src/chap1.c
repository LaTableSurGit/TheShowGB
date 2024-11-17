#include "game.h"

void moove_sprite_eric(int x, int y)
{
    move_sprite(0, x, y);
    move_sprite(1, x, y + 8);
    move_sprite(2, x, y + 16);
    move_sprite(3, x, y + 24);
    move_sprite(4, x + 8, y);
    move_sprite(5, x + 8, y + 8);
    move_sprite(6, x + 8, y + 16);
    move_sprite(7, x + 8, y + 24);
    move_sprite(8, x + 16, y + 16);
}

void init_eric(void)
{
    set_sprite_data(0, 20, Eric);
    set_sprite_tile(0, 2);
    set_sprite_tile(1, 3);
    set_sprite_tile(2, 6);
    set_sprite_tile(3, 7);
    set_sprite_tile(4, 8);
    set_sprite_tile(5, 9);
    set_sprite_tile(6, 12);
    set_sprite_tile(7, 13);
    set_sprite_tile(8, 14);
    moove_sprite_eric(80, 24);
}

int chap1(game_t *game)
{
    set_bkg_tiles(0, 75, box_diagWidth, box_diagHeight, box_diag);
    wait_vbl_done();
    printf("Ah, il est enfin l'heure de mon emission preferee !\n");
    waitpad(J_A);
    
    // mettre Sammy
    printf("Je suis sammy\n");
    return 0;
}