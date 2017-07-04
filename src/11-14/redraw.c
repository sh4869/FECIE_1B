#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "redraw.h"

void getMonsterLocation(POSITION *monster){
  int dx,dy;
  dx = rand()%3 - 1;
  dy = rand()%3 - 1;
  if((monster->x > 0 && dx < 0) || (monster->x < COLS - 1 && dx > 0)){
    monster->x += dx;
  }
  if((monster->y > 0 && dy < 0) || (monster->y < COLS - 1 && dy > 0)){
    monster->y += dy;
  }
}

void redraw(){
  POSITION *monster = (POSITION *)malloc(sizeof(POSITION));
  char ch;
  // Initialize
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  timeout(100);
  srand((unsigned)time(NULL));
  monster->x = COLS/2;
  monster->y = LINES/2;
  
  while(ch != 'q'){
    mvprintw(monster->y,monster->x," ");
    getMonsterLocation(monster);
    mvprintw(monster->y,monster->x,"M");
    ch = getch();
    refresh();
  }
  endwin();
  free(monster);
  return;
}
