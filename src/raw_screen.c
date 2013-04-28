//      raw_screen.c
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

#include "raw_screen.h"

SDL_Surface *raw_load_image(char *file) {
    SDL_Surface* tmp = NULL;
//    SDL_Surface* tmp_r = NULL;

    if((tmp = IMG_Load(file)) == NULL) {
        return NULL;
    }

//    tmp_r = SDL_DisplayFormat(tmp);
//    SDL_FreeSurface(tmp);

    return tmp;
}


int raw_surface_draw(SDL_Surface *out, SDL_Surface *in, int x, int y) {
    if(out == NULL || in == NULL) {
        return -1;
    }

    SDL_Rect outr;

    outr.x = x;
    outr.y = y;

    SDL_BlitSurface(in, NULL, out, &outr);

    return 0;
}

int raw_surface_draw_tile(SDL_Surface *out, SDL_Surface *in, int x1, int y1, int x2, int y2, int w1, int h1) {
    if(out == NULL || in == NULL) {
        return -1;
    }

    SDL_Rect outr, inr;
    outr.x = x1;
    outr.y = y1;

    inr.x = x2;
    inr.y = y2;
    inr.w = w1;
    inr.h = h1;

    SDL_BlitSurface(in, &inr, out, &outr);

    return 0;
}

int raw_text_print(SDL_Surface *out, TTF_Font *fnt, int r, int g, int b, int x, int y, char *text) {
    SDL_Color color = { r, g, b };
    SDL_Surface* message = TTF_RenderText_Solid(fnt, text, color);
    int res = raw_surface_draw(out, message, x, y);
    SDL_FreeSurface(message);
    return res;
}
