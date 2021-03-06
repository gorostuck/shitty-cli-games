// This file contains the declaration for the window component of the game
#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <ncurses.h>
#include "vec2.h"

int TOTAL_SCREEN_ROWS, TOTAL_SCREEN_COLS;

#define Y_CENTER TOTAL_SCREEN_ROWS/2
#define X_CENTER TOTAL_SCREEN_COLS/2

WINDOW *create_newwin(int height, int width, int starty, int startx);

void destroy_win(WINDOW* local_window);
void print_in_middle(int max_y, int max_x, const char* string);

#endif /* WINDOW_H_INCLUDED */
