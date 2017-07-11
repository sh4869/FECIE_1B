#include <stdio.h>
#include <ncurses.h>
#include "highscore.h"

int getHighScore(int highScore,int score){
  return highScore > score ? highScore : score;
}

int loadHighScore(){
  FILE *fp;
  int score;
  fp = fopen("highscore.txt","r");
  if(fp == NULL){
    printf("Error: highscore.txt not Found");
    score =  -1;
  } else {
    fscanf(fp,"%d",&score);
  }
  fclose(fp);
  return score;
}

void saveHighScore(int score){
  FILE *fp;
  fp = fopen("highscore.txt","w");
  if(fp == NULL){
    return;
  }
  fprintf(fp,"%d",score);
  fclose(fp);
  return;
}

void highScoreDisp(int highScore){
  mvprintw(0,COLS/2 + 2,"HIGH SCORE: %D",highScore);
}

