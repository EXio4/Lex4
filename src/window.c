//      window.c
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

int init_window(game* gm) {

    int flags = 0;
    if (gm->win->fs) {
        flags = SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN;
    } else {
        flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    }

    if((gm->win->display = SDL_SetVideoMode(gm->win->width, gm->win->height, gm->win->bbp, flags)) == NULL) {
        return -1;
    }

    SDL_WM_SetCaption(gm->name, NULL);

    // fill screen with black
    SDL_FillRect(gm->win->display, &(gm->win->display->clip_rect), SDL_MapRGB(gm->win->display->format, 0x0, 0x0, 0x0));

    return 0;
}

void render_window(game *gm) {
    SDL_Flip(gm->win->display);
}

void close_window(game *gm) {
    SDL_FreeSurface(gm->win->display);
    gm->win->display = NULL;
}
