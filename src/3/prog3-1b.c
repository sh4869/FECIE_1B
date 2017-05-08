#include <stdio.h>

int main(void){
  FILE *fp;
  char line[1000];
  int i = 1;
  fp = fopen("./prog2-1a.c","r");
  if(fp == NULL){
    printf("ファイルがひらけませんでした\n");
    return -1;
  }
  while(fgets(line,sizeof(line),fp)!=NULL){
    printf("%d: %s",i,line);
    i++;
  }
  fclose(fp);
  return 0;
}
