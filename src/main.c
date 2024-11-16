#include "game.h"

unsigned char empty_tile[16] = {0};

void performantdelay(UINT8 nloops) {
    for (UINT8 i = 0; i < nloops; i++) {
        wait_vbl_done();
    }
}

void fade_to_white() {
    for(int i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            BGP_REG = 0xF9;
            break;
        case 1:
            BGP_REG = 0xF6;
            break;
        case 2:
            BGP_REG = 0xF3;
            break;
        case 3:
            BGP_REG = 0x00;
            break;
        }
        performantdelay(10);
    }
}

void white_to_new() {
    for(int i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            BGP_REG = 0x00;
            break;
        case 1:
            BGP_REG = 0xF3;
            break;
        case 2:
            BGP_REG = 0xF6;
            break;
        case 3:
            BGP_REG = 0xE4;
            break;
        }
        performantdelay(10);
    }
}

void clear_screen() {
    for (int i = 0; i < 18; i++) {
        printf("\n");
    }
}

void print_menu(int select) {
    clear_screen();
    if (select == 0) {
        printf("> New Game\n");
        printf("  Continue\n");
    } else {
        printf("  New Game\n");
        printf("> Continue\n");
    }
}

void start_menu(int *select, game_t *game) {
    UBYTE key = joypad();
    int prec = *select;

    if (key & J_UP) {
        *select = 0;
    }
    if (key & J_DOWN) {
        *select = 1;
    }
    if (key & J_A) {
        if (*select == 1) {
            game->state = 50;
            printf("Continue\n");
        } else {
            game->state = 2;
            fade_to_white();
            clear_screen();
            white_to_new();
        }
    }
    if (prec != *select)
        print_menu(*select);
}

void main() {
    // Active l'affichage du background
    DISPLAY_ON;
    SHOW_SPRITES;
    SHOW_BKG;

    game_t game = {0, 80, 80};
    int select = 0;

    fill_bkg_rect(0, 0, 20, 18, scene1_TILE_COUNT);

    set_bkg_data(0, scene1_TILE_COUNT, scene1_tiles);
    uint8_t offset_x = (20 - (scene1_WIDTH / 8)) / 2;
    uint8_t offset_y = (18 - (scene1_HEIGHT / 8)) / 2;
    set_bkg_tiles(offset_x, offset_y, scene1_WIDTH / 8, scene1_HEIGHT / 8, scene1_map);

    for (uint16_t i = 0; i < 100; i++)
        wait_vbl_done();
    fade_to_white();
    set_bkg_data(0, logo_TILE_COUNT, logo_tiles);
    for (uint16_t i = 0; i < 33; i++)
        wait_vbl_done();
    white_to_new();

    offset_x = (20 - (logo_WIDTH / 8)) / 2;
    offset_y = (18 - (logo_HEIGHT / 8)) / 2;
    set_bkg_tiles(offset_x, offset_y, logo_WIDTH / 8, logo_HEIGHT / 8, logo_map);

    while (1) {
        if (game.state == 0 && joypad() & J_START) {
            game.state = 1;
            fade_to_white();
            fill_bkg_rect(0, 0, 20, 18, scene1_TILE_COUNT);
            BGP_REG = 0xE4;
            print_menu(0);
        }
        if (game.state == 1)
            start_menu(&select, &game);
        if (game.state == 2)
            break;
        wait_vbl_done();
    }
    if (game.state == 2) {
        fill_bkg_rect(0, 0, 20, 18, scene1_TILE_COUNT);
        set_bkg_data(0, 2, dial_sprite);
        init_eric();
        while (1) {
            chap1(&game);
            wait_vbl_done();
        }
    }
}
