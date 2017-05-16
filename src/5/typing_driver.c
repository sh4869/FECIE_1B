#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "typing.h"

int main(void){

  srand((unsigned)time(NULL));

  DATA *dataArray=(DATA *)malloc(sizeof(DATA)*MAXLEN);
  int num=0,ret=0,score=0;

  ret=DataReader(dataArray,&num);
  printf("%d sentences were read.\n",num);

  if(ret==0){
    score=typing(dataArray,num);
    printf("You got score:%d\n",score);
  }

  free(dataArray);

}
