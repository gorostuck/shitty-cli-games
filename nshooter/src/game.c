// This file contains the definition for the main game's process
#include "game.h"

#include <string.h>

#include "defines.h"
#include "vec2.h"
#include "window.h"
#include "main_screen.h"
#include "tutorial_screen.h"
#include "ammo.h"
#include "gameplay.h"
#include "enemy.h"

int game_start()
{
  init();
  while (game_loop());
  destroy_windows();
  endwin();
  return 0;
}

int game_loop()
{
  if (read_input(getch())==0) return 0;
  render_ammo();
  refresh();
  return 1;
}


void init()
{
  init_ncurses();
  init_screens();
  move(Y_CENTER, X_CENTER);
  print_in_tutorial(S_WELCOME);

#ifdef DEBUG_MODE
  print_debug_stuff();
#endif /* DEBUG_MODE */
}

void init_ncurses()
{
  initscr();
  cbreak();
  nodelay(stdscr, TRUE);
  noecho();
}

void init_screens()
{
  getmaxyx(stdscr, TOTAL_SCREEN_ROWS, TOTAL_SCREEN_COLS);
  box(stdscr, 0,0);
  move(0,0);
  getch();
  init_main_screen(TOTAL_SCREEN_ROWS, TOTAL_SCREEN_COLS);
  init_ammo();
  init_tutorial_screen();
}

void destroy_windows()
{
  destroy_win(main_screen);
  destroy_win(tutorial_screen);
  destroy_win(ammo_screen);
}

int read_input(int KEY)
{
  switch (KEY){
  case KEY_MOVE_UP:
  case KEY_MOVE_RIGHT:
  case KEY_MOVE_DOWN:
  case KEY_MOVE_LEFT:
    move_cursor(KEY);
    break;
  case KEY_SHOOT:
    if (shoot(cursor_vec2())==SHOOT_ENEMY);
    break;
  case KEY_RELOAD:
    reload_ammo();
    break;
  case KEY_TUTORIAL:
    print_in_tutorial(S_TUTORIAL);
    break;
  case KEY_CLEAN:
    clean_tutorial();
    break;
  case KEY_ESCAPE:
    print_score();
    return 0;
  }
  return 1;
}

void print_score()
{
  int score_screen_starting_y = (TOTAL_SCREEN_ROWS-SCORE_SCREEN_ROWS)/2;
  int score_screen_starting_x = (TOTAL_SCREEN_COLS-SCORE_SCREEN_COLS)/2;

  WINDOW* score_window = create_newwin(SCORE_SCREEN_ROWS, SCORE_SCREEN_COLS, score_screen_starting_y, score_screen_starting_x);

  mvprintw(TOTAL_SCREEN_COLS/2, (TOTAL_SCREEN_ROWS-strlen("Score: XX"))/2, "Score: %n", 10);

  getch();

  destroy_win(score_window);
}

#ifdef DEBUG_MODE
void print_debug_stuff()
{
  move(1,1);
  printw("TOTAL_SCREEN_ROWS: %d", TOTAL_SCREEN_ROWS);
  move(2,1);
  printw("TOTAL_SCREEN_COLS: %d", TOTAL_SCREEN_COLS);
  move(3,1);
  printw("MAIN_SCREEN_ROWS: %d", MAIN_SCREEN_ROWS);
  move(4,1);
  printw("MAIN_SCREEN_COLS: %d", MAIN_SCREEN_COLS);
  move(5,1);
  printw("AMMO_SCREEN_ROWS: %d", AMMO_SCREEN_ROWS);
  move(6,1);
  printw("AMMO_SCREEN_COLS: %d", AMMO_SCREEN_COLS);
  move(7,1);
  printw("TUTORIAL_SCREEN_ROWS: %d", TUTORIAL_SCREEN_ROWS);
  move(8,1);
  printw("TUTORIAL_SCREEN_COLS: %d", TUTORIAL_SCREEN_COLS);
}
#endif /* DEBUG_MODE */
