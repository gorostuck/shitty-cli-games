// This file contains the definitions for the main screen
#ifndef MAIN_SCREEN_H_INCLUDED
#define MAIN_SCREEN_H_INCLUDED

#include "window.h"
#include "vec2.h"
#include "defines.h"

WINDOW* main_screen;
int main_screen_starting_y, main_screen_starting_x;

void init_main_screen();
int check_border(int border, vec2 pos);
int check_all_borders(vec2 pos);


#endif /* MAIN_SCREEN_H_INCLUDED */
