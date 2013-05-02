//      timer.c
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

#include "sdl_include.h"
#include "timer.h"

timer* init_timer() {
    timer* tm=malloc(sizeof(timer));
    tm->start_ticks = 0;
    tm->paused_ticks = 0;
    tm->paused = 0;
    tm->started = 0;
    return tm;
}

void timer_start(timer* tm) {
    tm->started = 1;
    tm->paused = 0;
    tm->start_ticks = SDL_GetTicks();
}

void timer_stop(timer* tm) {
    tm->started = 0;
    tm->paused = 0;
}

int timer_get_ticks(timer* tm) {
    if (tm->started == 1) {
        if (tm->paused == 1) {
            return tm->paused_ticks;
        } else {
            return SDL_GetTicks() - tm->start_ticks;
        }
    }
    return 0;
}

void timer_pause(timer *tm) {
    if ( (tm->started == 1) && (tm->paused == 0) ) {
        tm->paused = 1;
        tm->paused_ticks = SDL_GetTicks() - tm->start_ticks;
    }
}

void timer_unpause(timer *tm) {
    if (tm->paused == 1) {
        tm->paused = 0;
        tm->start_ticks = SDL_GetTicks() - tm->paused_ticks;
        tm->paused_ticks = 0;
    }
}
