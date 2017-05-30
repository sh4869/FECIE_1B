#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#define N 100

void clean_stdio(){
  int ch;
  do {
    ch = getchar();
  } while(ch != '\n' && ch != EOF );
}

void menu(){
  DATA *dataArray = (DATA *)malloc(sizeof(DATA)*N);
  int n,success,ret = 1;
  char ch;
  while(ret==1){
    printf("---menu---\nq: Quiz\nt: Typing\ne: Exit\n>");
    ch = getchar();
    switch(ch){
      case 'q':
        input();
        break;
      case 't':
        success = DataReader(dataArray,&n);
        if(!success) typing(dataArray,n);
        break;
      case 'e':
        ret = 0;
        break;
      case '\n':
        break;
      default:
        printf("invalid command\n");
        clean_stdio();
        break;
    }
  }
  free(dataArray);
}

