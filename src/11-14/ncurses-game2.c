#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "redraw2.h"
int main(int argc, char **argv)
{
  /* declaration of variables */
  POSITION *player = (POSITION *)malloc(sizeof(POSITION));
  POSITION *monster = (POSITION *)malloc(sizeof(POSITION));
  POSITION *treasure = (POSITION *)malloc(sizeof(POSITION));
  int cnt = 0;
  int ch;
  int i;
  int stage = 0;
  int score = 0;
  int numTreasure;
  int clear = 0;
  /* initialization of rand function */
  srand((unsigned)time(NULL));
  /* initialization of ncurses */
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, true);
  wtimeout(stdscr, 500);
  /* initialization of variables */
  player->x = 5;
  player->y = 5;
  monster->x = COLS / 2;
  monster->y = LINES / 2;
  treasure->x = -1;
  treasure->y = -1;
  numTreasure = 0;
  /* First, let’s read key. */
  ch = getch();
  while (ch !='q'){
    mvprintw(1, 2, "stage : %d", (stage + 1));
    mvprintw(2, 2, "score : %d", score);
    mvprintw(3, 2, "count : %3d", MAX_COUNT - cnt);
    cnt++;
    /* move monster */
    mvprintw(monster->y, monster->x, " ");
    getMonsterLocation(monster, treasure, &numTreasure);
    mvprintw(monster->y, monster->x, "M");
    /* move player */
    mvprintw(player->y, player->x, " ");
    getPlayerLocation(player, ch);
    mvprintw(player->y, player->x, "@");
    refresh();
    /* judgement */
    clear += getTreasure(player, treasure, &numTreasure);
    if (cnt == MAX_COUNT)
    {
      /* could not get treasures */
      ch = gameOver();
    }
    else if (encounter(player, monster))
    {
      /* caught by monster */
      ch = gameOver();
    }
    else if (clear == stage + 1)
    {
      /* stage clear */
      mvprintw(4, 2, "Gotcha!");
      refresh();
      sleep(2);
      mvprintw(4, 2, " ");
      stage++;
      score += MAX_COUNT - cnt;
      cnt = 0;
      clear = 0;
      initPlayerLocation(player);
      initMonsterLocation(monster);
      initTreasureLocation(treasure, &numTreasure);
    }
    else
    {
      ch = getch();
    }
  }
  endwin();
  return 0;
}
