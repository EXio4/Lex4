//      game.c
//
//      Copyright 2013 Esteban I. RM <exio4.com@gmail.com>
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

#include "window.h"
#include "media.h"
#include "game.h"
#include "raw_screen.h"

game* alloc_game(const char* name) {
    game* gm=malloc(sizeof(game));
    gm->win=malloc(sizeof(window));
    gm->data=malloc(sizeof(media_data));
    gm->name=strdup(name);
    return gm;
};

void free_game(game* gm) {
    if (gm == NULL) return;
    free(gm->data);
    free(gm->win);
    free(gm->name);
    free(gm);
};

// ----------------------------------

int init_sdl(game *gm) {

    if (gm == NULL) return -1;

    // define default variables in the game.

    gm->state = GM_MENU;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return -1;
    }

    if (TTF_Init() < 0) {
        return -1;
    }

    return 0;
}

void clean_sdl(game *gm) {
    TTF_Quit();
    SDL_Quit();
}

void parse_keypress(game *gm) {
        // nothing for now
}

void got_event(game *gm) {
    if (gm->event.type == SDL_QUIT) {
        gm->state = GM_STOP;
    }
    else if (gm->event.type == SDL_KEYDOWN) {
        parse_keypress(gm);
    }
}

void do_game(game *gm) {
    raw_surface_draw(gm->win->display, gm->data->images[MENU_BACKGROUND], 0, 0);
    if (gm->state == GM_MENU) {
        // show_menu(gm);
        //print_text(gm, 200, 200, 200, 15, 40, "Lex4!");
    }
}

int game_run(char *gm_name) {
    game* gm = alloc_game(gm_name);

    // default values
    gm->win->width = 800;
    gm->win->height = 600;
    gm->win->bbp = 32;
    gm->win->fs = 0;

    if (init_sdl(gm) != 0) {
        ERROR("error starting sdl\n");
    }

    if (init_media(gm) != 0) {
        ERROR("error initializing media structures\n");
    }

    if (load_basic_media(gm) != 0) {
        ERROR("error loading media\n");
    }

    if (init_window(gm) != 0) {
        ERROR("error starting the main window\n");
    }

    while (gm->state != GM_STOP) {
        while(SDL_PollEvent(&(gm->event))) {
            got_event(gm);
        }
        do_game(gm);
        render_window(gm);
    }

    close_window(gm);
    unload_media(gm);
    clean_sdl(gm);
    free_game(gm);

    return 0;
}
