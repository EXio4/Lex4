//      media.c
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

#include "game.h"
#include "raw_screen.h"
#include "media.h"

int init_media(game *gm) {
    int i;
    for (i = 0; i < MEDIA_MAX; i++) {
        gm->data->images[i]=NULL;
        gm->data->fonts[i]=NULL;
    }
    return 0;
}

int load_basic_media(game *gm) {
    if ((gm->data->images[MENU_BACKGROUND] = raw_load_image("menu.png")) == NULL) {
       return -1;
    }

    if ((gm->data->fonts[MENU_FONT] = TTF_OpenFont("menu.ttf", 48)) == NULL) {
        return -1;
    }
    return 0;
}

int unload_media(game *gm) {
    int i;
    for (i = 0; i < MEDIA_MAX; i++) {
        if (gm->data->images[i]) {
            SDL_FreeSurface(gm->data->images[i]);
            gm->data->images[i]=NULL;
        }
        if (gm->data->fonts[i]) {
            TTF_CloseFont(gm->data->fonts[i]);
            gm->data->fonts[i]=NULL;
        }
    }
    return 0;
}
