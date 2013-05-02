//      entity.h
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

#include "media_defs.h"

typedef struct entity_data {
    int w, h;

    int idle_anim_start;
    int idle_anim_end;

    // walking to the the right
    int walk_anim_start;
    int walk_anim_stop;

    // running to the right
    int run_anim_start;
    int run_anim_stop;

    int surfaces_ids[MEDIA_MAX]; // the max surfaces loaded *per* entity is the same as the max number of general surfaces
    //
} entity_data;

typedef struct entity {
    int type;
    int flags;
    int status;
    float x, y;
    float xvel, yvel;
    entity_data* data;
} entity;

#declare ENT_T_PLAYER       0x01
#declare ENT_T_PARTICLE     0x02
#declare ENT_T_LUAENTITY    0x04

#declare ENT_F_PHYSICAL 0x01
#declare ENT_F_DEAD     0x02
