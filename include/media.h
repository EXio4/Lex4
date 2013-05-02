//      media.h
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

#ifndef MEDIA_H
#define MEDIA_H

#include "sdl_include.h"
#include "media_defs.h"
#include "game.h"

typedef struct media_data {
    SDL_Surface*    images[MEDIA_MAX];
    TTF_Font*       fonts[MEDIA_MAX];
} media_data;

int init_media(game *gm);
int load_basic_media(game *gm);
int unload_media(game *gm);


#endif