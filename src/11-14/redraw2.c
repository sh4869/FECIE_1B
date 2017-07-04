#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "redraw2.h"

int isEqual(POSITION *a,POSITION *b){
  return a->x == b->x && a->y == b->y;
}

void initPlayerLocation(POSITION *player){
  mvprintw(player->y,player->x," ");
  player->y = player->x = 5;
  mvprintw(player->y,player->x,"@");
}

void getPlayerLocation(POSITION *player, int key){
  switch(key){
    case KEY_LEFT:
      player->x = player->x > 0 ? player->x - 1 : player->x;
      break;
    case KEY_RIGHT:
      player->x = player->x < COLS - 1 ? player->x + 1 : player->x;
      break;
    case KEY_UP:
      player->y = player->y > 0 ? player->y - 1  : player->y;
      break;
    case KEY_DOWN:
      player->y = player->y < LINES - 1 ? player->y + 1 : player->y;
      break;
  }
}

void getMonsterLocation(POSITION *monster,POSITION *treasure,int *numTreasure){
  int dx,dy,origX,origY,dice;
  dx = rand()%3 - 1;
  dy = rand()%3 - 1;
  origX = monster->x;
  origY = monster->y;
  dice = rand() % 10;
  if((monster->x > 0 && dx < 0) || (monster->x < COLS - 1 && dx > 0)){
    monster->x += dx;
  }
  if((monster->y > 0 && dy < 0) || (monster->y < COLS - 1 && dy > 0)){
    monster->y += dy;
  }
  if(*numTreasure == 1 && isEqual(monster,treasure)){
    monster->x = origX;
    monster->y = origY;
  } else if(dice == 0 && *numTreasure == 0 && (monster->x != origX || monster->y != origY)){
    treasure->x = origX;
    treasure->y = origY;
    *numTreasure = 1;
    mvprintw(treasure->y,treasure->x,"T");
  }
}

int getTreasure(POSITION *player,POSITION *treasure, int *numTreasure){
  if(*numTreasure == 1 && isEqual(player,treasure)){
    mvprintw(treasure->y,treasure->x," ");
    *numTreasure = 0;
    return 1;
  }
  return 0;
}

int encounter(POSITION *player,POSITION *monster){
  return isEqual(player,monster);
}

void initMonsterLocation(POSITION *monster){
  mvprintw(monster->y,monster->x," ");
  monster->x = COLS / 2;
  monster->y = LINES / 2;
  mvprintw(monster->y,monster->x,"@");
}

void initTreasureLocation(POSITION *treasure,int *numTreasure){
  mvprintw(treasure->y,treasure->x," ");
  *numTreasure = 0;
}

char gameOver(){
  mvprintw(LINES / 2,COLS / 2 - 4,"GAME OVER");
  refresh();
  sleep(2);
  return 'q';
}

