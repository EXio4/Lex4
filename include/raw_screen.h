//      raw_screen.h
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

#ifndef RAW_SCREEN_H
#define RAW_SCREEN_H

#include "sdl_include.h"

SDL_Surface *raw_load_image(char *file);
int raw_surface_draw(SDL_Surface *out, SDL_Surface *in, int x, int y);
int raw_surface_draw_tile(SDL_Surface *out, SDL_Surface *in, int x1, int y1, int x2, int y2, int w1, int h1);
int raw_text_print(SDL_Surface *out, TTF_Font *fnt, int r, int g, int b, int x, int y, char *text);

#endif
