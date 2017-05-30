#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "typing.h"
#define MAXLEN 100

int DataReader(DATA *dataArray, int *n){
  FILE *fp;
  int i = 0;
  fp = fopen("typing.txt","r");
  if(fp == NULL) return -1;
  while(fscanf(fp,"%[^,],%d\n",dataArray[i].string,&dataArray[i].score) != EOF || i > MAXLEN){
    i++;
  }
  *n = i - 1;
  return 0;
}

int typing(DATA *dataArray,int n){
  double diff;
  double remain_time = 20.0;
  time_t starttime = time(NULL),endtime;
  int i=1,number,score = 0;

  char ans[50];
  while(1){
    number = rand()%n;
    printf("%s\n",dataArray[number].string);
    // 計測
    starttime = time(NULL);
    scanf("%s",ans);
    endtime = time(NULL);

    fflush(stdin);

    if(strcmp(dataArray[number].string,ans) == 0){
      printf("Great!\n");
      score += dataArray[number].score;
      remain_time += (double)dataArray[number].score;
    } else {
      printf("Bad...\n");
      remain_time -= dataArray[number].score;
    }
    remain_time -= difftime(endtime,starttime);
    if(remain_time > 0){
      printf("%f second left. Your current score is %d\n",remain_time,score);
    } else {
      printf("TIME UP! Game Over...\n");
      break;
    }
  }
  return score;
}
