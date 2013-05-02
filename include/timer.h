//      timer.h
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

typedef struct timer {
    int start_ticks;
    int paused_ticks;
    int paused, started;
} timer;

timer* init_timer();
void timer_start(timer* tm);
void timer_stop(timer* tm);
int timer_get_ticks(timer* tm);
void timer_pause(timer *tm);
void timer_unpause(timer *tm);
