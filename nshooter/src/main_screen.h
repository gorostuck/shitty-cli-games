// This file contains the definitions for the main screen
#ifndef MAIN_SCREEN_H_INCLUDED
#define MAIN_SCREEN_H_INCLUDED

#include "window.h"
#include "vec2.h"

WINDOW* main_screen;

void init_main_screen(int ROWS, int COLS);
int check_border(int border, vec2 cursor_pos);

#endif /* MAIN_SCREEN_H_INCLUDED */
